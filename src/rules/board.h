#include <string>

namespace Bill {
namespace Sudoku {

	class Board {
	public:
		int get(int x, int y);
		int set(int x, int y, int value);

		void readString(const std::string);
		void clear();

		Board();
		~Board();
	private:
		int values[9][9];
	};

}
}

