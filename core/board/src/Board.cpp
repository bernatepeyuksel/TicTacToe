#include "Board.h"
#include <QPainter>
#include <QRadialGradient>
#include <QDebug>
#include <QBuffer>
#include <QUrl>


Board::Board()
{
    clear();
}

unsigned int Board::getWidth() const
{
    return size_;
}

unsigned int Board::getHeight() const
{
    return size_;
}

void  Board::set(const unsigned int &x, const unsigned int &y, CellStatus status)
{
    board_[x][y] = status;
}

CellStatus Board::get(const unsigned int &x, const unsigned int &y)
{
    return board_[x][y];
}

void Board::clear()
{
    std::array<CellStatus, 3> tmp;
    tmp.fill(CellStatus::Empty);
    board_.fill(tmp);
}

std::array<std::array<CellStatus, 3>, 3>  Board::boardData() const
{
    return board_;
}

unsigned int Board::size() const
{
    return size_;
}

bool Board::hasEmptyCell()
{
    for (auto x: board_)
    {
        for (auto y: x)
        {
            if (y == CellStatus::Empty)
            {
                return true;
            }
        }
    }
    return false;
}

GameStatus Board::status()
{
    // Checking Rows for X or O victory.
    for (unsigned int row = 0; row < size(); row++)
    {
        if (get(row, 0) == get(row, 1)&&
            get(row, 1) == get(row, 2))
        {
            if (get(row, 0) == CellStatus::Computer)
                return GameStatus::ComputerWin;
            else if (get(row, 0) == CellStatus::Human)
                return GameStatus::HumanWin;
        }
    }

    // Check Columns for X or O victory.
    for (unsigned int col = 0; col < size(); col++)
    {
        if (get(0,col) == get(1,col)&&
            get(1,col) == get(2,col))
        {
            if (get(0,col) == CellStatus::Computer)
                return GameStatus::ComputerWin;
            else if (get(0,col) == CellStatus::Human)
                return GameStatus::HumanWin;
        }
    }

    // Check Diagonals for X or O victory.
    if (get(0,0) == get(1,1) && get(1,1) == get(2,2))
    {
        if (get(0,0) == CellStatus::Computer)
            return GameStatus::ComputerWin;
        else if (get(0,0) == CellStatus::Human)
            return GameStatus::HumanWin;
    }

    if (get(0,2) == get(1,1) && get(1,1) == get(2,0))
    {
        if (get(0,2) == CellStatus::Computer)
            return GameStatus::ComputerWin;
        else if (get(0,2) == CellStatus::Human)
            return GameStatus::HumanWin;
    }

    // No one has won then return 0
    return hasEmptyCell() ? GameStatus::Continue : GameStatus::Tie;
}



