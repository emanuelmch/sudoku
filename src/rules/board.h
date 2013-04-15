#pragma once 

#include <string>

namespace Bill {
namespace Sudoku {

	class Board {
	public:
		static const int GRID_SIZE = 9;
		static const int MINI_GRID_SIZE = GRID_SIZE / 3;
		static const int CELL_AMOUNT = GRID_SIZE * GRID_SIZE;

		int get(const int x, const int y) const;
		void set(const int x, const int y, const int value);

		int usedCells() const;
		void clear();

		bool isFilled();
		bool validate();

		void read(const std::string);
		void copy(const Board*);

		Board();
		~Board();
	private:
		int values[9][9];
	};

}
}

