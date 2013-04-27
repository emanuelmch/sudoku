#pragma once

#include <string>

namespace Bill {
	namespace Sudoku {

		class Board {
		public:
			static const int GRID_SIZE = 9;
			static const int MINI_GRID_SIZE = GRID_SIZE / 3;
			static const int CELL_AMOUNT = GRID_SIZE * GRID_SIZE;

			Board();
			~Board();

			int get(const int x, const int y) const;
			void set(const int x, const int y, const int value);

			int count() const;
			void clear();

			bool isFilled() const;
			bool validate() const;

			void read(const std::string);
			void read(const Board*);

		private:
			int values[9][9];
		};

	}
}

