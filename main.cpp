#include <iostream>
#include "SudokuPuzzle.h"
using namespace std ;

int main (int argc, char * const argv[]) {
    
	SudokuPuzzle puzzle;
	
	// Setting known values on board block 1
	puzzle.setBoardValue(0,0,1);
	puzzle.setBoardValue(1,1,3);
	puzzle.setBoardValue(2,2,9);
	
	// block 2
	puzzle.setBoardValue(3,2,6);
	puzzle.setBoardValue(4,1,2);
	puzzle.setBoardValue(5,0,7);
	
	// block 3
	puzzle.setBoardValue(6,2,5);
	puzzle.setBoardValue(7,0,9);
	puzzle.setBoardValue(8,1,8);
	
	// block 4
	puzzle.setBoardValue(0,5,6);
	puzzle.setBoardValue(1,4,1);
	puzzle.setBoardValue(2,3,5);
	
	// block 5
	puzzle.setBoardValue(3,3,3);
	puzzle.setBoardValue(4,4,8);
	puzzle.setBoardValue(5,5,4);
	
	// block 6
	puzzle.setBoardValue(6,3,9);
	puzzle.setBoardValue(8,4,2);
	
	// block 7
	puzzle.setBoardValue(0,6,3);
	puzzle.setBoardValue(1,7,4);
	puzzle.setBoardValue(2,8,7);
	
	// block 9
	puzzle.setBoardValue(6,8,3);
	puzzle.setBoardValue(7,6,1);
	puzzle.setBoardValue(8,7,7);
	
	// Printing 
	puzzle.print();
	
	cout << endl;
	
	// Now solve. If not solvable, say.
	if (puzzle.solve()) 
  {
	  cout << "Here is the solution:" << endl;
	  puzzle.print();
	} 

  else 
  {
	  cout << "Puzzle is not solvable.";
	}
	
	cout << endl;
	
  return 0;
	
} 
