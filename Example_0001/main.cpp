/****************************************************************************************************************
 * David Canino - canino.david@gmail.com
 *
 * Basic examples for the QT Library
 * Github: https://github.com/davidcanino/QT_examples.git
 *
 * This is the basic example for checking correctness of the current QT Library. No parameter is required.
 *
 * Last update: May 2016
 *****************************************************************************************************************/

#include <QtCore>
#include <QSysInfo>
#include <QLibraryInfo>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

/* No parameter is required! */
int main(int argc,char **argv)
{
    QSysInfo::MacVersion mv;
    QSysInfo::WinVersion mw;

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

    /* If we arrive here, all is ok. First, we analyze the version of the current QT Library! */
    cout<<"\tINFORMATION regarding the current build of the QT Library"<<endl;
    cout<<"\t========================================================================================================================="<<endl<<endl;
    cout<<"\tConstant value QT_VERSION: "<<QT_VERSION<<endl;
    cout<<"\tConstant value QT_VERSION_STR: "<<QT_VERSION_STR<<endl;
    cout<<"\tFunction 'qVersion()': "<<qVersion()<<endl;
    cout<<"\tVersion of the current QT Library: "<<qVersion()<<endl;
    cout.flush();
    if(QLibraryInfo::isDebugBuild()==true) { cout<<"\tThe current QT Library was built with debugging enabled"<<endl; }
    else { cout<<"\tThe current QT Library was built in release mode"<<endl; }
    cout<<"\tProducts, such that the license for the current build of the QT Library has access to: "<<QLibraryInfo::licensedProducts().toStdString()<<endl;
    cout<<"\tPerson to whom this build of the current build of the QT Library is licensed: "<<QLibraryInfo::licensee().toStdString()<<endl<<endl;
    cout<<"\tDefault path for all paths: "<<QLibraryInfo::location(QLibraryInfo::PrefixPath).toStdString()<<endl;
    cout<<"\tLocation for documentation upon install: "<<QLibraryInfo::location(QLibraryInfo::DocumentationPath).toStdString()<<endl;
    cout<<"\tLocation for all headers: "<<QLibraryInfo::location(QLibraryInfo::HeadersPath).toStdString()<<endl;
    cout<<"\tLocation for installed libraries: "<<QLibraryInfo::location(QLibraryInfo::LibrariesPath).toStdString()<<endl;
    cout<<"\tLocation for installed executables, required by libraries at run-time: "<<QLibraryInfo::location(QLibraryInfo::LibraryExecutablesPath).toStdString()<<endl;
    cout<<"\tLocation for installed QT binaries (tools and applications): "<<QLibraryInfo::location(QLibraryInfo::BinariesPath).toStdString()<<endl;
    cout<<"\tLocation for installed QT plugins: "<<QLibraryInfo::location(QLibraryInfo::PluginsPath).toStdString()<<endl;
    cout<<"\tLocation of installed QML extensions to import (QML 1.*): "<<QLibraryInfo::location(QLibraryInfo::ImportsPath).toStdString()<<endl;
    cout<<"\tLocation of installed QML extensions to import (QML 2.*): "<<QLibraryInfo::location(QLibraryInfo::Qml2ImportsPath).toStdString()<<endl;
    cout<<"\tLocation of general architecture-dependent QT data: "<<QLibraryInfo::location(QLibraryInfo::ArchDataPath).toStdString()<<endl;
    cout<<"\tLocation of general architecture-independent QT data: "<<QLibraryInfo::location(QLibraryInfo::DataPath).toStdString()<<endl;
    cout<<"\tLocation of translation information for QT strings: "<<QLibraryInfo::location(QLibraryInfo::TranslationsPath).toStdString()<<endl;
    cout<<"\tLocation for official examples of the QT Library upon install: "<<QLibraryInfo::location(QLibraryInfo::ExamplesPath).toStdString()<<endl;
    cout<<"\tLocation for official testcases of the QT Library upon install: "<<QLibraryInfo::location(QLibraryInfo::TestsPath).toStdString()<<endl;
    mw=QSysInfo::windowsVersion();
    if(mw==QSysInfo::WV_None) { cout<<"\tLocation for QT settings: "<<QLibraryInfo::location(QLibraryInfo::QLibraryInfo::SettingsPath).toStdString()<<endl; }
    cout<<endl;
    cout.flush();

    /* Now, we analyze which platform we are using! */
    cout<<"\tINFORMATION regarding the current platform"<<endl;
    cout<<"\t========================================================================================================================="<<endl<<endl;
    cout<<"\tStandard description for the current platform: "<<QSysInfo::buildAbi().toStdString()<<endl;
    #if Q_BYTE_ORDER==Q_BIG_ENDIAN

        cout<<"\tThe current platform is big-endian"<<endl;
        cout.flush();

    #endif

    /* Now, we analyze the current platform (LITTLE-ENDIAN)! */
    #if Q_BYTE_ORDER==Q_LITTLE_ENDIAN

        cout<<"\tThe current platform is little-endian"<<endl;
        cout.flush();

    #endif

    cout<<"\tArchitecture of the CPU that QT Library was compiled for: "<<QSysInfo::buildCpuArchitecture().toStdString()<<endl;
    cout<<"\tArchitecture of the CPU that this application is running on: "<<QSysInfo::currentCpuArchitecture().toStdString()<<endl;
    #if Q_CC_BOR

        cout<<"\tThis application is compiled using Borland/Turbo C++ compiler"<<end;
        cout.flush();

    #endif

    #if Q_CC_CDS

        cout<<"\tThis application is compiled using Reliant C++ compiler"<<endl;
        cout.flush();

    #endif

    #if Q_CC_CLANG

        cout<<"\tThis application is compiled using either CLANG or GNU compiler"<<endl;
        cout.flush();

    #endif

    #if Q_CC_COMEAU

        cout<<"\tThis application is compiled using Comeau C++ compiler"<<endl;
        cout.flush();

    #endif

    #if Q_CC_DEC

        cout<<"\tThis application is compiled using DEC C++ compiler"<<endl;
        cout.flush();

    #endif

    #if Q_CC_EDG

        cout<<"\tThis application is compiled using Edison Design Group C++ compiler"<<endl;
        cout.flush();

    #endif

    #if Q_CC_GHS

        cout<<"\tThis application is compiled using Green Hills Optimizing C++ Compilers"<<endl;
        cout.flush();

    #endif

    #if Q_CC_GNU

        cout<<"\tThis application is compiled using either GNU or CLANG compiler"<<endl;
        cout.flush();

    #endif

    #if Q_CC_HIGHC

        cout<<"\tThis application is compiled using MetaWare High C/C++ compiler"<<endl;
        cout.flush();

    #endif

    #if Q_CC_HPACC

        cout<<"\tThis application is compiled using HP aC++ compiler"<<endl;
        cout.flush();

    #endif

    #if Q_CC_INTEL

        cout<<"\tThis application is compiled using Intel C++ compiler (not for MS Windows)"<<endl;
        cout.flush();

    #endif

    #if Q_CC_KAI

        cout<<"\tThis application is compiled using KAI C++ compiler"<<endl;
        cout.flush();

    #endif

    #if Q_CC_MIPS

        cout<<"\tThis application is compiled using MIPSpro C++ compiler"<<endl;
        cout.flush();

    #endif

    #if Q_CC_MSVC

        cout<<"\tThis application is compiled using either MS Visual C/C++ or Intel C++ for MS Windows compiler"<<endl;
        cout.flush();

    #endif

    #if Q_CC_OC

        cout<<"\tThis application is compiled using CenterLine C++ compiler"<<endl;
        cout.flush();

    #endif

    #if Q_CC_PGI

        cout<<"\tThis application is compiled using Portland Group C++ compiler"<<endl;
        cout.flush();

    #endif

    #if Q_CC_SUN

        cout<<"\tThis application is compiled using either Forte Developer or Sun Studio C++ compiler"<<endl;
        cout.flush();

    #endif

    #if Q_CC_SYM

        cout<<"\tThis application is compiled using Digital Mars C++ (used to be Symantec C++) compiler"<<endl;
        cout.flush();

    #endif

    #if Q_CC_USLC

         cout<<"\tThis application is compiled using SCO OUDK and UDK"<<endl;
         cout.flush();
    #endif

    #if Q_CC_WAT

         cout<<"\tThis application is compiled using Watcom C++"<<endl;
         cout.flush();

    #endif

    cout<<"\tCurrent machine's host name: "<<QSysInfo::machineHostName().toStdString()<<endl<<endl;
    cout.flush();

    cout<<"\tINFORMATION regarding the current operating system"<<endl;
    cout<<"\t========================================================================================================================="<<endl<<endl;
    cout<<"\tCurrent operating system (complete information): "<<QSysInfo::prettyProductName().toStdString()<<endl;
    cout<<"\tProduct name of the operating system this application is running in: "<<QSysInfo::productType().toStdString()<<endl;
    cout<<"\tProduct version of the operating system this application is running in (string form): "<<QSysInfo::productVersion().toStdString()<<endl;
    #ifdef Q_OS_AIX

        cout<<"\tCurrent operating system: AIX operating system"<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_ANDROID

        cout<<"\tCurrent operating system: ANDROID operating system"<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_BSD4

        cout<<"\tCurrent operating system: any BSD 4.4 operating system"<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_BSDI

        cout<<"\tCurrent operating system: any BSD operating system"<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_CYGWIN

        cout<<"\tCurrent operating platform: Cygwin platform"<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_DARWIN

        cout<<"\tCurrent operating system: Darwin-based operating system (e.g., OS X and iOS, including its open-source version)"<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_DARWIN64

        cout<<"\tCurrent operating system: 64bit Darwin-based operating system (e.g., OS X and iOS, including its open-source version)"<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_DGUX

        cout<<"\tCurrent operating system: DG/UX operating system"<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_DYNIX

        cout<<"\tCurrent operating system: DYNIX/ptx operating system"<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_FREEBSD

        cout<<"\tCurrent operating system: any FreeBSD operating system"<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_HPUX

        cout<<"\tCurrent operating system: HP-UX operating system"<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_HURD

        cout<<"\tCurrent operating system: GNU Hurd operating system"<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_IOS

        cout<<"\tCurrent operating system: iOS operating system"<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_IRIX

        cout<<"\tCurrent operating system: SGI Irix operating system"<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_LINUX

        cout<<"\tCurrent operating system: GNU/Linux"<<endl;
        cout.flush();

    #endif

    #if Q_OS_LYNX

        cout<<"\tCurrent operating system: LynxOS operating system"<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_MAC

        cout<<"\tCurrent operating system: any generic Apple operating system (e.g., OS X and iOS)"<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_NETBSD

        cout<<"\tCurrent operating system: NetBSD operating system"<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_OPENBSD

        cout<<"\tCurrent operating system: OpenBSD operating system"<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_OSF

        cout<<"\tCurrent operating system: HP Tru64 UNIX"<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_OSX

         cout<<"\tCurrent operating system: any version of Apple OS X"<<endl;
         cout.flush();

    #endif

    #ifdef Q_OS_QNX

        cout<<"\tCurrent operating system: QNX Neutrino"<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_RELIANT

        cout<<"\tCurrent operating system: Reliant UNIX"<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_SOLARIS

        cout<<"\tCurrent operating system: SUN Solaris"<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_SCO

        cout<<"\tCurrent operating system: SCO OpenServer operating system"<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_ULTRIX

        cout<<"\tCurrent operating system: DEC Ultrix operating system"<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_UNIX

        cout<<"\tCurrent operating system: any UNIX BSD/SYS V system"<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_UNIXWARE

        cout<<"\tCurrent operating system: UnixWare 7 (Open Unix 8) operating system"<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_WIN

        cout<<"\tCurrent operating system: any version of MS Windows operating system"<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_WIN32

    cout<<"\tCurrent operating system: any 32-bit version of MS Windows operating system"<<endl;
    cout.flush();

    #endif

    #ifdef Q_OS_WIN64

        cout<<"\tCurrent operating system: any 64-bit version of MS Windows operating system"<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_WINCE

        cout<<"\tCurrent operating system: MS Windows CE operating system"<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_WINPHONE

        cout<<"\tCurrent operating system: MS Windows Phone 8 operating system"<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_WINRT

        cout<<"\tCurrent operating platform: any MS Windows Runtime (MS Windows Store Apps) on MS Windows 8, Windows RT, and Windows Phone 8"<<endl;
        cout.flush();

    #endif

    /* Retrieving more information! */
    mv=QSysInfo::macVersion();
    if(mv!=QSysInfo::MV_None)
    {
        switch (mv)
        {
            case QSysInfo::MV_9:

                cout<<"\tCurrent platform: Mac OS 9"<<endl;
                cout.flush();
                break;

            case QSysInfo::MV_CHEETAH:

                cout<<"\tCurrent platform: Mac OS 10.0 Cheetah"<<endl;
                cout.flush();
                break;

            case QSysInfo::MV_PUMA:

                cout<<"\tCurrent platform: Mac OS X 10.1 Puma"<<endl;
                cout.flush();
                break;

            case QSysInfo::MV_JAGUAR:

                cout<<"\tCurrent platform: Mac OS X 10.2 Jaguar"<<endl;
                cout.flush();
                break;

            case QSysInfo::MV_PANTHER:

                cout<<"\tCurrent platform: Mac OS X 10.3 Panther"<<endl;
                cout.flush();
                break;

            case QSysInfo::MV_TIGER:

                cout<<"\tCurrent platform: Mac OS X 10.4 Tiger"<<endl;
                cout.flush();
                break;

            case QSysInfo::MV_LEOPARD:

                cout<<"\tCurrent platform: Mac OS X 10.5 Leopard"<<endl;
                cout.flush();
                break;

            case QSysInfo::MV_SNOWLEOPARD:

                cout<<"\tCurrent platform: Mac OS X 10.6 Snow Leopard"<<endl;
                cout.flush();
                break;

            case QSysInfo::MV_LION:

                cout<<"\tCurrent platform: Mac OS X 10.7 Lion"<<endl;
                cout.flush();
                break;

            case QSysInfo::MV_MOUNTAINLION:

                cout<<"\tCurrent platform: Mac OS X 10.8 Mountain Lion"<<endl;
                cout.flush();
                break;

            case QSysInfo::MV_MAVERICKS:

                cout<<"\tCurrent platform: Mac OS X 10.9 Mavericks"<<endl;
                cout.flush();
                break;

            case QSysInfo::MV_YOSEMITE:

                cout<<"\tCurrent platform: Mac OS X 10.10 Yosemite"<<endl;
                cout.flush();
                break;

            case QSysInfo::MV_ELCAPITAN:

                cout<<"\tCurrent platform: Mac OS X 10.11 El-Capitan"<<endl;
                cout.flush();
                break;

            case QSysInfo::MV_IOS:

                cout<<"\tCurrent platform: any generic iOS"<<endl;
                cout.flush();
                break;

            case QSysInfo::MV_IOS_4_3:

                cout<<"\tCurrent platform: iOS 4.3"<<endl;
                cout.flush();
                break;

            case QSysInfo::MV_IOS_5_0:

                cout<<"\tCurrent platform: iOS 5.0"<<endl;
                cout.flush();
                break;

            case QSysInfo::MV_IOS_5_1:

                cout<<"\tCurrent platform: iOS 5.1"<<endl;
                cout.flush();
                break;

            case QSysInfo::MV_IOS_6_0:

                cout<<"\tCurrent platform: iOS 6.0"<<endl;
                cout.flush();
                break;

            case QSysInfo::MV_IOS_6_1:

                cout<<"\tCurrent platform: iOS 6.1"<<endl;
                cout.flush();
                break;

            case QSysInfo::MV_IOS_7_0:

                cout<<"\tCurrent platform: iOS 7.0"<<endl;
                cout.flush();
                break;

            case QSysInfo::MV_IOS_7_1:

                cout<<"\tCurrent platform: iOS 7.1"<<endl;
                cout.flush();
                break;

            case QSysInfo::MV_IOS_8_0:

                cout<<"\tCurrent platform: iOS 8.0"<<endl;
                cout.flush();
                break;

            case QSysInfo::MV_IOS_8_1:

                cout<<"\tCurrent platform: iOS 8.1"<<endl;
                cout.flush();
                break;

            case QSysInfo::MV_IOS_8_2:

                cout<<"\tCurrent platform: iOS 8.2"<<endl;
                cout.flush();
                break;

            case QSysInfo::MV_IOS_8_3:

                cout<<"\tCurrent platform: iOS 8.3"<<endl;
                cout.flush();
                break;

            case QSysInfo::MV_IOS_8_4:

                cout<<"\tCurrent platform: iOS 8.4"<<endl;
                cout.flush();
                break;

            default:

                cout<<"\tCurrent platform: iOS 9"<<endl;
                cout.flush();
                break;
        }
    }

    /* Probably, we use MS Windows! */
    mw=QSysInfo::windowsVersion();
    if(mw!=QSysInfo::WV_None)
    {
        switch (mw)
        {
            case QSysInfo::WV_32s:

                cout<<"\tCurrent platform: MS Windows 3.1"<<endl;
                cout.flush();
                break;

            case QSysInfo::WV_95:

                cout<<"\tCurrent platform: MS Windows 95"<<endl;
                cout.flush();
                break;

            case QSysInfo::WV_98:

                cout<<"\tCurrent platform: MS Windows 98"<<endl;
                cout.flush();
                break;

            case QSysInfo::WV_Me:

                cout<<"\tCurrent platform: MS Windows Millenium Edition (ME)"<<endl;
                cout.flush();
                break;

            case QSysInfo::WV_NT:

                cout<<"\tCurrent platform: MS Windows NT"<<endl;
                cout.flush();
                break;

            case QSysInfo::WV_2000:

                cout<<"\tCurrent platform: MS Windows 2000"<<endl;
                cout.flush();
                break;

            case QSysInfo::WV_XP:

                cout<<"\tCurrent platform: MS Windows XP"<<endl;
                cout.flush();
                break;

            case QSysInfo::WV_2003:

                cout<<"\tCurrent platform: MS Windows Server 2003, MS Windows XP Professional x64 Edition"<<endl;
                cout.flush();
                break;

            case QSysInfo::WV_VISTA:

                cout<<"\tCurrent platform: MS Windows Vista, MS Windows Server 2008"<<endl;
                cout.flush();
                break;

            case QSysInfo::WV_WINDOWS7:

                cout<<"\tCurrent platform: MS Windows 7"<<endl;
                cout.flush();
                break;

            case QSysInfo::WV_WINDOWS8:

                cout<<"\tCurrent platform: MS Windows 8"<<endl;
                cout.flush();
                break;

            case QSysInfo::WV_WINDOWS8_1:

                cout<<"\tCurrent platform: MS Windows 8.1"<<endl;
                cout.flush();
                break;

            case QSysInfo::WV_CE:

                cout<<"\tCurrent platform: MS Windows CE"<<endl;
                cout.flush();
                break;

            case QSysInfo::WV_CENET:

                cout<<"\tCurrent platform: MS Windows CE.NET"<<endl;
                cout.flush();
                break;

             case QSysInfo::WV_CE_5:

                cout<<"\tCurrent platform: MS Windows CE 5.*"<<endl;
                cout.flush();
                break;

             case QSysInfo::WV_CE_6:

                cout<<"\tCurrent platform: MS Windows CE 6.*"<<endl;
                cout.flush();
                break;

             case QSysInfo::WV_DOS_based:

                cout<<"\tCurrent platform: any generic DOS-based version of MS Windows"<<endl;
                cout.flush();
                break;

             case QSysInfo::WV_NT_based:

                cout<<"\tCurrent platform: any generic NT-based version of MS Windows"<<endl;
                cout.flush();
                break;

             case QSysInfo::WV_CE_based:

                cout<<"\tCurrent platform: any generic CE-based version of MS Windows"<<endl;
                cout.flush();
                break;

             default:

                cout<<"\tCurrent platform: MS Windows 10"<<endl;
                cout.flush();
                break;
        }
    }

    /* If we arrive here, all is ok! */
    cout<<"\tOperating system kernel QT Library was compiled for: "<<QSysInfo::kernelType().toStdString()<<endl;
    cout<<"\tRelease version of the operating system kernel: "<<QSysInfo::kernelVersion().toStdString()<<endl<<endl;
    return EXIT_SUCCESS;
}
