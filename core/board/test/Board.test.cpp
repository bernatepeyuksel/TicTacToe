#include <gtest/gtest.h>
#include "Board.h"


//************* Clear Tests *************//

TEST(Board, clearCheckIfAllEmptyCell) {
  // Arrange
  Board boardEmpty;
  Board boardFull;
  boardFull.set(0,0, CellStatus::Computer);
  boardFull.set(0,1, CellStatus::Human);
  boardFull.set(0,2, CellStatus::Computer);
  boardFull.set(1,0, CellStatus::Human);
  boardFull.set(1,1, CellStatus::Computer);
  boardFull.set(1,2, CellStatus::Human);
  boardFull.set(2,0, CellStatus::Computer);
  boardFull.set(2,1, CellStatus::Human);
  boardFull.set(2,2, CellStatus::Computer);
  // Act
  boardFull.clear();

  bool clear = boardFull.boardData() == boardEmpty.boardData() ? true : false;
  // Assert
  EXPECT_EQ(clear, true);
}

//************* HasEmptyCell Tests *************//

TEST(Board, hasEmptyCellReturnFalseIfNoEmptyCell) {
  // Arrange
  Board board;
  board.set(0,0, CellStatus::Computer);
  board.set(0,1, CellStatus::Human);
  board.set(0,2, CellStatus::Computer);
  board.set(1,0, CellStatus::Human);
  board.set(1,1, CellStatus::Computer);
  board.set(1,2, CellStatus::Human);
  board.set(2,0, CellStatus::Computer);
  board.set(2,1, CellStatus::Human);
  board.set(2,2, CellStatus::Computer);
  // Act
  bool hasEmptyCell = board.hasEmptyCell();

  // Assert
  EXPECT_EQ(hasEmptyCell, false);
}

TEST(Board, hasEmptyCellReturnTrueIfEmptyCell) {
  // Arrange
  Board board;
  board.set(0,0, CellStatus::Computer);
  board.set(0,1, CellStatus::Human);
  board.set(0,2, CellStatus::Computer);
  board.set(1,0, CellStatus::Human);
  board.set(1,1, CellStatus::Computer);
  board.set(1,2, CellStatus::Human);
  board.set(2,0, CellStatus::Empty);
  board.set(2,1, CellStatus::Human);
  board.set(2,2, CellStatus::Computer);

  // Act
  bool hasEmptyCell = board.hasEmptyCell();

  // Assert
  EXPECT_EQ(hasEmptyCell, true);
}

//************* Status Diagonal Tests *************//

TEST(Board, statusReturnComputerWinIfFirstDiagnolMatch) {
  // Arrange
  Board board;
  board.set(0,0, CellStatus::Computer);
  board.set(1,1, CellStatus::Computer);
  board.set(2,2, CellStatus::Computer);

  // Act
  GameStatus status = board.status();

  // Assert
  EXPECT_EQ(status, GameStatus::ComputerWin);
}

TEST(Board, statusReturnHumanIfFirstDiagnolMatch) {
  // Arrange
  Board board;
  board.set(0,0, CellStatus::Human);
  board.set(1,1, CellStatus::Human);
  board.set(2,2, CellStatus::Human);
  
  // Act
  GameStatus status = board.status();

  // Assert
  EXPECT_EQ(status, GameStatus::HumanWin);
}

TEST(Board, statusReturnComputerWinIfSecondDiagnolMatch) {
  // Arrange
  Board board;
  board.set(0,2, CellStatus::Computer);
  board.set(1,1, CellStatus::Computer);
  board.set(2,0, CellStatus::Computer);
  
  // Act
  GameStatus status = board.status();

  // Assert
  EXPECT_EQ(status, GameStatus::ComputerWin);
}

TEST(Board, statusReturnHumanIfSecondDiagnolMatch) {
  // Arrange
  Board board;
  board.set(0,2, CellStatus::Human);
  board.set(1,1, CellStatus::Human);
  board.set(2,0, CellStatus::Human);
  
  // Act
  GameStatus status = board.status();

  // Assert
  EXPECT_EQ(status, GameStatus::HumanWin);
}

//************* Status Row Tests *************//

TEST(Board, statusReturnComputerWinIfSecondRowMatch) {
  // Arrange
  Board board;
  board.set(1,0, CellStatus::Computer);
  board.set(1,1, CellStatus::Computer);
  board.set(1,2, CellStatus::Computer);
  
  // Act
  GameStatus status = board.status();

  // Assert
  EXPECT_EQ(status, GameStatus::ComputerWin);
}

TEST(Board, statusReturnHumanIfSecondRowMatch) {
  // Arrange
  Board board;
  board.set(1,0, CellStatus::Human);
  board.set(1,1, CellStatus::Human);
  board.set(1,2, CellStatus::Human);
  
  // Act
  GameStatus status = board.status();

  // Assert
  EXPECT_EQ(status, GameStatus::HumanWin);
}

//************* Status Column Tests *************//
TEST(Board, statusReturnComputerWinIfSecondColumnMatch) {
  // Arrange
  Board board;
  board.set(0,1, CellStatus::Computer);
  board.set(1,1, CellStatus::Computer);
  board.set(2,1, CellStatus::Computer);
  
  // Act
  GameStatus status = board.status();

  // Assert
  EXPECT_EQ(status, GameStatus::ComputerWin);
}

TEST(Board, statusReturnHumanIfSecondColumnMatch) {
  // Arrange
  Board board;
  board.set(0,1, CellStatus::Human);
  board.set(1,1, CellStatus::Human);
  board.set(2,1, CellStatus::Human);
  
  // Act
  GameStatus status = board.status();

  // Assert
  EXPECT_EQ(status, GameStatus::HumanWin);
}
