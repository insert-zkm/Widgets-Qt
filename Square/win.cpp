#include "win.h"

Win::Win(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Возведение в квадрат");
    frame = new QFrame(this);
    frame->setFrameShadow(QFrame::Raised);
    frame->setFrameShape(QFrame::Panel);

    inputLabel  = new QLabel("Введите число:", this);
    inputEdit   = new QLineEdit("",this);

    StrValidator *v=new StrValidator(inputEdit);
    inputEdit->setValidator(v);

    outputLabel = new QLabel("Результат:", this);
    outputEdit  = new QLineEdit("",this);
    nextButton  = new QPushButton("Следующее", this);
    exitButton  = new QPushButton("Выход", this);

    // компоновка приложения выполняется согласно рисунку 2.
    QVBoxLayout *vLayout1 = new QVBoxLayout(frame);
    vLayout1->addWidget(inputLabel);
    vLayout1->addWidget(inputEdit);
    vLayout1->addWidget(outputLabel);
    vLayout1->addWidget(outputEdit);
    vLayout1->addStretch();

    QVBoxLayout *vLayout2 = new QVBoxLayout();
    vLayout2->addWidget(nextButton);
    vLayout2->addWidget(exitButton);
    vLayout2->addStretch();

    QHBoxLayout *hLayout = new QHBoxLayout(this);
    hLayout->addWidget(frame);
    hLayout->addLayout(vLayout2);
}

Win::~Win()
{
}

