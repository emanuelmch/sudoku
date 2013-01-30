#pragma once 

#include <string>

namespace Bill {
namespace Sudoku {

	class Board {
	public:
		int get(const int x, const int y) const;
		void set(const int x, const int y, const int value);

		void readString(const std::string);
		void clear();

		bool isFilled();

		Board();
		~Board();
	private:
		int values[9][9];
	};

}
}

