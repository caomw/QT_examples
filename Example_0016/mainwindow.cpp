#include "mainwindow.h"
#include "flowlayout.h"
#include <QPushButton>
#include <QLabel>

MainWindow::MainWindow()
{
    FlowLayout *flowLayout = new FlowLayout;
    flowLayout->addWidget(new QPushButton(tr("Short")));
    flowLayout->addWidget(new QPushButton(tr("Longer label")));
    flowLayout->addWidget(new QPushButton(tr("Example of the flow layout with a long label")));
    flowLayout->addWidget(new QPushButton(tr("About QT")));
    connect( static_cast<QPushButton*>(flowLayout->itemAt(3)->widget()),SIGNAL(clicked()),this,SIGNAL(qtinfo_required()));
    flowLayout->addWidget(new QPushButton(tr("Quit")));
    connect( static_cast<QPushButton*>(flowLayout->itemAt(4)->widget()),SIGNAL(clicked()),this,SIGNAL(quit_required()));
    flowLayout->itemAt(0)->widget()->setEnabled(false);
    flowLayout->itemAt(1)->widget()->setEnabled(false);
    flowLayout->itemAt(2)->widget()->setEnabled(false);
    this->setLayout(flowLayout);
}

MainWindow::~MainWindow() { ; }
