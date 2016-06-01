/*************************************************************************************************************************
 * David Canino - canino.david@gmail.com
 *
 * Basic examples for the QT Library
 * Github: https://github.com/davidcanino/QT_examples.git
 *
 * An other GUI example for the Signal & Slot mechanism in the current QT Library. No parameter is required.
 *
 * Last update: June 2016
 *************************************************************************************************************************/

#include "widget.h"
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
    Widget w;
    int ris;

    /* Now, we create the custom widget 'w', and we start the events loop! */
    w.resize(650,100);
    w.setWindowTitle("Example_0010 - An other GUI example about the Signal & Slot mechanism");
    QObject::connect(&w,SIGNAL(clickedOnQuitButton()),&app,SLOT(quit()));
    QObject::connect(&w,SIGNAL(clickedOnInfoButton()),&app,SLOT(aboutQt()));
    w.show();
    ris=app.exec();
    return EXIT_SUCCESS;
}
