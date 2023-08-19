#ifndef _SUDOKU_PUZZLE_H
#define _SUDOKU_PUZZLE_H

class SudokuPuzzle {
  private:
	// data members
  	short int board[9][9];
  	bool debug;

	// member functions
  	void printTracerTryingValue(int cord_x, int cord_y);
  	bool solve(int cord_x, int cord_y);
  	bool verifyValue(int cord_x, int cord_y);

  public:
    	// Constructor
	SudokuPuzzle();
  
   void print();
	
	  void setBoardValue(int cord_x, int cord_y, int value);
  
	  int getBoardValue(int cord_x, int cord_y);
	  bool solve();
};

#endif
