/********************************************************************************************************************************************************
 * David Canino - canino.david@gmail.com
 *
 * Basic examples for the QT Library
 * Github: https://github.com/davidcanino/QT_examples.git
 *
 * This is QT Project file of the basic example for opening a new main window in the current QT Library (Example_0003). No parameter is required.
 *
 * File main.cpp - main function. Last update: May 2016
 *******************************************************************************************************************************************************/

#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <cstdlib>
using namespace std;

/* Main function - no parameter is required! */
int main(int argc, char *argv[])
{
    MainWindow *w;
    QApplication a(argc,argv);
    int ris;

    /* First, we check parameters! */
    if(argc!=1)
    {
        cout<<endl;
        cout.flush();
        cerr<<"\tError: no parameter is required."<<endl;
        cerr<<"Use: "<<string(argv[0])<<endl<<endl;
        return EXIT_FAILURE;
    }

    /* If we arrive here, all is ok! */
    w=NULL;
    w=new MainWindow(QString("New Main Window"));
    w->resize(250,150);
    w->show();
    ris=a.exec();
    delete w;
    w=NULL;
    return ris;
}
