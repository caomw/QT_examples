/*************************************************************************************************************************
 * David Canino - canino.david@gmail.com
 *
 * Basic examples for the QT Library
 * Github: https://github.com/davidcanino/QT_examples.git
 *
 * This is the basic example about GUI programs. No parameter is required.
 *
 * Last update: May 2016
 *************************************************************************************************************************/

#include <cstdlib>
#include <iostream>
#include <QApplication>
#include <QWidget>
using namespace std;

/* No parameter is required! */
int main(int argc,char **argv)
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

    QApplication app(argc,argv);
    QWidget window;
    int ris;

    window.resize(500,150);
    window.setWindowTitle("Example_0006 - First example of the GUI programs in the QT Library");
    window.setToolTipDuration(1500);
    window.setToolTip("Example of the Main Window");
    window.show();
    ris = app.exec();
    return EXIT_SUCCESS;
}
