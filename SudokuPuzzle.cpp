#include "SudokuPuzzle.h"
#include <iostream>
using namespace std ;

SudokuPuzzle::SudokuPuzzle() {

	// Set to true to turn on tracers
	debug = false;

	// Initialize board
	for (int y=0; y<9; y++) {
		for (int x=0; x<9; x++) {
			board[x][y] = 0;
		}
	}
	
} 
void SudokuPuzzle::print() {
	// For each row
	for (int y=0; y<9; y++) {
	    // Draw horizontal lines between blocks
	    if (y % 3== 0) {
			cout << "-------------------------------" << endl;
		}
		
		// For each cell in row
		for (int x=0; x<9; x++) {
			if (x % 3 == 0) {
				cout << "|";
			}
		
		    if (board[x][y] != 0) {
				cout << " " << board[x][y] << " ";
			} else {
				cout << " . ";
			}
			
		}
		
		// Draw columns between blocks
		cout << "|" << endl;
	}
	cout << "-------------------------------" << endl;
	
} 
void SudokuPuzzle::setBoardValue(int x_cord, int y_cord, int value) {
  board[x_cord][y_cord] = value;
} 
bool SudokuPuzzle::solve() {
  return solve(0,0);
} // SudokuPuzzle::solve()

int SudokuPuzzle::getBoardValue(int x_cord, int y_cord) {
	return board[x_cord][y_cord];
} 
bool SudokuPuzzle::solve(int x_cord, int y_cord) {

  // Only solve piece if not already solved (given)
  if (board[x_cord][y_cord] != 0) {
  
    // If value works, on to next
    if (verifyValue(x_cord,y_cord)) {
	
		// If last piece, puzzle solved!
		if (x_cord == 8 && y_cord == 8) {
			return true;
		}
	
	    // Find next slot on this row
		int next_x = x_cord+1;
		int next_y = y_cord;
		
		// If at end of row, start next
		if (next_x >= 9) {
			next_x = 0;
			next_y++;
		}
		
		// Move on to next piece
		return solve(next_x, next_y);
	} 
	
	// Value doesn't work. Early guess is bad
	else {
		return false;
	}
	
  }
  for (int val=1; val<10; val++) {
	
	setBoardValue(x_cord, y_cord, val);
	
	// If value works, on to next
    if (verifyValue(x_cord,y_cord)) {
	
		// If last piece, puzzle solved!
		if (x_cord == 8 && y_cord == 8) {
			return true;
		}
	
		// Find next slot on this row
		int next_x = x_cord+1;
		int next_y = y_cord;
		
		// If at end of row, start next
		if (next_x >= 9) {
			next_x = 0;
			next_y++;
		}
		
		// Move on to next piece
		//return solve(next_x, next_y);
		if (solve(next_x, next_y)) {
		  return true;
		}
	}
  }
  
  
  board[x_cord][y_cord] = 0;
  
  // If gets here, must backtrack. No solution
  // for path.
  return false;
  
} // SudokuPuzzle::solve(int, int)


bool SudokuPuzzle::verifyValue(int x_cord, int y_cord) {

  printTracerTryingValue(x_cord, y_cord);

  int value = board[x_cord][y_cord];

  // Make sure no vertical collision
  for (int x_verify=0; x_verify<9; x_verify++) {
    // Skip self.
    if (x_verify == x_cord) {
	  continue;
	}
	
	// If same value, failed
	int verifyValue = board[x_verify][y_cord];
	if (verifyValue == value) {
	  return false;
	}
  }
  
  // Make sure no horizontal collision
  for (int y_verify=0; y_verify<9; y_verify++) {
    // Skip self.
    if (y_verify == y_cord) {
	  continue;
	}
	
	// If same value, failed
	int verifyValue = board[x_cord][y_verify];
	if (verifyValue == value) {
	  return false;
	}
  }
  
  // Make sure no collision in box
  int box_x = x_cord / 3; // If this box 0, 1, 2 on x-cord
  int box_y = y_cord / 3; // Is this box 0, 1, 2 on y-cord
  
  // For each y in the same box
  for (int y_verify=box_y * 3; y_verify < box_y * 3 + 3; y_verify++) {
	// For each x in the same box
	for (int x_verify=box_x * 3; x_verify < box_x * 3 + 3; x_verify++) {
		// Skip self.
		if (x_verify == x_cord && y_verify == y_cord) {
			continue;
		}
		
		// If same value, failed
		int verifyValue = board[x_verify][y_verify];
		if (verifyValue == value) {
			return false;
		}
	}
  }
  
  // Passed all of the tests, so valid
  return true;
  
} /
void SudokuPuzzle::printTracerTryingValue(int x_cord, int y_cord) {
  if (debug) {
    // Indent for easier reading
	for (int i=0; i<x_cord+y_cord; i++) {
	  cout << " ";
	}
	
	cout << "Trying value " << board[x_cord][y_cord] << " at board[" << x_cord << "][" << y_cord << "]" << endl;
  }
  
} 
