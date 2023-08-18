if [ -f sudoku-solver ]; then
  rm sudoku-solver
fi

# Build using GCC C++ compiler, then run
g++ -Wall main.cpp SudokuPuzzle.cpp -o sudoku-solver
