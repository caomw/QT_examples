#include "widget.h"
#include <QPalette>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QSignalMapper>
#include <iostream>
using namespace std;

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    QPalette sample_palette;
    QGridLayout *grid;
    QHBoxLayout *grid1,*grid2;
    QFrame *buttons,*numbers;
    QSignalMapper *signalMapper;

    sample_palette.setColor(QPalette::Window, Qt::black);
    sample_palette.setColor(QPalette::WindowText, Qt::white);
    sample_palette.setColor(QPalette::Foreground, Qt::white);
    sample_palette.setColor(QPalette::Text, Qt::white);
    sample_palette.setColor(QPalette::BrightText, Qt::white);
    this->initState();

    /* Block in position (0,0) */
    numbers = new QFrame(this);

    grid2=new QHBoxLayout();
    grid2->addWidget(new QLabel("Number #1: ",this),Qt::AlignRight);
    this->box_num1=new QSpinBox(this);
    this->box_num1->setMinimum(-10);
    this->box_num1->setMaximum(10);
    this->box_num1->setSingleStep(1);
    grid2->addWidget(this->box_num1,Qt::AlignCenter);
    grid2->addWidget(new QLabel("Number #2: ",this),Qt::AlignRight);
    this->box_num2=new QSpinBox(this);
    this->box_num2->setMinimum(-10);
    this->box_num2->setMaximum(10);
    this->box_num2->setSingleStep(1);
    grid2->addWidget(this->box_num2,Qt::AlignCenter);
    numbers->setLayout(grid2);

    /* Block in position (0,1) */
    this->err_msg=new QLabel("",this);

    /* Block in position (0,2) */
    this->info_butt=new QPushButton("About QT",this);
    QObject::connect(this->info_butt,SIGNAL(clicked(bool)),this,SIGNAL(clickedOnInfoButton()));

    /* Block in position (1,0) */
    buttons = new QFrame(this);
    this->plus_butt=new QPushButton("+");
    this->mult_butt=new QPushButton("*");
    this->minus_butt=new QPushButton("-");
    this->div_butt=new QPushButton("/");
    grid1=new QHBoxLayout();
    grid1->addWidget(this->plus_butt,Qt::AlignCenter);
    grid1->addWidget(this->minus_butt,Qt::AlignCenter);
    grid1->addWidget(this->mult_butt,Qt::AlignCenter);
    grid1->addWidget(this->div_butt,Qt::AlignCenter);
    buttons->setLayout(grid1);

    /* Block in position (1,1) */
    this->ris=new QLCDNumber(this);
    this->ris->setAutoFillBackground(true);
    this->ris->setPalette(sample_palette);
    this->ris->setSegmentStyle(QLCDNumber::Outline);
    this->ris->display("");

    /* Block in position (1,2) */
    this->quit_butt=new QPushButton("Quit",this);
    QObject::connect(this->quit_butt,SIGNAL(clicked(bool)),this,SIGNAL(clickedOnQuitButton()));

    /* We compose everything! */
    grid = new QGridLayout();
    grid->addWidget(buttons,1,0);
    grid->addWidget(this->ris,1,1,Qt::AlignCenter);
    grid->addWidget(numbers,0,0,Qt::AlignCenter);
    grid->addWidget(this->err_msg,0,1,Qt::AlignCenter);
    grid->addWidget(this->info_butt,0,2,Qt::AlignCenter);
    grid->addWidget(this->quit_butt,1,2,Qt::AlignCenter);
    this->setLayout(grid);

    /* Advanced Mapping for buttons! */
    signalMapper = new QSignalMapper(this);
    signalMapper->setMapping(this->plus_butt, QString("+"));
    signalMapper->setMapping(this->minus_butt, QString("-"));
    signalMapper->setMapping(this->mult_butt, QString("*"));
    signalMapper->setMapping(this->div_butt, QString("/"));
    connect(this->plus_butt, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(this->minus_butt, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(this->mult_butt, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(this->div_butt, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(signalMapper, SIGNAL(mapped(QString)),this, SLOT(buttonPressed(QString)));
}

Widget::~Widget()
{
    if(this->ris!=NULL) delete this->ris;
    if(this->info_butt!=NULL) delete this->info_butt;
    if(this->quit_butt!=NULL) delete this->quit_butt;
    if(this->plus_butt) delete this->plus_butt;
    if(this->minus_butt!=NULL) delete this->minus_butt;
    if(this->mult_butt) delete this->mult_butt;
    if(this->div_butt!=NULL) delete this->div_butt;
    if(this->box_num1!=NULL) delete this->box_num1;
    if(this->box_num2!=NULL) delete this->box_num2;
     if(this->err_msg!=NULL) delete this->err_msg;
    this->initState();
}

void Widget::initState()
{
    this->ris=NULL;
    this->info_butt=NULL;
    this->quit_butt=NULL;
    this->plus_butt=NULL;
    this->minus_butt=NULL;
    this->mult_butt=NULL;
    this->div_butt=NULL;
    this->box_num1=NULL;
    this->box_num2=NULL;
    this->err_msg=NULL;
}

void Widget::buttonPressed(QString lab)
{
    int v1,v2;

    if(lab=="+")
    {
        v1=this->box_num1->value();
        v2=this->box_num2->value();
        this->ris->display(v1+v2);
        this->err_msg->setText("All is ok");
    }
    else if(lab=="-")
    {
        v1=this->box_num1->value();
        v2=this->box_num2->value();
        this->ris->display(v1-v2);
        this->err_msg->setText("All is ok");
    }
    else if(lab=="*")
    {
        v1=this->box_num1->value();
        v2=this->box_num2->value();
        this->ris->display(v1*v2);
        this->err_msg->setText("All is ok");
    }
    else if(lab=="/")
    {
        v1=this->box_num1->value();
        v2=this->box_num2->value();
        if(v2==0)
        {
            this->ris->display("Err");
            this->err_msg->setText("Division by zero");
        }
        else
        {
            double d=(double)v1/(double)v2;
            this->ris->display(d);
            this->err_msg->setText("All is ok");
        }
    }
    else
    {
        cout<<endl;
        cout.flush();
        cerr<<"\tCommand '"<<lab.toStdString()<<"' is not recognized (unknown)."<<endl;
        this->ris->display("Err");
        this->err_msg->setText("Unknown command");
    }
}
