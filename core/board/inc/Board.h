#pragma once
#include <QObject>
#include <QVector>
#include <QString>
#include "CellStatus.h"
#include <array>
#include "GameStatus.h"


class Board : public QObject
{
    Q_OBJECT


public :
    explicit Board();

    bool operator==(const Board& board2);

    unsigned int size() const;

    void set(const unsigned int &x, const unsigned int &y, CellStatus status);

    CellStatus get(const unsigned int &x, const unsigned int &y) const;

    Q_INVOKABLE void clear();

    bool hasEmptyCell() const;

    GameStatus status() const;


private:

    unsigned int size_{3};
    std::array<std::array<CellStatus, 3>, 3> board_{};

};

