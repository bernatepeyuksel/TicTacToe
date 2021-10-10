#pragma once
#include <QObject>
#include <QString>
#include "Board.h"

class Human: public QObject
{
    Q_OBJECT
public:

    Q_INVOKABLE void play(Board* board, const unsigned int& x, const unsigned int& y);

signals:

     void humanPlayed(Board* board);

     void gameOver(const QString &result);

};


