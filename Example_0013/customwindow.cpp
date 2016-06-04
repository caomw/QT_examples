#include "customwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QPixmap>
#include <QStatusBar>
#include <QToolBar>
#include <QIcon>

CustomWindow::CustomWindow(QWidget *parent) : QMainWindow(parent)
{
    QMenu *file,*help,*view;
    QAction *newa,*opena,*quita,*quita2,*infoQt;
    QIcon *ico_new;

    /* Adding Menu 'File' */
    this->tsb_action=NULL;
    file=this->menuBar()->addMenu("&File");
    QPixmap newpix("new_icon.png");
    newa = new QAction(newpix,"&New",this);
    newa->setShortcut(tr("CTRL+N"));
    QPixmap openpix("open_icon.png");
    opena = new QAction(openpix,"&Open",this);
    opena->setShortcut(tr("CTRL+O"));
    QPixmap quitpix("quit_icon.png");
    quita = new QAction(quitpix,"&Quit",this);
    quita->setShortcut(tr("CTRL+Q"));
    connect(quita,SIGNAL(triggered()),this,SIGNAL(quit_required()));
    file->addAction(newa);
    file->addAction(opena);
    file->addSeparator();
    file->addAction(quita);

    /* Adding Menu 'View' */
    view=this->menuBar()->addMenu("&View");
    this->tsb_action=new QAction("&Toggle status bar",this);
    this->tsb_action->setShortcut(tr("CRTL+V"));
    view->addAction(this->tsb_action);
    connect(this->tsb_action,SIGNAL(triggered()),this,SLOT(toggleStatusBar()));
    this->tsb_action->setCheckable(true);
    this->tsb_action->setChecked(true);
    this->statusBar()->show();
    this->statusBar()->showMessage("The status and the tool bars can be shown/hidden by the actions in the 'View' Menu");

    /* Adding Menu 'Help' */
    help=this->menuBar()->addMenu("&Help");
    infoQt = new QAction("About QT",this);
    help->addAction(infoQt);
    connect(infoQt,SIGNAL(triggered()),this,SIGNAL(qtinfo_required()));
    this->setToolTip("Only the 'Quit' and the 'About QT' actions offer feedback");
    this->setToolTipDuration(2000);

    /* Adding ToolBar */
    this->toolBar=this->addToolBar("Toolbar");
    this->toolBar->addAction(QIcon(newpix),"New");
    this->toolBar->addAction(QIcon(openpix),"Open");
    this->toolBar->addSeparator();
    quita2=this->toolBar->addAction(QIcon(quitpix),"Quit");
    connect(quita2,SIGNAL(triggered()),this,SIGNAL(quit_required()));

    /* Toggle ToolBar */
    this->tb_action=new QAction("&Toggle tool bar",this);
    this->tb_action->setShortcut(tr("CRTL+T"));
    view->addAction(this->tb_action);
    connect(this->tb_action,SIGNAL(triggered()),this,SLOT(toggleToolBar()));
    this->tb_action->setCheckable(true);
    this->tb_action->setChecked(true);
}

CustomWindow::~CustomWindow()
{
    if(this->tsb_action!=NULL) delete this->tsb_action;
    this->tsb_action=NULL;
    if(this->tb_action!=NULL) delete this->tb_action;
    this->tb_action=NULL;
}

void CustomWindow::toggleStatusBar()
{
    if (this->tsb_action->isChecked()) { this->statusBar()->show(); }
    else { this->statusBar()->hide(); }
}

void CustomWindow::toggleToolBar()
{
    if (this->tb_action->isChecked()) { this->toolBar->show(); }
    else { this->toolBar->hide(); }
}
