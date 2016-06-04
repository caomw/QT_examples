#include "customwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QPixmap>
#include <QStatusBar>

CustomWindow::CustomWindow(QWidget *parent) : QMainWindow(parent)
{
    QMenu *file,*help,*view;
    QAction *newa,*opena,*quita,*infoQt;

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
    this->statusBar()->showMessage("The status bar can be shown/hidden by the action in the 'View' Menu");

    /* Adding Menu 'Help' */
    help=this->menuBar()->addMenu("&Help");
    infoQt = new QAction("About QT",this);
    help->addAction(infoQt);
    connect(infoQt,SIGNAL(triggered()),this,SIGNAL(qtinfo_required()));
    this->setToolTip("Only the 'Quit' and the 'About QT' actions offer feedback");
    this->setToolTipDuration(2000);
}

CustomWindow::~CustomWindow()
{
    if(this->tsb_action!=NULL) delete this->tsb_action;
    this->tsb_action=NULL;
}

void CustomWindow::toggleStatusBar()
{
    if (this->tsb_action->isChecked()) { this->statusBar()->show(); }
    else { this->statusBar()->hide(); }
}
