#include "customwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QPixmap>

CustomWindow::CustomWindow(QWidget *parent) : QMainWindow(parent)
{
    QMenu *file,*help;
    QAction *newa,*opena,*quita,*infoQt;

    /* Adding Menu 'File' */
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

    /* Adding Menu 'Help' */
    help=this->menuBar()->addMenu("&Help");
    infoQt = new QAction("About QT",this);
    help->addAction(infoQt);
    connect(infoQt,SIGNAL(triggered()),this,SIGNAL(qtinfo_required()));
    this->setToolTip("Only the 'Quit' and the 'About QT' actions offer feedback");
    this->setToolTipDuration(2000);
}

CustomWindow::~CustomWindow() { ; }

