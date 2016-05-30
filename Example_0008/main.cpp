/*************************************************************************************************************************
 * David Canino - canino.david@gmail.com
 *
 * Basic examples for the QT Library
 * Github: https://github.com/davidcanino/QT_examples.git
 *
 * This is the basic example for the Signal & Slot mechanism in the current QT Library. No parameter is required.
 *
 * Last update: May 2016
 *************************************************************************************************************************/

#include<iostream>
#include<cstdlib>
#include<QtCore>
using namespace std;

class Counter : public QObject
{
    Q_OBJECT

    public:

    inline Counter() { this->mvalue=0; }

    virtual ~Counter() { ; }

    int value() { return this->mvalue; }

    public slots:

    inline void setValue(int val)
    {
        if(val!=this->mvalue)
        {
            this->mvalue=val;
            emit valueChanged(val);
        }
    }

    signals:

        void valueChanged(int nvalue);

    private:

    int mvalue;
};

/* No parameter is required! */
int main(int argc,char **argv)
{
    Counter a,b;

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

    /* Initializing without signal & slot! */
    cout<<"\tInitializing counters without enabling the signals and slot mechanism ... ";
    a.setValue(5);
    b.setValue(2);
    cout<<"ok"<<endl;
    cout<<"\tCounter 'a': "<<a.value()<<endl;
    cout<<"\tCounter 'b': "<<b.value()<<endl<<endl;

    /* Connecting signal 'valueChanged' and slot 'setValue' from 'a' to 'b' */
    cout<<"\tConnecting the signal 'valueChanged' for counter 'a' with the slot 'setValue' on counter 'b' ... ";
    QObject::connect(&a,&Counter::valueChanged,&b,&Counter::setValue);
    cout<<"ok"<<endl;
    cout<<"\tSetting value 14 for counter 'a' ... ";
    a.setValue(14);
    cout<<"ok"<<endl;
    cout<<"\tCounter 'a': "<<a.value()<<endl;
    cout<<"\tCounter 'b': "<<b.value()<<endl<<endl;

    /* No propagation from 'b' to 'a' */
    cout<<"\tSetting value 26 for counter 'b' ... ";
    b.setValue(26);
    cout<<"ok"<<endl;
    cout<<"\tCounter 'a': "<<a.value()<<endl;
    cout<<"\tCounter 'b': "<<b.value()<<endl<<endl;

    /* Connecting signal 'valueChanged' and slot 'setValue' from 'b' to 'a' (reverse connection) */
    cout<<"\tConnecting the signal 'valueChanged' for counter 'b' with the slot 'setValue' on counter 'a' (reverse connection) ... ";
    QObject::connect(&b,SIGNAL(valueChanged(int)),&a,SLOT(setValue(int)));
    cout<<"ok"<<endl;
    cout<<"\tSetting value 66 for counter 'b' ... ";
    b.setValue(66);
    cout<<"ok"<<endl;
    cout<<"\tCounter 'a': "<<a.value()<<endl;
    cout<<"\tCounter 'b': "<<b.value()<<endl<<endl;

    /* Disconnecting the emission of signal 'valueChanged' from counter 'b' */
    cout<<"\tDisconnecting the emission of signal 'valueChanged' from counter 'b' (no more connection with 'a') ... ";
    b.disconnect(SIGNAL(valueChanged(int)));
    cout<<"ok"<<endl;
    cout<<"\tSetting value 45 for counter 'b' ... ";
    b.setValue(45);
    cout<<"ok"<<endl;
    cout<<"\tCounter 'a': "<<a.value()<<endl;
    cout<<"\tCounter 'b': "<<b.value()<<endl<<endl;
    cout<<"\tSetting value 75 for counter 'a' ... ";
    a.setValue(75);
    cout<<"ok"<<endl;
    cout<<"\tCounter 'a': "<<a.value()<<endl;
    cout<<"\tCounter 'b': "<<b.value()<<endl<<endl;
    cout<<"\tDisconnecting the emission of signal 'valueChanged' from counter 'a' (no more connection with 'b') ... ";
    a.disconnect(SIGNAL(valueChanged(int)));
    cout<<"ok"<<endl;
    cout<<"\tSetting value 97 for counter 'a' ... ";
    b.setValue(97);
    cout<<"ok"<<endl;
    cout<<"\tCounter 'a': "<<a.value()<<endl;
    cout<<"\tCounter 'b': "<<b.value()<<endl<<endl;

    return EXIT_SUCCESS;
}

/* If we have all in 'main.cpp', then this line is mandatory! */
#include "main.moc"
