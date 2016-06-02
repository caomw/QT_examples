#include "widget.h"
#include <QTimer>
#include <QTime>
#include <QString>

Widget::Widget(QWidget *parent) : QLCDNumber(parent)
{
    QTimer *timer;

    this->setSegmentStyle(Filled);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start(1000);
    this->setDigitCount(8);
    this->showTime();
}

void Widget::showTime()
{
    QTime time;
    QString text;

    time = QTime::currentTime();
    text = time.toString("hh:mm:ss");
    if ((time.second() % 2) == 0)
    {
        text[2]=' ';
        text[5]=' ';
    }

    this->display(text);
}
