#pragma once
#include <QObject>
#include <QVector>
#include <QString>
#include "Board.h"

class Computer: public QObject
{
    Q_OBJECT

public:
    explicit Computer() = default;

public slots:

    void play(Board* board);

signals:

     void computerPlayed(const unsigned int &x, const unsigned int &y);

     void gameOver(const QString &result);

private:

    int statusToScore(const GameStatus& status);

    int miniMax(Board* board, int depth, bool isMax);

    void bestMove(Board* board);
};
