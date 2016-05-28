/*************************************************************************************************************************
 * David Canino - canino.david@gmail.com
 *
 * Basic examples for the QT Library
 * Github: https://github.com/davidcanino/QT_examples.git
 *
 * This is the basic example for managing files and directories in the current QT Library. No parameter is required.
 *
 * Last update: May 2016
 *************************************************************************************************************************/

#include<cstdlib>
#include<iostream>
#include<string>
#include<QTextStream>
#include <QFileInfo>
#include <QDateTime>
#include <QDir>
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

    /******************************* VALIDATING 'QFile' and 'QFileInfo' ************************************************************************************/

    QTextStream out(stdout);
    QString filename = "./main.cpp";
    QFileInfo fileinfo;

    /* We understand the size of the 'main.cpp' file. */
    fileinfo.setFile(filename);
    if(fileinfo.exists())
    {
        out<<"\tFile '"<<fileinfo.fileName()<<"' exists and its size is "<<fileinfo.size()<<" bytes"<<endl<<"\tIn particular, it is:"<<endl<<endl;
        if(fileinfo.isDir()) out<<"\t\t-) a directory<"<<endl;
        else out<<"\t\t-) not a directory"<<endl;
        if(fileinfo.isFile()) out<<"\t\t-) a plain file"<<endl;
        else out<<"\t\t-) not a plain file"<<endl;
        if(fileinfo.isExecutable()) out<<"\t\t-) an executable file"<<endl;
        else out<<"\t\t-) not an executable file"<<endl;
        if(fileinfo.isHidden()) out<<"\t\t-) a hidden file"<<endl;
        else out<<"\t\t-) not a hidden file"<<endl;
        if(fileinfo.isReadable()) out<<"\t\t-) a readable file"<<endl;
        else out<<"\t\t-) not a readable file"<<endl;
        if(fileinfo.isWritable()) out<<"\t\t-) a writable file"<<endl;
        else out<<"\t\t-) not a writable file"<<endl;
        if(fileinfo.isSymLink()) out<<"\t\t-) a symbolic link (or shorcut)"<<endl;
        else out<<"\t\t-) not a symbolic link (or shorcut)"<<endl;
        if(fileinfo.isAbsolute()) out<<"\t\t-) specified by an absolute path"<<endl;
        else out<<"\t\t-) not specified by an absolute path"<<endl;
        if(fileinfo.isRelative()) out<<"\t\t-) specified by a relative path"<<endl<<endl;
        else out<<"\t\t-) not specified by a relative path"<<endl<<endl;
        out<<"\tAbsolute path: '"<<fileinfo.absoluteFilePath()<<"'"<<endl;
        out<<"\tBasename: '"<<fileinfo.baseName()<<"'"<<endl;
        if(fileinfo.isBundle()) out<<"\tThis file belongs to bundle "<<fileinfo.bundleName()<<"'"<<endl;
        else out<<"\tThis file does not belong to any bundle"<<endl;
        out<<"\tCanonical file path: '"<<fileinfo.canonicalFilePath()<<"'"<<endl;
        out<<"\tCanonical path: '"<<fileinfo.canonicalPath()<<"'"<<endl;
        out<<"\tComplete basename: '"<<fileinfo.completeBaseName()<<"'"<<endl;
        out<<"\tComplete suffix: '"<<fileinfo.completeSuffix()<<"'"<<endl<<endl;

        #if (defined Q_OS_AIX) || (defined Q_OS_ANDROID) || (defined Q_OS_BSD4) || (defined Q_OS_BSDI) || (defined Q_OS_CYGWIN) || (defined Q_OS_DARWIN) || (defined Q_OS_DARWIN64) || (defined Q_OS_DGUX) || (defined Q_OS_DYNIX) || (defined Q_OS_FREEBSD) || (defined Q_OS_HPUX) || (defined Q_OS_HURD) || (defined Q_OS_IOS) || (defined Q_OS_IRIX) || (defined Q_OS_LINUX) || (defined Q_OS_LYNX) || (defined Q_OS_MAC) || (defined Q_OS_NETBSD) || (defined Q_OS_OPENBSD) || (defined Q_OS_OSF) || (defined Q_OS_OSX) || (defined Q_OS_QNX) || (defined Q_OS_RELIANT) || (defined Q_OS_SOLARIS) || (defined Q_OS_SCO) || (defined Q_OS_ULTRIX) || (defined Q_OS_UNIX) || (defined Q_OS_UNIXWARE)

            out<<"\tOwner: "<<fileinfo.owner()<<endl;
            out<<"\tOwner identifier: "<<fileinfo.ownerId()<<endl;
            out<<"\tGroup: "<<fileinfo.group()<<endl;
            out<<"\tGroup identifier: "<<fileinfo.groupId()<<endl<<endl;
            if(fileinfo.permission(QFileDevice::ReadOwner)) out<<"\tIt is readable by the owner '"<<fileinfo.owner()<<"'"<<endl;
            else out<<"\tIt is not readable by the owner '"<<fileinfo.owner()<<"'"<<endl;
            if(fileinfo.permission(QFileDevice::WriteOwner)) out<<"\tIt is writable by the owner '"<<fileinfo.owner()<<"'"<<endl;
            else out<<"\tIt is not writable by the owner '"<<fileinfo.owner()<<"'"<<endl;
            if(fileinfo.permission(QFileDevice::ExeOwner)) out<<"\tIt is executable by the owner '"<<fileinfo.owner()<<"'"<<endl<<endl;
            else out<<"\tIt is not executable by the owner '"<<fileinfo.owner()<<"'"<<endl<<endl;
            if(fileinfo.permission(QFileDevice::ReadGroup)) out<<"\tIt is readable by anyone in the group '"<<fileinfo.group()<<"'"<<endl;
            else out<<"\tIt is not readable by anyone in the group '"<<fileinfo.group()<<"'"<<endl;
            if(fileinfo.permission(QFileDevice::WriteGroup)) out<<"\tIt is writable by anyone in the group '"<<fileinfo.group()<<"'"<<endl;
            else out<<"\tIt is not writable by anyone in the group '"<<fileinfo.group()<<"'"<<endl;
            if(fileinfo.permission(QFileDevice::ExeGroup)) out<<"\tIt is executable by anyone in the group '"<<fileinfo.group()<<"'"<<endl<<endl;
            else out<<"\tIt is not executable by anyone in the group '"<<fileinfo.group()<<"'"<<endl<<endl;
            if(fileinfo.permission(QFileDevice::ReadOther)) out<<"\tIt is readable by anyone"<<endl;
            else out<<"\tIt is not readable by anyone"<<endl;
            if(fileinfo.permission(QFileDevice::WriteOther)) out<<"\tIt is writable by anyone"<<endl;
            else out<<"\tIt is not writable by anyone"<<endl;
            if(fileinfo.permission(QFileDevice::ExeOther)) out<<"\tIt is executable by anyone"<<endl<<endl;
            else out<<"\tIt is not executable by anyone"<<endl<<endl;

        #endif

        if(fileinfo.permission(QFileDevice::ReadUser)) out<<"\tIt is readable by the user"<<endl;
        else out<<"\tIt is not readable by the user"<<endl;
        if(fileinfo.permission(QFileDevice::WriteUser)) out<<"\tIt is writable by the user"<<endl;
        else out<<"\tIt is not writable by the user"<<endl;
        if(fileinfo.permission(QFileDevice::ExeUser)) out<<"\tIt is executable by the user"<<endl<<endl;
        else out<<"\tIt is not executable by the user"<<endl<<endl;
        out<<"\tCreation (or last modification) date: "<<fileinfo.created().toString()<<endl;
        out<<"\tLast modification date: "<<fileinfo.lastModified().toString()<<endl;
        out<<"\tLast reading date: "<<fileinfo.lastRead().toString()<<endl<<endl;
        out<<"\tDirectory (as specified internally): "<<fileinfo.dir().path()<<endl;
        out<<"\tFile path (as specified internally): "<<fileinfo.filePath()<<endl;
        out<<"\tConverting internal representation with the absolute paths ... ";
        fileinfo.makeAbsolute();
        out<<"ok"<<endl;
        out<<"\tDirectory (as specified internally): "<<fileinfo.dir().path()<<endl;
        out<<"\tFile path (as specified internally): "<<fileinfo.filePath()<<endl<<endl;
        out<<"\tPress the RETURN key to continue"<<endl;
        getchar();
    }
    else
    {
        /* The file 'main.cpp' does not exist! */
        cout.flush();
        cerr<<"\tError: file "<<fileinfo.fileName().toStdString()<<" does not exist"<<endl<<endl;
        cerr<<"\tUsage: "<<string(argv[0])<<endl<<endl;
        cerr.flush();
        return EXIT_FAILURE;
    }

    /********************************************* VALIDATING the WRITING of STRINGS on ASCII FILES ***********************************/

    QFile file;

    out<<"\tCreating an auxiliary ASCII file 'test.txt' ... ";
    file.setFileName("test.txt");
    if (file.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        QTextStream fout(&file);

        out<<"ok"<<endl<<"\tIn particular, it is:"<<endl<<endl;
        if(file.isOpen()) out<<"\t\t-) open correctly"<<endl;
        else
        {
            /* The file 'test.txt' cannot be created! */
            cout.flush();
            cerr<<"\tError: file 'test.txt' is not opened correctly [ "<<file.errorString().toStdString()<<" ]"<<endl;
            cerr<<"\tUsage: "<<string(argv[0])<<endl<<endl;
            cerr.flush();
            return EXIT_FAILURE;
        }

        if(file.isSequential()) out<<"\t\t-) sequential"<<endl;
        else out<<"\t\t-) not sequential"<<endl;
        if(file.isTextModeEnabled()) out<<"\t\t-) enabled for storing some text"<<endl;
        else out<<"\t\t-) not enabled for storing some text"<<endl;
        if(file.isWritable()) out<<"\t\t-) writable"<<endl<<endl;
        else out<<"\t\t-) not writable"<<endl<<endl;
        out<<"\tWriting some strings on ASCII file 'test.txt' ... ";
        fout<<"\texample of lines   , tabs and     spaces"<<endl;
        fout<<"25       #"<<endl;
        fout<<"20"<<endl;
        fout<<"34 33 22"<<endl;
        fout<<"end file (EOF)";
        out<<"ok"<<endl;
        file.flush();
        file.close();
        out<<"\tWritten "<<file.size()<<" bytes on file 'test.txt'"<<endl;
        if(file.isOpen()==false) out<<"\tFile 'test.txt' is closed correctly"<<endl<<endl;
        else
        {
            /* The file 'test.txt' cannot be closed! */
            cout.flush();
            cerr<<"\tError: file 'test.txt' is not closed correctly [ "<<file.errorString().toStdString()<<" ]"<<endl;
            cerr<<"\tUsage: "<<string(argv[0])<<endl<<endl;
            cerr.flush();
            return EXIT_FAILURE;
        }
    }
    else
    {
        /* The file 'test.txt' cannot be created! */
        cout.flush();
        cerr<<"\tError: file 'test.txt' cannot be created [ "<<file.errorString().toStdString()<<" ]"<<endl;
        cerr<<"\tUsage: "<<string(argv[0])<<endl<<endl;
        cerr.flush();
        return EXIT_FAILURE;
    }

    out<<"\tPress the RETURN key to continue"<<endl;
    getchar();

    /********************************************* VALIDATING the PARSING of STRINGS from ASCII FILES ***********************************/

    out<<"\tReading ASCII data from file 'test.txt' (just created) ... ";
    file.setFileName("test.txt");
    if (file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QTextStream fin(&file);

        out<<"ok"<<endl<<"\tIn particular, it is:"<<endl<<endl;
        if(file.isOpen()) out<<"\t\t-) open correctly"<<endl;
        else
        {
            /* The file 'test.txt' cannot be created! */
            cout.flush();
            cerr<<"\tError: file 'test.txt' is not opened correctly [ "<<file.errorString().toStdString()<<" ]"<<endl;
            cerr<<"\tUsage: "<<string(argv[0])<<endl<<endl;
            cerr.flush();
            return EXIT_FAILURE;
        }

        if(file.isSequential()) out<<"\t\t-) sequential"<<endl;
        else out<<"\t\t-) not sequential"<<endl;
        if(file.isTextModeEnabled()) out<<"\t\t-) enabled for storing some text"<<endl;
        else out<<"\t\t-) not enabled for storing some text"<<endl;
        if(file.isReadable()) out<<"\t\t-) readable"<<endl<<endl;
        else out<<"\t\t-) not readable"<<endl<<endl;
        out<<"\tNumber of bytes, available for reading (estimation): "<<file.bytesAvailable()<<endl;
        out<<"\tNumber of bytes in file 'test.txt': "<<file.size()<<endl;
        out<<"\tContent of file 'test.txt':"<<endl<<endl;
        while (!fin.atEnd())
        {
            QString line = fin.readLine();
            out<<"\t\t'"<<line<<"'"<<endl;
        }

        out<<endl;
        file.close();
        if(file.isOpen()==false) out<<"\tFile 'test.txt' is closed correctly"<<endl<<endl;
        else
        {
            /* The file 'test.txt' cannot be closed! */
            cout.flush();
            cerr<<"\tError: file 'test.txt' is not closed correctly [ "<<file.errorString().toStdString()<<" ]"<<endl;
            cerr<<"\tUsage: "<<string(argv[0])<<endl<<endl;
            cerr.flush();
            return EXIT_FAILURE;
        }
    }
    else
    {
        /* The file 'test.txt' is not open! */
        cout.flush();
        cerr<<"\tError: file 'test.txt' cannot be opened [ "<<file.errorString().toStdString()<<" ]"<<endl;
        cerr<<"\tUsage: "<<string(argv[0])<<endl<<endl;
        cerr.flush();
        return EXIT_FAILURE;
    }

    file.setFileName("test.txt");
    out<<"\tRemoving auxiliary file 'test.txt' ... ";
    if(file.remove())
    {
        out<<"ok"<<endl;
        if(file.exists()==false) { out<<"\tFile 'test.txt' does not exist anymore (correctly)"<<endl<<endl; }
        else
        {
            /* The file 'test.txt' is not removed! */
            cout.flush();
            cerr<<"\tError: file 'test.txt' cannot be removed [ "<<file.errorString().toStdString()<<" ]"<<endl;
            cerr<<"\tUsage: "<<string(argv[0])<<endl<<endl;
            cerr.flush();
            return EXIT_FAILURE;
        }
    }
    else
    {
        /* The file 'test.txt' is not removed! */
        cout.flush();
        cerr<<"\tError: file 'test.txt' cannot be removed [ "<<file.errorString().toStdString()<<" ]"<<endl;
        cerr<<"\tUsage: "<<string(argv[0])<<endl<<endl;
        cerr.flush();
        return EXIT_FAILURE;
    }

    out<<"\tPress the RETURN key to continue"<<endl;
    getchar();

    /********************************************* VALIDATING the WRITING of BYTES on BINARY FILES ***********************************/

    out<<"\tCreating an auxiliary binary file 'test_bin.bin' ... ";
    file.setFileName("test_bin.bin");
    if (file.open(QIODevice::WriteOnly))
    {
        out<<"ok"<<endl<<"\tIn particular, it is:"<<endl<<endl;
        if(file.isOpen()) out<<"\t\t-) open correctly"<<endl;
        else
        {
            /* The file 'test_bin.bin' cannot be created! */
            cout.flush();
            cerr<<"\tError: file 'test_bin.bin' is not opened correctly [ "<<file.errorString().toStdString()<<" ]"<<endl;
            cerr<<"\tUsage: "<<string(argv[0])<<endl<<endl;
            cerr.flush();
            return EXIT_FAILURE;
        }

        if(file.isSequential()) out<<"\t\t-) sequential"<<endl;
        else out<<"\t\t-) not sequential"<<endl;
        if(file.isTextModeEnabled()) out<<"\t\t-) enabled for storing some text"<<endl;
        else out<<"\t\t-) not enabled for storing some text"<<endl;
        if(file.isWritable()) out<<"\t\t-) writable"<<endl<<endl;
        else out<<"\t\t-) not writable"<<endl<<endl;
        out<<"\tWriting some bytes on binary file 'test_bin.bin' ... ";
        for(int k=0;k<20;k++)
        {
            double d=2.0*k;
            qint64 pos=file.write((const char*)&d,sizeof(d));
        }

        out<<"ok"<<endl;
        file.close();
        out<<"\tWritten "<<file.size()<<" bytes on file 'test_bin.bin'"<<endl;
        if(file.isOpen()==false) out<<"\tFile 'test_bin.bin' is closed correctly"<<endl<<endl;
        else
        {
            /* The file 'test_bin.bin' cannot be closed! */
            cout.flush();
            cerr<<"\tError: file 'test_bin.bin' is not closed correctly [ "<<file.errorString().toStdString()<<" ]"<<endl;
            cerr<<"\tUsage: "<<string(argv[0])<<endl<<endl;
            cerr.flush();
            return EXIT_FAILURE;
        }
    }
    else
    {
        /* The file 'test_bin.bin' cannot be created! */
        cout.flush();
        cerr<<"\tError: file 'test_bin.bin' cannot be created [ "<<file.errorString().toStdString()<<" ]"<<endl;
        cerr<<"\tUsage: "<<string(argv[0])<<endl<<endl;
        cerr.flush();
        return EXIT_FAILURE;
    }

    out<<"\tPress the RETURN key to continue"<<endl;
    getchar();

    /********************************************* VALIDATING the PARSING of BYTES from BINARY FILES ***********************************/

    out<<"\tReading binary data from file 'test_bin.bin' (just created) ... ";
    file.setFileName("test_bin.bin");
    if (file.open(QIODevice::ReadOnly))
    {
        out<<"ok"<<endl<<"\tIn particular, it is:"<<endl<<endl;
        if(file.isOpen()) out<<"\t\t-) open correctly"<<endl;
        else
        {
            /* The file 'test_bin.bin' cannot be created! */
            cout.flush();
            cerr<<"\tError: file 'test_bin.bin' is not opened correctly [ "<<file.errorString().toStdString()<<" ]"<<endl;
            cerr<<"\tUsage: "<<string(argv[0])<<endl<<endl;
            cerr.flush();
            return EXIT_FAILURE;
        }

        if(file.isSequential()) out<<"\t\t-) sequential"<<endl;
        else out<<"\t\t-) not sequential"<<endl;
        if(file.isTextModeEnabled()) out<<"\t\t-) enabled for storing some text"<<endl;
        else out<<"\t\t-) not enabled for storing some text"<<endl;
        if(file.isReadable()) out<<"\t\t-) readable"<<endl<<endl;
        else out<<"\t\t-) not readable"<<endl<<endl;
        out<<"\tNumber of bytes, available for reading (estimation): "<<file.bytesAvailable()<<endl;
        out<<"\tNumber of bytes in file 'test_bin.bin': "<<file.size()<<endl;
        out<<"\tContent of file 'test_bin.bin':"<<endl<<endl;
        for(int k=0;k<20;k++)
        {
           double d;
           qint64 pos=file.read((char*)&d,sizeof(d));
           out<<"\t\tRead "<<pos<<" bytes: "<<d<<endl;
        }

        out<<endl;
        file.close();
        if(file.isOpen()==false) out<<"\tFile 'test_bin.bin' is closed correctly"<<endl<<endl;
        else
        {
            /* The file 'test_bin.bin' cannot be closed! */
            cout.flush();
            cerr<<"\tError: file 'test_bin.bin' is not closed correctly [ "<<file.errorString().toStdString()<<" ]"<<endl;
            cerr<<"\tUsage: "<<string(argv[0])<<endl<<endl;
            cerr.flush();
            return EXIT_FAILURE;
        }
    }
    else
    {
        /* The file 'test_bin.bin' is not open! */
        cout.flush();
        cerr<<"\tError: file 'test_bin.bin' cannot be opened [ "<<file.errorString().toStdString()<<" ]"<<endl;
        cerr<<"\tUsage: "<<string(argv[0])<<endl<<endl;
        cerr.flush();
        return EXIT_FAILURE;
    }

    file.setFileName("test_bin.bin");
    out<<"\tRemoving auxiliary file 'test_bin.bin' ... ";
    if(file.remove())
    {
        out<<"ok"<<endl;
        if(file.exists()==false) { out<<"\tFile 'test_bin.bin' does not exist anymore (correctly)"<<endl<<endl; }
        else
        {
            /* The file 'test_bin.bin' is not removed! */
            cout.flush();
            cerr<<"\tError: file 'test_bin.bin' cannot be removed [ "<<file.errorString().toStdString()<<" ]"<<endl;
            cerr<<"\tUsage: "<<string(argv[0])<<endl<<endl;
            cerr.flush();
            return EXIT_FAILURE;
        }
    }
    else
    {
        /* The file 'test_bin.bin' is not removed! */
        cout.flush();
        cerr<<"\tError: file 'test_bin.bin' cannot be removed [ "<<file.errorString().toStdString()<<" ]"<<endl;
        cerr<<"\tUsage: "<<string(argv[0])<<endl<<endl;
        cerr.flush();
        return EXIT_FAILURE;
    }

    out<<"\tPress the RETURN key to continue"<<endl;
    getchar();

    /******************************************** VALIDATING 'QDir' ****************************************************/

    QDir dir;
    QFileInfoList files;

    out << "\tCurrent path: '"<< QDir::currentPath() << "'"<<endl;
    out << "\tHome path: '" << QDir::homePath() << "'"<<endl;
    out << "\tTemporary path: '" << QDir::tempPath() <<"'"<< endl;
    out << "\tRooth path: '" << QDir::rootPath() << "'"<<endl;
    out << "\tSeparator in the paths: '"<<QDir::separator()<<"'"<<endl;
    out << "\tList separator: '"<<QDir::listSeparator()<<"'"<<endl<<endl;
    dir.setPath("./");
    out<<"\tAbsolute path of directory '"<<dir.path()<<"': '"<<dir.absolutePath()<<"'"<<endl;
    out<<"\tCanonical path of directory '"<<dir.path()<<"': '"<<dir.canonicalPath()<<"'"<<endl;
    out<<"\tDirectory name of directory '"<<dir.path()<<"': '"<<dir.dirName()<<"'"<<endl<<endl;
    out<<"\tMoving to upper directory ... ";
    dir.cdUp();
    out<<"ok"<<endl;
    out<<"\tPath of the upper directory: '"<<dir.absolutePath()<<"'"<<endl;
    out<<"\tDirectory '"<<dir.absolutePath()<<"' contains "<<dir.count()<<" elements"<<endl<<endl;
    files=dir.entryInfoList();
    for(QFileInfoList::iterator it=files.begin();it!=files.end();it++)
    {
        out<<"\t\t-)";
        if(it->isHidden()) out<<" hidden";
        else out<<" not hidden";
        if(it->isSymLink()) out<<" symbolic link";
        if(it->isDir()) out<<" directory";
        if(it->isFile()) out<<" file";
        if(it->isBundle()) out<<" bundle";
        out<<" '"<<it->fileName()<<"'"<<endl;
    }




    out<<endl;
    return EXIT_SUCCESS;
}

    /*



     */
