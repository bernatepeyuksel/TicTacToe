#include <QDebug>
#include <algorithm>
#include "Human.h"




void Human::play(Board* board, const unsigned int &x, const unsigned int &y)
{
    if(nullptr == board)
    {
        qCritical() <<"Board null! ";
        return;
    }

    board->set(x,y, CellStatus::Human);

    GameStatus status = board->status();

    if(GameStatus::HumanWin == status)
    {
        emit gameOver("You won!");
    }
    else if(GameStatus::Tie == status)
    {
        emit gameOver("It's a tie!");
    }
    else
    {
        emit humanPlayed(board);
    }
}
