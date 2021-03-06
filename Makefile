
CXX := g++

SRC_DIR := ./src
TSS_DIR := ./tests
BUILD_DIR := ./build
DBG_DIR := $(BUILD_DIR)/debug
REL_DIR := $(BUILD_DIR)/release
TST_DIR := $(BUILD_DIR)/test

FLAGS := -std=c++11 -Wall -Wextra -Wfloat-equal -Wundef -Wunreachable-code -Wswitch-enum -ansi -pedantic
FLAGS_DEBUG := -march=corei7-avx -mtune=corei7-avx -O0 -g
FLAGS_RELEASE := -march=corei7-avx -mtune=corei7-avx -O3 -Werror
LIBS :=
TEST_LIBS := -lcppunit

SRCS := $(shell find $(SRC_DIR) -type f -name \*.cpp)
DBG_OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(DBG_DIR)/%.o, $(SRCS))
DBG_DEPS := $(patsubst $(SRC_DIR)/%.cpp, $(DBG_DIR)/%.d, $(SRCS))
REL_OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(REL_DIR)/%.o, $(SRCS))
REL_DEPS := $(patsubst $(SRC_DIR)/%.cpp, $(REL_DIR)/%.d, $(SRCS))

TESTS := $(shell find $(TSS_DIR) -type f -name \*.cpp)
TST_OBJS := $(patsubst $(TSS_DIR)/%.cpp, $(TST_DIR)/%.o, $(TESTS))

all: release test

#
# RUNNER TARGETS
#
gdb: debug
	gdb ./debug

valgrind: debug
	valgrind --log-file=val.log --leak-check=full ./debug

check: test
	./test

run: release
	./release

#
# FINAL BINARY TARGETS
#
debug: $(DBG_OBJS)
	$(CXX) -o $@ $^ $(LIBS)

release: $(REL_OBJS)
	$(CXX) -o $@ $^ $(LIBS)

test: $(TST_OBJS) $(subst $(REL_DIR)/main.o,,$(REL_OBJS))
	$(CXX) -o $@ $^ $(LIBS) $(TEST_LIBS)

#
# DEPENDENCIES TARGETS
#
$(DBG_DIR)/%.d: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) -E -M -MM -MF $@ $<
# Gambiarras...
	@mv $@ $@.tmp
	@echo -n "$(DBG_DIR)/" > $@
	@cat $@.tmp >> $@
	@rm $@.tmp

$(REL_DIR)/%.d: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) -E -M -MM -MF $@ $<
# Gambiarras...
	@mv $@ $@.tmp
	@echo -n "$(@D)/" > $@
	@cat $@.tmp >> $@
	@rm $@.tmp

$(DBG_DIR)/%.o: $(DBG_DIR)/%.d

$(REL_DIR)/%.o: $(REL_DIR)/%.d

#
# OBJECT TARGETS
#
$(DBG_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(FLAGS) $(INCLUDES) $(FLAGS_DEBUG) -c -o $@ $<

$(REL_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(FLAGS) $(INCLUDES) $(FLAGS_RELEASE) -c -o $@ $<

$(TST_DIR)/%.o: $(TSS_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(FLAGS) $(INCLUDES) $(FLAGS_RELEASE) -c -o $@ $<

#
# OTHER TARGETS
#
clean:
	rm -rf $(BUILD_DIR) release{,.exe} debug{,.exe} test{,.exe}

.PHONY: clean

# Code dependencies are not necessary for these these targets
NODEPS := clean todo

ifeq (0, $(words $(findstring $(MAKECMDGOALS), $(NODEPS))))
-include $(DBG_DEPS)
-include $(REL_DEPS)
endif
