#pragma once 

#include <string>

namespace Bill {
namespace Sudoku {

	class Board {
	public:
		static const int CELL_AMOUNT = 9 * 9;

		int get(const int x, const int y) const;
		void set(const int x, const int y, const int value);

		int usedCells() const;
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

