#include "customwidget.h"
#include <QGridLayout>
#include <iostream>
using namespace std;

CustomWidget::CustomWidget(QWidget *parent) : QWidget(parent)
{
    QGridLayout *grid;

    this->initState();
    this->butt1=new QPushButton("Enable",this);
    this->butt2=new QPushButton("Quit",this);
    this->butt3=new QPushButton("QT Version",this);
    this->butt2->setEnabled(false);
    QObject::connect(this->butt1,SIGNAL(clicked(bool)),this,SLOT(enableQuitButton()));
    QObject::connect(this->butt2,SIGNAL(clicked(bool)),this,SIGNAL(clickedOnQuitButton()));
    QObject::connect(this->butt3,SIGNAL(clicked(bool)),this,SIGNAL(clickedOnInfoButton()));
    grid = new QGridLayout();
    grid->addWidget(this->butt3,0,0);
    grid->addWidget(this->butt1,0,1);
    grid->addWidget(this->butt2,0,2);
    this->setLayout(grid);
}

CustomWidget::~CustomWidget()
{
    if(this->butt1!=NULL) delete this->butt1;
    if(this->butt2!=NULL) delete this->butt2;
    if(this->butt3!=NULL) delete this->butt3;
    this->initState();
}

void CustomWidget::enableQuitButton()
{
    /* Button 'Quit' is enabled? */
    if(this->butt2->isEnabled())
    {
        /* Button 'Quit' must be disabled, and we must change label as 'Enable'! */
        this->butt2->setEnabled(false);
        this->butt1->setText("Enable");
    }
    else
    {
         /* Button 'Quit' must be enable, and we must change label as 'Disable'! */
        this->butt2->setEnabled(true);
        this->butt1->setText("Disable");
    }
}

void CustomWidget::initState()
{
    this->butt1=NULL;
    this->butt2=NULL;
    this->butt3=NULL;
}

