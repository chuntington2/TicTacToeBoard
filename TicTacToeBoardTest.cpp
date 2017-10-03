/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, sanityCheck)
{
	ASSERT_TRUE(true);
}
*/

TEST(TicTacToeBoardTest, turnSwitch1)
{	
	TicTacToeBoard board;
	ASSERT_TRUE(board.toggleTurn() == O);
}

TEST(TicTacToeBoardTest, turnSwitch2)
{	
	TicTacToeBoard board;
	ASSERT_TRUE(board.toggleTurn() == O);
	ASSERT_TRUE(board.toggleTurn() == X);
}

TEST(TicTacToeBoardTest, turnSwitch3)
{	
	TicTacToeBoard board;
	ASSERT_TRUE(board.toggleTurn() == O);
	ASSERT_TRUE(board.toggleTurn() == X);
	ASSERT_TRUE(board.toggleTurn() == O);
}

TEST(TicTacToeBoardTest, place1)
{
	TicTacToeBoard board;
	ASSERT_TRUE(board.placePiece(0,0) == X);
	ASSERT_TRUE(board.placePiece(0,1) == O);
	ASSERT_TRUE(board.placePiece(1,1) == X);
	ASSERT_TRUE(board.placePiece(0,2) == O);
	ASSERT_TRUE(board.placePiece(2,2) == X);
}

TEST(TicTacToeBoardTest, place2)
{
	TicTacToeBoard board;
	ASSERT_TRUE(board.placePiece(0,0) == X);
	ASSERT_TRUE(board.placePiece(0,0) == X);
	ASSERT_TRUE(board.placePiece(0,1) == O);
	ASSERT_TRUE(board.placePiece(1,0) == X);
}

TEST(TicTacToeBoardTest, place3)
{
	TicTacToeBoard board;
	ASSERT_TRUE(board.placePiece(3,0) == Invalid);/* 
	BUG: When the column for getpiece is equal to the size of the board, it should return invalid.
	ACTUAL: Accepts it if the column is equal to the boardsize and gets a piece out of bounds
	*/
	ASSERT_TRUE(board.placePiece(0,3) == Invalid);
	ASSERT_TRUE(board.placePiece(3,3) == Invalid);
	ASSERT_TRUE(board.placePiece(-1,0) == Invalid);
	ASSERT_TRUE(board.placePiece(0,-1) == Invalid);
	ASSERT_TRUE(board.placePiece(-1,-1) == Invalid);
}

TEST(TicTacToeBoardTest, rowWin)
{
	TicTacToeBoard board;
	ASSERT_TRUE(board.placePiece(0,0) == X);
	ASSERT_TRUE(board.placePiece(1,0) == O);
	ASSERT_TRUE(board.placePiece(0,1) == X);
	ASSERT_TRUE(board.placePiece(2,1) == O);
	ASSERT_TRUE(board.placePiece(0,2) == X);
	ASSERT_TRUE(board.getPiece(2,0) == Blank);
	ASSERT_TRUE(board.getPiece(0,1) == X);
	ASSERT_TRUE(board.getWinner() == X);
	ASSERT_TRUE(board.placePiece(2,2) == Invalid);
}

TEST(TicTacToeBoardTest, colWin)
{
	TicTacToeBoard board;
	ASSERT_TRUE(board.placePiece(0,2) == X);
	ASSERT_TRUE(board.placePiece(1,0) == O);
	ASSERT_TRUE(board.placePiece(0,1) == X);
	ASSERT_TRUE(board.placePiece(2,0) == O);
	ASSERT_TRUE(board.placePiece(1,2) == X);
	ASSERT_TRUE(board.placePiece(0,0) == O);
	ASSERT_TRUE(board.getPiece(1,1) == Blank);
	ASSERT_TRUE(board.getPiece(0,1) == X);
	ASSERT_TRUE(board.getWinner() == O);
	ASSERT_TRUE(board.placePiece(2,2) == Invalid);
}

TEST(TicTacToeBoardTest, diagWin1)
{
	TicTacToeBoard board;
	ASSERT_TRUE(board.placePiece(0,0) == X);
	ASSERT_TRUE(board.placePiece(1,0) == O);
	ASSERT_TRUE(board.placePiece(1,1) == X);
	ASSERT_TRUE(board.placePiece(2,0) == O);
	ASSERT_TRUE(board.placePiece(2,2) == X);
	ASSERT_TRUE(board.getPiece(1,2) == Blank);
	ASSERT_TRUE(board.getWinner() == X);
}

TEST(TicTacToeBoardTest, diagWin2)
{
	TicTacToeBoard board;
	ASSERT_TRUE(board.placePiece(0,2) == X);
	ASSERT_TRUE(board.placePiece(1,0) == O);
	ASSERT_TRUE(board.placePiece(1,1) == X);
	ASSERT_TRUE(board.placePiece(0,0) == O);
	ASSERT_TRUE(board.placePiece(2,0) == X);
	ASSERT_TRUE(board.getPiece(1,2) == Blank);
	ASSERT_TRUE(board.getWinner() == X);
}

TEST(TicTacToeBoardTest, ties)
{
	TicTacToeBoard board;
	ASSERT_TRUE(board.placePiece(0,0) == X);
	ASSERT_TRUE(board.placePiece(0,1) == O);
	ASSERT_TRUE(board.placePiece(0,2) == X);
	ASSERT_TRUE(board.placePiece(1,0) == O);
	ASSERT_TRUE(board.placePiece(1,2) == X);
	ASSERT_TRUE(board.placePiece(1,1) == O);
	ASSERT_TRUE(board.placePiece(2,0) == X);
	ASSERT_TRUE(board.placePiece(2,2) == O);
	ASSERT_TRUE(board.getWinner() == Invalid);
	ASSERT_TRUE(board.placePiece(2,1) == X);
	ASSERT_TRUE(board.getWinner() == Blank);
}

