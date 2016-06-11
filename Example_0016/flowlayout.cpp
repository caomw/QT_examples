#include "flowlayout.h"
#include <QWidget>

FlowLayout::FlowLayout(QWidget *parent, int margin, int hSpacing, int vSpacing) : QLayout(parent), m_hSpace(hSpacing), m_vSpace(vSpacing) { this->setContentsMargins(margin, margin, margin, margin); }

FlowLayout::FlowLayout(int margin, int hSpacing, int vSpacing) : m_hSpace(hSpacing), m_vSpace(vSpacing) { this->setContentsMargins(margin, margin, margin, margin); }

FlowLayout::~FlowLayout()
{
    QLayoutItem *item;

    while ((item = this->takeAt(0))) delete item;
}

int FlowLayout::count() const { return this->items.size(); }

QLayoutItem * FlowLayout::itemAt(int index) const { return this->items.value(index); }

QLayoutItem *FlowLayout::takeAt(int index)
{
    if ( (index >= 0) && (index < this->items.size()) ) return this->items.takeAt(index);
    else return 0;
}

Qt::Orientations FlowLayout::expandingDirections() const { return Qt::Horizontal | Qt::Vertical; }

void FlowLayout::addItem(QLayoutItem *item) { this->items.append(item); }

QSize FlowLayout::sizeHint() const { return this->minimumSize(); }

bool FlowLayout::hasHeightForWidth() const { return true; }

int FlowLayout::horizontalSpacing() const
{
    if (this->m_hSpace >= 0) { return this->m_hSpace; }
    else { return this->smartSpacing(QStyle::PM_LayoutHorizontalSpacing); }
}

int FlowLayout::verticalSpacing() const
{
    if(this->m_vSpace >= 0) { return this->m_vSpace; }
    else { return this->smartSpacing(QStyle::PM_LayoutVerticalSpacing); }
}

void FlowLayout::setGeometry(const QRect &rect)
{
    QLayout::setGeometry(rect);
    this->doLayout(rect, false);
}

int FlowLayout::heightForWidth(int width) const { return this->doLayout(QRect(0, 0, width, 0), false); }

QSize FlowLayout::minimumSize() const
{
    QSize size;
    QLayoutItem *item;

    foreach (item, this->items) size = size.expandedTo(item->minimumSize());
    size += QSize(2*margin(), 2*margin());
    return size;
}

int FlowLayout::smartSpacing(QStyle::PixelMetric pm) const
{
    QObject *parent = this->parent();
    if(!parent) { return -1; }
    else if (parent->isWidgetType())
    {
        QWidget *pw = static_cast<QWidget *>(parent);
        return pw->style()->pixelMetric(pm, 0, pw);
    }
    else { return static_cast<QLayout *>(parent)->spacing(); }
}

int FlowLayout::doLayout(const QRect &rect, bool testOnly) const
{
    int left, top, right, bottom,x,y,lineHeight,spaceX,spaceY,nextX;
    QRect effectiveRect;
    QLayoutItem *item;
    QWidget *wid;

    this->getContentsMargins(&left, &top, &right, &bottom);
    effectiveRect=rect.adjusted(+left, +top, -right, -bottom);
    x = effectiveRect.x();
    y = effectiveRect.y();
    lineHeight=0;
    foreach (item, this->items)
    {
        wid = item->widget();
        spaceX = this->horizontalSpacing();
        if (spaceX == -1) spaceX = wid->style()->layoutSpacing(QSizePolicy::PushButton, QSizePolicy::PushButton, Qt::Horizontal);
        spaceY = this->verticalSpacing();
        if (spaceY == -1) spaceY = wid->style()->layoutSpacing(QSizePolicy::PushButton, QSizePolicy::PushButton, Qt::Vertical);
        nextX = x + item->sizeHint().width() + spaceX;
        if (nextX - spaceX > effectiveRect.right() && lineHeight > 0)
        {
            x = effectiveRect.x();
            y = y + lineHeight + spaceY;
            nextX = x + item->sizeHint().width() + spaceX;
            lineHeight = 0;
        }

        if (!testOnly) item->setGeometry(QRect(QPoint(x, y), item->sizeHint()));
        x = nextX;
        lineHeight = qMax(lineHeight, item->sizeHint().height());
    }

    return y + lineHeight - rect.y() + bottom;
}
