#include "cardlayout.h"

CardLayout::CardLayout(QWidget *parent) : QLayout(parent) { ; }

CardLayout::~CardLayout()
{
    QLayoutItem *item;

    while ((item = takeAt(0))) delete item;
}

void CardLayout::addItem(QLayoutItem *item) { this->list.append(item); }

void CardLayout::addWidget(QWidget *widget) { this->list.append( new QWidgetItem(widget) ); }

QSize CardLayout::sizeHint() const
{
    QSize s(0,0);
    int n,i;

    n = list.count();
    if (n > 0) s = QSize(100,70);
    i=0;
    while (i < n)
    {
       QLayoutItem *o = list.at(i);
       s = s.expandedTo(o->sizeHint());
       ++i;
    }

    return s + n*QSize(spacing(), spacing());
}

QSize CardLayout::minimumSize() const
{
    QSize s(0,0);
    int n,i;

    n = list.count();
    i=0;
    while (i < n)
    {
       QLayoutItem *o = list.at(i);
       s = s.expandedTo(o->sizeHint());
       ++i;
    }

    return s + n*QSize(spacing(), spacing());
}

int CardLayout::count() const { return this->list.size(); }

QLayoutItem * CardLayout::itemAt(int idx) const { return this->list.value(idx); }

QLayoutItem * CardLayout::takeAt(int idx)
{
    if( (idx>=0) && (idx<this->list.size() ) ) return this->list.takeAt(idx);
    else return 0;
}

void CardLayout::setGeometry(const QRect &r)
{
    int w,h,i;

    QLayout::setGeometry(r);
    if(this->count()==0) return;
    w = r.width() - (this->list.count() - 1) * spacing();
    h = r.height() - (this->list.count() - 1) * spacing();
    i=0;
    while (i < list.size())
    {
        QRect geom(r.x() + i * spacing(), r.y() + i * spacing(), w, h);
        this->list.at(i)->setGeometry(geom);
        ++i;
    }
}
