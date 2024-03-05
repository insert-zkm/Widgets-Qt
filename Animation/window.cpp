#include <QVBoxLayout>

#include "window.h"

Window::Window(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("Обработка событий");
    area = new Area(this);
    btn = new QPushButton("Завершить", this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(area);
    layout->addWidget(btn);

    connect(btn, &QPushButton::clicked, this, &Window::close);
}

Window::~Window()
{
}

