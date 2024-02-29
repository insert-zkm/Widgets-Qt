#ifndef WIN_H
#define WIN_H

#include <QWidget>
#include <QtWidgets>

class Counter:public QLineEdit
{
    Q_OBJECT
public:
    Counter(const QString & contents, QWidget *parent = 0):
        QLineEdit(contents, parent)
    {
        this->setReadOnly(true);
    }
signals:
    void tick_signal();
public slots:
    void add_one()
    {
        QString str = text();
        int r = str.toInt();
        r++;
        if (r != 0 && r % 5 == 0) emit tick_signal();
        str.setNum(r);
        setText(str);
    }
};

class Win : public QWidget
{
    Q_OBJECT

public:
    Win(QWidget *parent = nullptr);
    ~Win();
protected:
    QLabel *label1,*label2;
    Counter *edit1,*edit2;
    QPushButton *calcbutton;
    QPushButton *exitbutton;
};
#endif // WIN_H
