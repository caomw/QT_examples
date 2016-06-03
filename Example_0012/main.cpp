/*************************************************************************************************************************
 * David Canino - canino.david@gmail.com
 *
 * Basic examples for the QT Library
 * Github: https://github.com/davidcanino/QT_examples.git
 *
 * Basic GUI example for menu and layouts. No parameter is required.
 *
 * Last update: June 2016
 *************************************************************************************************************************/

#include "customdialog.h"
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
    CustomDialog w;
    int ris;

    /* Now, we create the custom widget 'w', and we start the events loop! */
    w.resize(500,100);
    w.setWindowTitle("Example_0012 - Basic GUI example for menu and layouts");
    QObject::connect(&w,SIGNAL(required_qt_info()),&app,SLOT(aboutQt()));
    w.show();
    ris=app.exec();
    return EXIT_SUCCESS;
}
