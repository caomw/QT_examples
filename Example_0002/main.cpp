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
#include <QFile>
#include<iostream>
using namespace std;

/* No parameter is required! */
int main(int argc,char **argv)
{
    QTextStream out(stdout);
    QString a="example of string in the",str1,str2,str3,str4,str5;
    string s1,s2;
    char s3[]="arrays of characters";
    int n,v0,v1,digits=0,letters=0,spaces=0,puncts=0;
    double h;
    QStringRef suba;
    QFile file;

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

    /* Seventh test: looping on characters of strings! */
    out<<"\tCurrent string: '"<<a<<"'"<<endl;
    out<<"\tEnumerating its characters (with 'foreach'): ";
    foreach (QChar qc, a) { out <<"'"<< qc <<"'"<<" "; }
    out<<endl<<"\tEnumerating its characters (with 'C++-like' iterators): ";
    for (QChar *it=a.begin(); it!=a.end(); ++it) { out <<"'"<< (*it) <<"'"<<" "; }
    out<<endl<<"\tEnumerating its characters (with indices): ";
    for(unsigned int i=0;i<a.size();i++) { out <<"'"<< a.at(i) <<"'"<<" "; }
    out<<endl<<endl;

    /* Eighth test: comparing strings! */
    str1 = QString("Rainfall");
    str2 = QString("rainfall");
    str3 = QString("rainfall\n");
    out<<"\tFirst string 's0' to be compared: '"<<str1<<"'"<<endl;
    out<<"\tSecond string 's1' to be compared: '"<<str2<<"'"<<endl;
    out<<"\tThird string 's2' to be compared (with EOL): '"<<str3<<"'"<<endl;
    if(QString::compare(str1,str2)==0) out<<"\tStrings 's0' and 's1' coincide (with respect to case sensitive comparisons)"<<endl;
    else out<<"\tStrings 's0' and 's1' do not coincide (with respect to case sensitive comparisons)"<<endl;
    if(QString::compare(str1,str2,Qt::CaseInsensitive)==0) out<<"\tStrings 's0' and 's1' coincide (with respect to case insensitive comparisons)"<<endl;
    else out<<"\tStrings 's0' and 's1' do not coincide (with respect to case insensitive comparisons)"<<endl;
    if(QString::compare(str2,str3)==0) out<<"\tStrings 's1' and 's2' coincide (with respect to case sensitive comparisons)"<<endl;
    else out<<"\tStrings 's1' and 's2' do not coincide (with respect to case sensitive comparisons)"<<endl;
    if(QString::compare(str2,str3,Qt::CaseInsensitive)==0) out<<"\tStrings 's1' and 's2' coincide (with respect to case insensitive comparisons)"<<endl<<endl;
    else out<<"\tStrings 's1' and 's2' do not coincide (with respect to case insensitive comparisons)"<<endl<<endl;
    out<<"\tRemoving EOL from string 's2' ... ";
    str3.chop(1);
    out<<"ok. Resulting string: '"<<str3<<"'"<<endl;
    if(QString::compare(str2,str3)==0) out<<"\tStrings 's1' and 's2' coincide (with respect to case sensitive comparisons)"<<endl;
    else out<<"\tStrings 's1' and 's2' do not coincide (with respect to case sensitive comparisons)"<<endl;
    if(QString::compare(str2,str3,Qt::CaseInsensitive)==0) out<<"\tStrings 's1' and 's2' coincide (with respect to case insensitive comparisons)"<<endl<<endl;
    else out<<"\tStrings 's1' and 's2' do not coincide (with respect to case insensitive comparisons)"<<endl<<endl;

    /* Ninth test: converting string as 'int' and 'double' value! */
    str1=QString("25");
    str2=QString("10");
    out<<"\tString 's0': '"<<str1<<"'"<<endl;
    out<<"\tString 's1': '"<<str2<<"'"<<endl;
    v0=str1.toInt();
    v1=str2.toInt();
    out<<"\tString 's0', converted as 'int': "<<v0<<endl;
    out<<"\tString 's1', converted as 'int': "<<v1<<endl;
    out<<"\tSum of these 'int' values: "<<(v0+v1)<<endl;
    str3.setNum(v0);
    a.setNum(v1);
    out<<"\tConversion back to string '"<<str3<<"'"<<endl;
    out<<"\tConversion back to string '"<<a<<"'"<<endl;
    out<<"\tConcatenating these two strings: '"<<(str3+a)<<"'"<<endl<<endl;

    /* Tenth test: classifying characters in a string! */
    a="We have 8 apples, 6 oranges, and 8 lemons";
    out<<"\tCurrent string: '"<<a<<"'"<<endl;
    foreach(QChar c,a)
    {
        if(c.isDigit()) { digits++; }
        else if(c.isLetter()) { letters++; }
        else if(c.isSpace()) { spaces++; }
        else if (c.isPunct()) { puncts++; }
    }

    out << QString("\tTotal number of characters: %1").arg(a.count()) << endl;
    out << QString("\tTotal number of digits: %1").arg(digits) << endl;
    out << QString("\tTotal number of spaces: %1").arg(spaces) << endl;
    out << QString("\tTotal number of punctuation characters: %1").arg(puncts) << endl;
    out << QString("\tTotal number of letters: %1").arg(letters) << endl<<endl;

    /* Eleventh test: converting a plain text string to an HTML string with HTML metacharacters <, >, &, and " replaced by HTML named entities */
    out<<"\tOpen auxiliary file 'cprog.c', containing HTML metacharacters <, >, &, ... ";
    file.setFileName("cprog.c");
    if (!file.open(QIODevice::ReadOnly))
    {
        qWarning("\tCannot open file 'cprog.c' for reading");
        return EXIT_FAILURE;
    }
    else
    {
        out<<"ok"<<endl<<"\tContent:"<<endl<<endl;

        QTextStream in(&file);
        QString allText = in.readAll();

        out<<allText<<"\tReplacing HTML metacharacters with HTML named entities ... ";
        str3=allText.toHtmlEscaped();
        out<<"ok. Result: "<<endl<<endl<<str3;
        file.close();
    }

    /* Twelveth test: align strings to the left! */
    a="Name: ";
    str1="Degree: ";
    str2="Interests: ";
    str3="Residence: ";
    str4="Job: ";
    n=str3.size();
    out<<"\t"<<a.leftJustified(n,' ')<<"David Canino"<<endl;
    out<<"\t"<<str1.leftJustified(n,' ')<<"Computer Science, Programming"<<endl;
    out<<"\t"<<str2.leftJustified(n,' ')<<"Noli (SV), Italy"<<endl;
    out<<"\t"<<str3.leftJustified(n,' ')<<"Looking for a new job"<<endl<<endl;

    return EXIT_SUCCESS;
}
