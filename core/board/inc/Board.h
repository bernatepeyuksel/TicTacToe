#pragma once
#include <QObject>
#include <QQuickPaintedItem>
#include <QImage>
#include <QPixmap>
#include <QSize>
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

    std::array<std::array<CellStatus, 3>, 3>  boardData() const;

    unsigned int size() const;

    unsigned int getWidth() const;

    unsigned int getHeight() const;

    void set(const unsigned int &x, const unsigned int &y, CellStatus status);

    CellStatus get(const unsigned int &x, const unsigned int &y);

    Q_INVOKABLE void clear();

    bool hasEmptyCell();

    GameStatus status();


private:

    unsigned int size_{3};
    std::array<std::array<CellStatus, 3>, 3> board_ = {};

};

