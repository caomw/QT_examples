/*************************************************************************************************************************
 * David Canino - canino.david@gmail.com
 *
 * Basic examples for the QT Library
 * Github: https://github.com/davidcanino/QT_examples.git
 *
 * Custom example of the FlowLayout. No parameter is required.
 *
 * Last update: June 2016
 *************************************************************************************************************************/

#include "mainwindow.h"
#include <QApplication>
#include<iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[])
{
    /* First, we check whether all is ok! */
    cout<<endl<<"\tEXAMPLE '"<<string(argv[0])<<"'"<<endl<<endl;
    if(argc!=1)
    {
       cout.flush();
       cerr<<"\tError: too much parameters"<<endl<<endl;
       cerr<<"\tUsage: "<<string(argv[0])<<endl<<endl;
       cerr.flush();
       return EXIT_FAILURE;
    }

    QApplication app(argc, argv);
    MainWindow *w;
    int ris;

    /* Now, we create the custom widget 'w', and we start the events loop! */
    w = new MainWindow();
    w->resize(650,100);
    w->setWindowTitle("Example_0016 - Basic Example for the FlowLayout");
    QObject::connect(w,SIGNAL(quit_required()),&app,SLOT(quit()));
    QObject::connect(w,SIGNAL(qtinfo_required()),&app,SLOT(aboutQt()));
    w->show();
    ris=app.exec();
    delete w;
    w = NULL;
    return EXIT_SUCCESS;
}
