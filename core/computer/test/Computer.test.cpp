#include <gtest/gtest.h>
#include "Computer.h"



class ComputerUnitTest: public ::testing::Test, public Computer {

};

//************* BestMove Test *************//

TEST_F(ComputerUnitTest, clearCheckIfBestMove) {
  // Arrange
    Board board;
    board.set(0,0, CellStatus::Computer);
    board.set(0,1, CellStatus::Human);
    board.set(0,2, CellStatus::Empty);
    board.set(1,0, CellStatus::Human);
    board.set(1,1, CellStatus::Computer);
    board.set(1,2, CellStatus::Empty);
    board.set(2,0, CellStatus::Empty);
    board.set(2,1, CellStatus::Empty);
    board.set(2,2, CellStatus::Human);

    // Act
    QPair<unsigned int, unsigned int> move = bestMove(&board);

    // Assert
    QPair<unsigned int, unsigned int> bestVal{0,2};

    EXPECT_EQ( move,bestVal);
}

//************* MiniMax Test *************//

TEST_F(ComputerUnitTest, clearCheckIfMinimax) {
  // Arrange
    Board board;
    Computer computer;
    board.set(0,0, CellStatus::Computer);
    board.set(0,1, CellStatus::Computer);
    board.set(0,2, CellStatus::Human);
    board.set(1,0, CellStatus::Human);
    board.set(1,1, CellStatus::Human);
    board.set(1,2, CellStatus::Computer);
    board.set(2,0, CellStatus::Computer);
    board.set(2,1, CellStatus::Empty);
    board.set(2,2, CellStatus::Empty);

    // Act
    int max = miniMax(&board, false);

    // Assert
    EXPECT_EQ( max, 0);
}
