#include <QDebug>
#include <algorithm>
#include "Computer.h"

int Computer::statusToScore(const GameStatus& status)
{
    switch (status)
    {
        case GameStatus::HumanWin:
            return -1;
        case GameStatus::Continue:
        case GameStatus::Tie:
            return 0;
        case GameStatus::ComputerWin:
            return 1;
    }
}

int Computer::miniMax(Board* board, int depth, bool isMax)
{
    GameStatus status = board->status();

    int score = statusToScore(status);

     // If Maximizer has won the game return evaluated score
    if (status != GameStatus::Continue)
    {
        return score;
    }

    int best = isMax ? -1000 : 1000;
    CellStatus move = isMax ? CellStatus::Computer : CellStatus::Human;


    //Traverse all cells
    for ( unsigned int i = 0; i<board->size(); i++)
    {
        for (unsigned int j = 0; j<board->size(); j++)
        {
            // Check if cell is empty
            if (board->get(i,j) == CellStatus::Empty)
            {
                // Make the move
                board->set(i,j, move);

                // Call minimax recursively and choose
                // the maximum value
                best = isMax ? std::max( best, miniMax(board, depth+1, !isMax) ) : std::min(best, miniMax(board, depth+1, !isMax));

                // Undo the move
                board->set(i,j, CellStatus::Empty);
            }
        }
    }
    return best;
}

void Computer::bestMove(Board* board)
{
    if (nullptr == board)
        return;

    int bestVal = -1000;
    QPair<unsigned int, unsigned int> bestMove;

    for(unsigned int row=0; row < board->size(); row++)
    {
        for(unsigned int elem=0; elem < board->size(); elem++)
        {
            // Check if cell is empty
            if(board->get(row,elem) == CellStatus::Empty )
            {
                // Make the move
                board->set(row, elem, CellStatus::Computer);

                // compute evaluation function for this move.
                int moveVal = miniMax(board, 0, false);

                // Undo the move
                board->set(row, elem, CellStatus::Empty);

                // If the value of the current move is
                // more than the best value, then update best
                if (moveVal > bestVal)
                {
                    bestMove.first = row;
                    bestMove.second = elem;
                    bestVal = moveVal;
                }
            }
        }
    }
    board->set(bestMove.first, bestMove.second, CellStatus::Computer);
    emit computerPlayed(bestMove.first, bestMove.second);
}


void Computer::play(Board* board)
{
    bestMove(board);

    GameStatus status = board->status();

    if(GameStatus::ComputerWin == status)
    {
        emit gameOver("Computer won!");
    }
    else if(GameStatus::Tie == status)
    {
        emit gameOver("It's a tie!");
    }

}
