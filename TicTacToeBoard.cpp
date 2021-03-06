#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
  if (turn == X) {
    turn = O;
    return O;
  } else {
    turn = X;
    return X;
  }
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
  if(getWinner() == Invalid) {
    if(getPiece(row,column) != Invalid) {
      if(getPiece(row,column) != Blank) {
        return getPiece(row,column);
      } else {
        board[row][column] = turn;
        Piece placedPiece = turn;
        turn = toggleTurn();
        return placedPiece;
      }
    }
    else {
      return Invalid;
    }
  }
  return Invalid;
}
/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/

/* 
BUG: When the column for getpiece is equal to the size of the board, it should return invalid.
ACTUAL: Accepts it if the column is equal to the boardsize and gets a piece out of bounds
*/

Piece TicTacToeBoard::getPiece(int row, int column)
{
  if((row < BOARDSIZE && row >= 0) && (column < BOARDSIZE && column >= 0)) {
    if(board[row][column] == Blank) {
      return Blank;
    } else if (board[row][column] == O){
      return O;
    } else {
      return X; 
    }
  } else {
    return Invalid;
  }
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
  Piece winner = Invalid;
  bool same = false; //row
  for (int i = 0; i < BOARDSIZE; i++) {
    for(int j = 0; j < BOARDSIZE - 1; j++) {
      if(j == 0) {
        if (getPiece(i, j) == getPiece(i, j+1)) {
          same = true;
          if (getPiece(i,j) == Blank) {
            same = false;
          }
        }
      }
      else {
        same = same && (getPiece(i, j) == getPiece(i, j+1));
      }
    }
    if (same) {
      winner = getPiece(0, i);
    }
  }
  
  same = false; //column
  for (int i = 0; i < BOARDSIZE; i++) {
    for(int j = 0; j < BOARDSIZE - 1; j++) {
      if(j == 0) {
        if (getPiece(j, i) == getPiece(j+1, i)) {
          same = true;
          if (getPiece(j,i) == Blank) {
            same = false;
          }
        }
      }
      else {
        same = same && (getPiece(j, i) == getPiece(j+1, i));
      }
    }
    if (same) {
      winner = getPiece(i, 0);
    }
  }
  
  same = false; //diagonal top down
  for(int i = 0; i < BOARDSIZE - 1; i++) {
    if (i == 0) {
      if (getPiece(i, i) == getPiece(i+1, i+1)) {
        same = true;
        if (getPiece(i, i) == Blank) {
          same = false;
        }
      }
    }
    else {
      same = same && (getPiece(i, i) == getPiece(i+1, i+1));
    }
  }
   if (same) {
    winner = getPiece(0, 0);
  }
  
  same = false; //diagonal bottom up
  for(int i = 0; i < BOARDSIZE - 1; i++) {
    if (i == 0) {
      if (getPiece((BOARDSIZE-1) - i, i) == getPiece((BOARDSIZE-1) - i-1, i+1)) {
        same = true;
        if (getPiece((BOARDSIZE-1) - i, i) == Blank) {
          same = false;
        }
      }
    }
    else {
      same = same && (getPiece((BOARDSIZE-1) - i, i) == getPiece((BOARDSIZE-1) - i-1, i+1));
    }
  }
   if (same) {
    winner = getPiece(0, BOARDSIZE - 1);
  }

  
  if (winner == Invalid) {
    bool tie = true;
    for(int i = 0; i < BOARDSIZE; i++) {
      for(int j = 0; j < BOARDSIZE; j++) {
        if (getPiece(i, j) == Blank) {
          tie = false;
        }
      }
    }
    if(tie) {
      return Blank;
    }
  }
  return winner;
}
