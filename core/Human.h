#pragma once
#include <QObject>
#include <QVector>
#include <QString>
#include "Board.h"

class Human: public QObject
{
    Q_OBJECT
public:
    explicit Human() = default;

    Q_INVOKABLE void play(Board* board, const unsigned int& x, const unsigned int& y);

signals:

     void humanPlayed(Board* board);

     void gameOver(const QString &result);

};


