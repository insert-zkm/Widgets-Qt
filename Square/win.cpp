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

    begin();

    connect(exitButton, &QPushButton::clicked,        this,    &Win::close);
    connect(nextButton, &QPushButton::clicked,        this,    &Win::begin);
    connect(inputEdit,  &QLineEdit::returnPressed,    this,    &Win::calc);
}

Win::~Win()
{
}

void Win::begin()
{
    inputEdit->clear();
    nextButton->setEnabled(false);
    nextButton->setDefault(false);
    inputEdit->setEnabled(true);
    outputLabel->setVisible(false);
    outputEdit->setVisible(false);
    outputEdit->setEnabled(false);
    inputEdit->setFocus();
}

void Win::calc()
{
    bool Ok = true;
    float r, a;
    QString str = inputEdit->text();
    try {
        a = str.toDouble(&Ok);

        if(!qIsFinite(a)) {
            throw std::range_error("Переполнение.");
        }

        if(Ok)
        {
            r = a * a;
            if(!qIsFinite(r)) {
                throw std::range_error("Переполнение.");
            }
            str.setNum(r);
            outputEdit->setText(str);
            inputEdit->setEnabled(false);
            outputLabel->setVisible(true);
            outputEdit->setVisible(true);
            nextButton->setDefault(true);
            nextButton->setEnabled(true);
            nextButton->setFocus();
        }
        else if (!str.isEmpty())
        {
            throw std::invalid_argument("Введено неверное значение.");
        }
    }  catch (std::overflow_error &e) {
        QMessageBox msgBox(QMessageBox::Information,
            "Возведение в квадрат.",
            e.what(),
            QMessageBox::Ok);
        msgBox.exec();
    } catch (std::invalid_argument &e) {
        QMessageBox msgBox(QMessageBox::Information,
            "Возведение в квадрат.",
            e.what(),
            QMessageBox::Ok);
        msgBox.exec();
    }


}

