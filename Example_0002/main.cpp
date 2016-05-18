/*************************************************************************************************************************
 * David Canino - canino.david@gmail.com
 *
 * Basic examples for the QT Library
 * Github: https://github.com/davidcanino/QT_examples.git
 *
 * This is the basic example for manipulating strings (QString) of the current QT Library. No parameter is required.
 *
 * Last update: May 2016
 *************************************************************************************************************************/

#include<cstdlib>
#include<string>
#include<QString>
#include <QTextStream>
#include<iostream>
using namespace std;

/* No parameter is required! */
int main(int argc,char **argv)
{
    QTextStream out(stdout);
    QString a="example of string in the",str1,str2,str3,str4,str5;
    string s1,s2;
    char s3[]="arrays of characters";
    int n;
    double h;
    QStringRef suba;

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

    /* First test: writing strings! */
    out<<"\tInitial string: '"<<a<<"'"<<endl;
    a.append(" QT Library");
    out<<"\tString after append operation: '"<<a<<"'"<<endl;
    a.prepend("First ");
    out<<"\tString after prepend operation: '"<<a<<"'"<<endl;
    out<<"\tNumber of characters: "<<a.count()<<endl<<endl;
    out<<"\ttoUpper version: '"<<a.toUpper()<<"'"<<endl;
    out<<"\ttoLower version: '"<<a.toLower()<<"'"<<endl;
    out<<"\tCurrent string: '"<<a<<"'"<<endl<<endl;

    /* Second test: initialization methods! */
    str1 = "direct initialization";
    out<<"\tFirst initialization method: '"<<str1<<"'"<<endl;
    str2 = QString("initialization during the explicit creation");
    out<<"\tSecond initialization method: '"<<str2<<"'"<<endl;
    s1=string("initialization from any standard C++ string (without conversion)");
    str3=s1.c_str();
    out<<"\tThird initialization method: '"<<str3<<"'"<<endl;
    s2=string("initialization from any standard C++ string (with conversion from Latin1)");
    str4=QString::fromLatin1(s2.data(),s2.size());
    out<<"\tFourth initialization method: '"<<str4<<"'"<<endl;
    str5=QString(s3);
    out<<"\tFifth initialization method: '"<<str5<<"'"<<endl<<endl;

    /* Third test: accessing string elements! */
    a="example of string";
    out<<"\tCurrent string: '"<<a<<"'"<<endl;
    out<<"\tCharacter in position 0: '"<<a[0]<<"'"<<endl;
    out<<"\tCharacter in position 8: '"<<a[8]<<"'"<<endl;
    out<<"\tUpdating character in position 0 ... ";
    a[0]='E';
    out<<"ok"<<endl;
    out<<"\tNew character in position 0: '"<<a[0]<<"'"<<endl;
    out<<"\tNew string: '"<<a<<"'"<<endl<<endl;

    /* Fourth test: retrieving number of elements! */
    str1 = "Eagle";
    str2 = "Eagle\n";
    str3="Eagle ";
    str4="орел";
    out<<"\tCurrent string: '"<<str1<<"'"<<endl;
    out<<"\tNumber of elements (see the 'QString::length()' member function): "<<str1.length()<<endl;
    out<<"\tNumber of elements (see the 'QString::size()' member function): "<<str1.size()<<endl;
    out<<"\tNumber of elements (see the 'QString::count()' member function): "<<str1.count()<<endl<<endl;
    out<<"\tCurrent string (including EOL): '"<<str2<<"'"<<endl;
    out<<"\tNumber of elements (see the 'QString::length()' member function): "<<str2.length()<<endl;
    out<<"\tNumber of elements (see the 'QString::size()' member function): "<<str2.size()<<endl;
    out<<"\tNumber of elements (see the 'QString::count()' member function): "<<str2.count()<<endl<<endl;
    out<<"\tCurrent string (including white spaces): '"<<str3<<"'"<<endl;
    out<<"\tNumber of elements (see the 'QString::length()' member function): "<<str3.length()<<endl;
    out<<"\tNumber of elements (see the 'QString::size()' member function): "<<str3.size()<<endl;
    out<<"\tNumber of elements (see the 'QString::count()' member function): "<<str3.count()<<endl<<endl;
    out<<"\tCurrent string (with not standard characters): '"<<str4<<"'"<<endl;
    out<<"\tNumber of elements (see the 'QString::length()' member function): "<<str4.length()<<endl;
    out<<"\tNumber of elements (see the 'QString::size()' member function): "<<str4.size()<<endl;
    out<<"\tNumber of elements (see the 'QString::count()' member function): "<<str4.count()<<endl<<endl;

    /* Fifth test: replacing specific control characters! */
    str1="Example for replacing specific control characters - here, we have %1 control character to be replaced";
    out<<"\tGeneric pattern #1: '"<<str1<<"'"<<endl;
    n=1;
    out<<"\tAfter replacing control character: '"<<str1.arg(n)<<"'"<<endl<<endl;
    str2="Example for replacing specific control characters - the most common approximation of pi is %1";
    out<<"\tGeneric pattern #2: '"<<str2<<"'"<<endl;
    h=3.14;
    out<<"\tAfter replacing control character: '"<<str2.arg(h)<<"'"<<endl<<endl;
    str3="There are at least %1 interesting constant values in mathematics, namely e=%2 and pi=%3";
    out<<"\tGeneric pattern #3: '"<<str3<<"'"<<endl;
    out<<"\tAfter replacing control characters: '"<<str3.arg(2).arg(2.78).arg(3.14)<<"'"<<endl<<endl;

    /* Sixth test: manipulating substrings! */
    a.append(" in the QT Library");
    out<<"\tCurrent string: '"<<a<<"'"<<endl;
    out<<"\tSubstring, formed by last 5 characters (see the 'QString::right()' member function): '"<<a.right(5)<<"'"<<endl;
    out<<"\tSubstring, formed by first 9 characters (see the 'QString::left()' member function): '"<<a.left(9)<<"'"<<endl;
    out<<"\tSubstring, formed by 7 characters (starting from position 10, see the 'QString::mid()' member function): '"<<a.mid(7,10)<<"'"<<endl;
    suba=QStringRef(&a,0,8);
    out<<"\tSubstring, formed by first 8 characters (see the 'QStringRef' class): '"<<suba.toString()<<"'"<<endl<<endl;


    return EXIT_SUCCESS;
}

