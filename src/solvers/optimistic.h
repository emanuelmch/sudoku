#include "solver.h"

namespace Bill {
namespace Sudoku {

	class OptimisticSolver : public Solver {
	public:
		OptimisticSolver();
		~OptimisticSolver();

		bool solve(Board *);
		void registerCallback(SolverCallback);
	private:
		SolverCallback callback;
	};

}
}
