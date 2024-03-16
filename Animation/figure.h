#ifndef FIGURE_H
#define FIGURE_H


#include <QPainter>

class Figure
{
protected:
    int x, y, halflen, dx, dy, r;
    virtual void draw(QPainter *Painter) = 0;

public:
    Figure(int X, int Y, int Halflen):
        x(X), y(Y), halflen(Halflen) {}
    virtual ~Figure() = default;

    void move(float Alpha, QPainter *Painter);
};

class MyLine : public Figure {
protected:
    void draw(QPainter *Painter);

public:
    MyLine(int x, int y, int halflen) : Figure(x, y, halflen) {}
    ~MyLine() = default;
};

class MyRect : public Figure
{
protected:
    void draw(QPainter *Painter);

public:
    MyRect(int x, int y, int halflen) : Figure(x, y, halflen) {}
    ~MyRect() = default;
};

#endif // FIGURE_H
