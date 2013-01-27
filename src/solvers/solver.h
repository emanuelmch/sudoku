#include "../rules/board.h"

namespace Bill {
namespace Sudoku {

	typedef void (*SolverCallback)(Board *);

	class Solver {
	public:
		virtual bool solve(Board *) = 0;
		virtual void registerCallback(SolverCallback) = 0;
	};

}
}
