/*************************************************************************************************************************
 * David Canino - canino.david@gmail.com
 *
 * Basic examples for the QT Library
 * Github: https://github.com/davidcanino/QT_examples.git
 *
 * This is the basic example for manipulating several containers in the current QT Library. No parameter is required.
 *
 * Last update: May 2016
 *************************************************************************************************************************/

#include<cstdlib>
#include<iostream>
#include <QVector>
#include <QTextStream>
#include <QList>
#include <algorithm>
#include <QString>
#include <QStringList>
#include <QSet>
#include <QMap>
using namespace std;

/* No parameter is required! */
int main(int argc,char **argv)
{
    QTextStream out(stdout);
    QVector<int> vals = {1, 2, 3, 4, 5};
    int pos;
    QList<QString> authors = {"Torvalds","Harrison","Minsky","Brown","Lovecraft"};
    QStringList fonts,res;
    QString ss;
    QList<int> aux;

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

    /*********************************************************************** TESTING QVector ****************************************************/

    out<<"\tThe current 'QVector'' is initialized"<<endl;
    out<<"\tNumber of values in the current 'QVector': "<<vals.size()<<endl;
    out<<"\tCapacity of the current 'QVector': "<<vals.capacity()<<endl;
    out<<"\tFirst value in the current 'QVector': "<<vals.first()<<endl;
    out<<"\tLast value in the current 'QVector': "<<vals.last()<<endl;
    out<<"\tValues in the current 'QVector': ";
    for(int i=0;i<vals.count();i++) out<<vals.at(i)<<" ";
    out<<endl;
    out<<"\tAppending new value to the current 'QVector' ... ";
    vals.append(6);
    out<<"ok"<<endl;
    out<<"\tPrepending new value to the current 'QVector' ... ";
    vals.prepend(0);
    out<<"ok"<<endl;
    out<<"\tValues in the current 'QVector': ";
    Q_FOREACH(int v,vals) { out<<v<<" "; }
    out<<endl;
    out<<"\tValues (in reverse order) in the current 'QVector': ";
    for(QVector<int>::reverse_iterator it=vals.rbegin();it!=vals.rend();it++) { out<<(*it)<<" "; }
    out<<endl<<endl;
    if(vals.isEmpty()) out<<"\tThe current 'QVector' is empty"<<endl;
    else out<<"\tThe current 'QVector' is not empty"<<endl;
    out<<"\tNumber of values in the current 'QVector': "<<vals.size()<<endl;
    out<<"\tAdding value 20 in position 7 to the current 'QVector' ... ";
    vals.insert(7,20);
    out<<"ok"<<endl;
    out<<"\tValue in position 7 in the current 'QVector': "<<vals.value(7)<<endl;
    out<<"\tNumber of values in the current 'QVector': "<<vals.size()<<endl;
    out<<"\tValues in the current 'QVector': ";
    for(QVector<int>::iterator it=vals.begin();it!=vals.end();it++) { out<<(*it)<<" "; }
    out<<endl<<endl;
    out<<"\tResizing the number of values in the current 'QVector' ... ";
    vals.resize(10);
    out<<"ok"<<endl;
    out<<"\tNumber of values in the current 'QVector': "<<vals.size()<<endl;
    out<<"\tAppending new values to the current 'QVector' ... ";
    vals<<11;
    vals<<12;
    vals<<13;
    vals<<14;
    out<<"ok"<<endl<<"\tNumber of values in the current 'QVector': "<<vals.size()<<endl;
    out<<"\tValues in the current 'QVector': ";
    for(QVector<int>::iterator it=vals.begin();it!=vals.end();it++) { out<<(*it)<<" "; }
    out<<endl<<endl;
    pos=vals.indexOf(20);
    if(pos!=-1)
    {
        out<<"\tValue 20 is stored in position "<<pos<<" in the current 'QVector'"<<endl;
        out<<"\tRemoving value "<<vals.takeAt(pos)<<" in position "<<pos<<" from the current 'QVector' ... ok"<<endl;
        out<<"\tNumber of values in the current 'QVector': "<<vals.size()<<endl;
        out<<"\tValues in the current 'QVector': ";
        for(QVector<int>::iterator it=vals.begin();it!=vals.end();it++) { out<<(*it)<<" "; }
        out<<endl;
    }
    else out<<"\tValue 20 is not stored"<<endl<<endl;
    out<<"\tRemoving the last value from the current 'QVector' ... ";
    vals.pop_back();
    out<<"ok"<<endl;
    out<<"\tNumber of values in the current 'QVector': "<<vals.size()<<endl;
    out<<"\tRemoving the first value from the current 'QVector' ... ";
    vals.pop_front();
    out<<"ok"<<endl;
    out<<"\tNumber of values in the current 'QVector': "<<vals.size()<<endl<<endl;
    for(int k=vals.size()-1;k>5;k--)
    {
        out<<"\tRemoving value in position "<<k<<" from the current 'QVector' ... ";
        vals.erase(vals.begin()+k);
        out<<"ok. #Number of values in the current 'QVector': "<<vals.length()<<endl;
    }

    out<<"\tValues in the current 'QVector': ";
    for(QVector<int>::iterator it=vals.begin();it!=vals.end();it++) { out<<(*it)<<" "; }
    out<<endl;
    out<<"\tHashing value for the remaining values in the current 'QVector': "<<qHash(vals)<<endl<<endl;
    out<<"\tRemoving all values from the current 'QVector' ... ";
    vals.clear();
    out<<"ok. ";
    if(vals.empty()) out<<"The current 'QVector' is empty"<<endl<<endl;
    else out<<"The current 'QVector' is not empty"<<endl<<endl;
    out<<"\tPress the RETURN key to continue"<<endl;
    getchar();

    /************************************** END FOR TESTING for 'QVector' **********************************************************/

    /************************************** START TESTING for 'QList' **************************************************************/

    out<<"\tThe current 'QList'' is initialized"<<endl;
    out<<"\tNumber of values in the current 'QList': "<<authors.size()<<endl;
    out<<"\tFirst value in the current 'QList': '"<<authors.first()<<"'"<<endl;
    out<<"\tLast value in the current 'QList': "<<authors.last()<<"'"<<endl;
    out<<"\tValues in the current 'QList':"<<endl<<endl;
    for(int i=0;i<authors.count();i++) out<<"\t\t'"<<authors.at(i)<<"'"<<endl;
    out<<endl;
    out<<"\tAppending a new value to the current 'QList' ... ";
    authors.append("Asimov");
    out<<"ok"<<endl;
    out<<"\tPrepending a new value to the current 'QList' ... ";
    authors.prepend("Kishimoto");
    out<<"ok"<<endl;
    out<<"\tNumber of values in the current 'QList': "<<authors.size()<<endl;
    out<<"\tSorting values in the current 'QList' ... ";
    std::sort(authors.begin(),authors.end());
    out<<"ok"<<endl;
    out<<"\tNumber of values in the current 'QList': "<<authors.size()<<endl;
    out<<"\tValues in the current 'QList':"<<endl<<endl;
    foreach(QString s,authors) out<<"\t\t'"<<s<<"'"<<endl;
    out<<endl;
    out<<"\tConcatenating another value to the current 'QList' ... ";
    authors<<"Hardy";
    out<<"ok"<<endl;
    out<<"\tNumber of values in the current 'QList': "<<authors.size()<<endl;
    out<<"\tValues in the current 'QList' (in reverse order):"<<endl<<endl;
    for(QList<QString>::reverse_iterator it=authors.rbegin();it!=authors.rend();it++) out<<"\t\t'"<<(*it)<<"'"<<endl;
    out<<endl;
    out<<"\tRemoving value '"<<authors.at(4)<<"', stored in position 4 ... ";
    authors.removeAt(4);
    out<<"ok"<<endl;
    out<<"\tNumber of values in the current 'QList': "<<authors.size()<<endl;
    out<<"\tRemoving the first value '"<<authors.takeFirst()<<"' ... ok"<<endl;
    out<<"\tNumber of values in the current 'QList': "<<authors.size()<<endl;
    out<<"\tRemoving the last value '"<<authors.takeLast()<<"' ... ok"<<endl;
    out<<"\tNumber of values in the current 'QList': "<<authors.size()<<endl<<endl;
    Q_FOREACH(QString s,authors) out<<"\t\t'"<<s<<"'"<<endl;
    out<<endl;
    out<<"\tHashing value for the current 'QList': "<<qHash(authors)<<endl<<endl;
    out<<"\tRemoving all values from the current 'QList' ... ";
    authors.clear();
    out<<"ok. ";
    if(authors.empty()) out<<"The current 'QList' is empty"<<endl<<endl;
    else out<<"The current 'QList' is not empty"<<endl<<endl;
    out<<"\tPress the RETURN key to continue"<<endl;
    getchar();

    /************************************** END TESTING for 'QList' ****************************************************************/

    /************************************** TESTING 'QStringList '******************************************************************/
    fonts << "Arial" << "Helvetica" << "Times" << "Courier";
    fonts.append("Courier New");
    out<<"\tThe current 'QStringList' is initialized"<<endl<<endl;
    for (int i = 0; i < fonts.size(); ++i) { out << "\t\t'"<<fonts.at(i).toLocal8Bit().constData() << "'"<<endl; }
    out<<endl;
    out<<"\tJoining all strings into a unique string ... ";
    ss = fonts.join(", ");
    out<<"ok"<<endl;
    out<<"\tUnique string: '"<<ss<<"'"<<endl<<endl;
    out<<"\tClearing the current 'QStringList' ... ";
    fonts.clear();
    out<<"ok"<<endl;
    if(fonts.isEmpty()) out<<"\tThe current 'QStringList' is empty"<<endl;
    else out<<"\tThe current 'QStringList' is not empty"<<endl<<endl;
    out<<"\tSplitting the unique string into a collection of substrings ... ";
    fonts = ss.split(',', QString::SkipEmptyParts);
    out<<"ok. Found "<<fonts.size()<<" substrings."<<endl<<endl;
    for(QStringList::const_iterator it=fonts.constBegin();it!=fonts.constEnd();it++) { out<<"\t\t'"<<(it->trimmed())<<"'"<<endl; }
    out<<endl;
    out<<"\tLooking for strings, containing either the 'Courier' string or the 'Fixed' string ... ";
    res=fonts.filter(QRegExp("Courier|Fixed"));
    out<<"ok. Found ";
    if(res.count()==0) out<<"no result."<<endl<<endl;
    else
    {
        QStringListIterator it(res);

        if(res.length()==1) out<<"only one result:"<<endl<<endl;
        else out<<res.size()<<" results:"<<endl<<endl;
        while(it.hasNext()) { out<<"\t\t'"<<it.next().trimmed()<<"'"<<endl; }
        out<<endl;
    }

    out<<"\tCreating a collection of strings (paths) to be completed ... ";
    res.clear();
    res<< "$QTDIR/src/moc/moc.y"<< "$QTDIR/src/moc/moc.l"<< "$QTDIR/include/qconfig.h";
    out<<"ok"<<endl<<endl;

    QStringListIterator it(res);

    while(it.hasNext()) { out<<"\t\t'"<<it.next().trimmed()<<"'"<<endl; }
    out<<endl<<"\tReplacing $QTDIR as '/usr/lib/qt' .. ";
    res.replaceInStrings("$QTDIR", "/usr/lib/qt");
    out<<"ok"<<endl<<endl;
    for(QStringList::const_iterator it=res.constBegin();it!=res.constEnd();it++) { out<<"\t\t'"<<(it->trimmed())<<"'"<<endl; }
    out<<endl;
    out<<"\tPress the RETURN key to continue"<<endl;
    getchar();

    /************************************** END TESTING for 'QStringList' **********************************************************/

    /************************************** TESTING 'QSet' *************************************************************************/

    QSet<QString> qss,qss1,qss2;

    out<<"\tAdding several element to the current 'QSet' ... ";
    qss.insert("one");
    qss.insert("three");
    qss.insert("seven");
    qss << "twelve" << "fifteen" << "nineteen";
    out<<"ok. Found not sorted "<<qss.size()<<" elements:"<<endl<<endl;
    foreach (const QString &v, qss) out<<"\t\t'"<<v<<"'"<<endl;
    out<<endl;
    authors.clear();
    authors=qss.values();
    std::sort(authors.begin(),authors.end());
    out<<"\tFound sorted "<<authors.size()<<" elements"<<endl<<endl;
    for(QList<QString>::iterator it=authors.begin();it!=authors.end();it++) out<<"\t\t'"<<(*it)<<"'"<<endl;
    out<<endl;
    authors.clear();
    qss.clear();
    out<<"\tInitializing two 'QSet' objects ... ";
    qss1={"yellow", "red", "blue"};
    qss1.insert("brown");
    qss2={"blue", "pink", "orange"};
    out<<"ok"<<endl<<endl;
    out<<"\tFound "<<qss1.count()<<" elements in the first 'QSet' object: "<<endl<<endl;
    for(QSet<QString>::iterator it=qss1.begin();it!=qss1.end();it++) out<<"\t\t'"<<(*it)<<"'"<<endl;
    out<<endl;
    if(qss1.contains("brown")==true) out<<"\tThe first 'QSet' object contains the element 'brown'"<<endl;
    else out<<"\tThe first 'QSet' object does not contain the element 'brown'"<<endl;
    out<<endl<<"\tFound "<<qss2.count()<<" elements in the second 'QSet' object: "<<endl<<endl;
    for(QSet<QString>::iterator it=qss2.begin();it!=qss2.end();it++) out<<"\t\t'"<<(*it)<<"'"<<endl;
    qss=QSet<QString>::fromList(qss1.values());
    if(qss2.contains("brown")==true) out<<endl<<"\tThe second 'QSet' object contains the element 'brown'"<<endl;
    else out<<endl<<"\tThe second 'QSet' object does not contain the element 'brown'"<<endl;
    out<<endl<<"\tComputing the intersection of two 'QSet' objects ... ";
    qss.intersect(qss2);
    out<<"ok. Found ";
    if(qss.count()==0) out<<" no common element"<<endl<<endl;
    else
    {
        if(qss.size()==1) out<<"only one common element:"<<endl<<endl;
        else out<<"\t"<<qss.size()<<" common elements:"<<endl<<endl;
        for(QSet<QString>::iterator it=qss.begin();it!=qss.end();it++) out<<"\t\t'"<<(*it)<<"'"<<endl;
        out<<endl;
    }

    qss=QSet<QString>::fromList(qss1.values());
    out<<"\tComputing the union of two 'QSet' objects ... ";
    qss.unite(qss2);
    out<<"ok. Found ";
    if(qss.count()==0) out<<" no common element"<<endl<<endl;
    else
    {
        if(qss.size()==1) out<<"only one common element:"<<endl<<endl;
        else out<<qss.size()<<" common elements:"<<endl<<endl;
        for(QSet<QString>::iterator it=qss.begin();it!=qss.end();it++) out<<"\t\t'"<<(*it)<<"'"<<endl;
        out<<endl;
    }

    if(qss1.remove("red")==true) out<<"\tRemoved element 'red' correctly from the first 'QSet' object"<<endl<<endl;
    else out<<"\tImpossible to remove element 'red' from the first 'QSet' object"<<endl<<endl;
    if(qss2.remove("red")==true) out<<"\tRemoved element 'red' correctly from the second 'QSet' object"<<endl<<endl;
    else out<<"\tImpossible to remove element 'red' from the second 'QSet' object"<<endl<<endl;
    out<<"\tPress the RETURN key to continue"<<endl;
    getchar();

    /************************************** END TESTING 'QSet' *********************************************************************/

    /************************************** TESTING 'QMap' ************************************************************************/

    QMap<QString, int> map;
    QMap<QString, int>::const_iterator i;

    map["one"] = 1;
    map["three"] = 3;
    map["seven"] = 7;
    map.insert("twelve", 12);
    out<<"\tCreated new 'QMap' object with "<<map.size()<<" associations: "<<endl<<endl;
    i = map.constBegin();
    while(i != map.constEnd())
    {
        out<<"\t\tassociation '"<<i.key()<<"'' <-> "<<i.value()<<endl;
        ++i;
    }

    out<<endl<<"\tLooking up for a not existing association (with modifying operator []) in the current 'QMap' object ... ";
    pos = map["five"];
    out<<"ok. Found "<<map.size()<<" associations in the current 'QMap' object."<<endl;
    out<<"\tCreated new association in the current 'QMap' object, involving the key 'five' and the default value "<<pos<<endl<<endl;
    i = map.constBegin();
    while(i != map.constEnd())
    {
        out<<"\t\tassociation '"<<i.key()<<"' <-> "<<i.value()<<endl;
        ++i;
    }

    out<<endl<<"\tLooking up for a not existing association (with not modifying function) in the current 'QMap' object ... ";
    pos=map.value("thirty");
    out<<"ok. Found still "<<map.size()<<" associations in the current 'QMap' object."<<endl<<endl;
    out<<"\tAdding two associations, involving the same key 'plenty' (without support for multiple associations), in the current 'QMap' object ... ";
    map.insert("plenty", 100);
    map.insert("plenty", 2000);
    aux.clear();
    aux=map.values("plenty");
    out<<"ok. Found ";
    if(aux.size()==0) { out<<" no association, involving the key 'plenty' in the current 'QMap' object"<<endl<<endl; }
    else
    {
        if(aux.size()==1) { out<<" only one association, involving the key 'plenty' in the current 'QMap' object:"<<endl<<endl; }
        else { out<<aux.size()<<" associations, involving the key 'plenty':"<<endl<<endl; }
        for(QList<int>::iterator aa=aux.begin();aa!=aux.end();aa++) { out<<"\t\tassociation 'plenty' <-> "<<(*aa)<<endl; }
        out<<endl;
    }

    out<<"\tFound "<<map.size()<<" associations in the current 'QMap' object:"<<endl<<endl;
    i = map.constBegin();
    while(i != map.constEnd())
    {
        out<<"\t\tassociation '"<<i.key()<<"' <-> "<<i.value()<<endl;
        ++i;
    }

    out<<endl<<"\tAdding two associations, involving the same key 'multi' (with support for multiple associations), in the current 'QMap' object ... ";
    map.insertMulti("multi", 7);
    map.insertMulti("multi", 5000);
    aux.clear();
    aux=map.values("multi");
    out<<"ok. Found ";
    if(aux.size()==0) { out<<" no association, involving the key 'multi' in the current 'QMap' object"<<endl<<endl; }
    else
    {
        if(aux.size()==1) { out<<" only one association, involving the key 'multi':"<<endl<<endl; }
        else { out<<aux.size()<<" associations, involving the key 'multi':"<<endl<<endl; }
        for(QList<int>::iterator aa=aux.begin();aa!=aux.end();aa++) { out<<"\t\tassociation 'multi' <-> "<<(*aa)<<endl; }
        out<<endl;
    }

    out<<"\tFound "<<map.size()<<" associations and ";
    authors.clear();
    authors=map.uniqueKeys();
    out<<authors.size()<<" unique keys in the current 'QMap' object"<<endl<<endl;
    for(QList<QString>::iterator kk=authors.begin();kk!=authors.end();kk++)
    {
        aux.clear();
        aux=map.values(*kk);
        out<<"\t\tThe key '"<<(*kk)<<"' is involved by ";
        if(aux.size()==0) { out<<" no association"<<endl<<endl; }
        else
        {
            if(aux.size()==1) { out<<" only one association '"<<*kk<<"' <-> "<<aux.first()<<endl<<endl; }
            else
            {
                out<<aux.size()<<" associations"<<endl<<endl;
                for(QList<int>::iterator aa=aux.begin();aa!=aux.end();aa++) { out<<"\t\t\tassociation '"<<*kk<<"' <-> "<<(*aa)<<endl; }
                out<<endl;
            }
        }
    }

    out<<"\tRemoving all associations, involving the key 'multi', in the current 'QMap' object ... ";
    map.remove("multi");
    out<<"ok"<<endl<<"\tFound "<<map.size()<<" associations in the current 'QMap' object"<<endl<<endl;

    /* If we arrive here, we can deallocate everything! */
    vals.clear();
    authors.clear();
    fonts.clear();
    res.clear();
    ss.clear();
    qss.clear();
    qss1.clear();
    qss2.clear();
    map.clear();
    return EXIT_SUCCESS;
}
