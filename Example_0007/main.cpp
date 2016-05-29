/*************************************************************************************************************************
 * David Canino - canino.david@gmail.com
 *
 * Basic examples for the QT Library
 * Github: https://github.com/davidcanino/QT_examples.git
 *
 * Another basic example for QWidgets. No parameter is required.
 *
 * Last update: May 2016
 *************************************************************************************************************************/

#include "customwidget.h"
#include <QApplication>
#include <iostream>
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
    CustomWidget w;
    int ris;

    /* Now, we create the custom widget 'w', and we start the events loop! */
    w.resize(550,100);
    w.setWindowTitle("Example_0007 - the basic example about the grid layout, cursors, and panels");
    w.show();
    ris=app.exec();
    return EXIT_SUCCESS;
}

