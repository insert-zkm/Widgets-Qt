#include "win.h"
Win::Win(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("Счетчик");
    label1 = new QLabel("Cчет по 1", this);
    label2 = new QLabel("Cчет по 5", this);
    edit1 = new Counter("0", this);
    edit2 = new Counter("0", this);
    calcbutton = new QPushButton("+1", this);
    exitbutton = new QPushButton("Выход", this);

    QHBoxLayout *layout1 = new QHBoxLayout();
    QHBoxLayout *layout2 = new QHBoxLayout();
    QHBoxLayout *layout3 = new QHBoxLayout();
    QVBoxLayout *layout4 = new QVBoxLayout(this);

    layout4->addLayout(layout1);
    layout4->addLayout(layout2);
    layout4->addLayout(layout3);

    if(!layout1 || !layout2 || !layout3 || !layout4 || !label1 || !label2 || !edit1 || !edit2 || !calcbutton || !exitbutton) {
        this->failed = true;
    } else {
        layout1->addWidget(label1);
        layout1->addWidget(label2);

        layout2->addWidget(edit1);
        layout2->addWidget(edit2);

        layout3->addWidget(calcbutton);
        layout3->addWidget(exitbutton);



        connect(calcbutton, &QPushButton::clicked,      edit1,  &Counter::add_one);
        connect(edit1,      &Counter::tick_signal,      edit2,  &Counter::add_one);
        connect(exitbutton, &QPushButton::clicked,      this,   &Win::close);
    }
}

Win::~Win()
{
}


bool Win::Failed() const {
    return this->failed;
}
