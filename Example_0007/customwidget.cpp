/*************************************************************************************************************************
 * David Canino - canino.david@gmail.com
 *
 * Basic examples for the QT Library
 * Github: https://github.com/davidcanino/QT_examples.git
 *
 * Another basic example for QWidgets. No parameter is required.
 *
 * Definition of a custom widget.
 *
 * Last update: May 2016
 *************************************************************************************************************************/

#include "customwidget.h"
#include <QFrame>
#include <QGridLayout>

CustomWidget::CustomWidget(QWidget *parent) : QWidget(parent)
{
    QFrame *frame1,*frame2,*frame3;
    QGridLayout *grid;

    /* Frame #1 - style: Panel, cursor: ArrowCursor */
    frame1 = new QFrame(this);
    frame1->setCursor(Qt::ArrowCursor);
    frame1->setFrameStyle(QFrame::Panel);

    /* Frame #2 - style: Box, cursor: CrossCursor */
    frame2 = new QFrame(this);
    frame2->setCursor(Qt::CrossCursor);
    frame2->setFrameStyle(QFrame::Box);

    /* Frame #3 - style: StyledPanel, cursor: SplitVCursor */
    frame3 = new QFrame(this);
    frame3->setCursor(Qt::SplitVCursor);
    frame3->setFrameStyle(QFrame::StyledPanel);

    /* Grid 1x3 layout: [ frame1 ] - [ frame2 ] - [ frame3 ] */
    grid=new QGridLayout();
    grid->addWidget(frame1,0,0);
    grid->addWidget(frame2,0,1);
    grid->addWidget(frame3,0,2);
    this->setLayout(grid);
}

