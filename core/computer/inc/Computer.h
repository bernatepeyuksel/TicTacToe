#pragma once
#include <QObject>
#include <QString>
#include "Board.h"

class Computer: public QObject
{
    Q_OBJECT

public:


public slots:

    void play(Board* board);

signals:

     void computerPlayed(const unsigned int &x, const unsigned int &y);

     void gameOver(const QString &result);

protected:

    int statusToScore(const GameStatus& status) const;

    int miniMax(Board& board, bool isMax) const;

     QPair<unsigned int, unsigned int> bestMove(Board& board);
};

