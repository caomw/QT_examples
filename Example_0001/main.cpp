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
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

/* No parameter is required! */
int main(int argc,char **argv)
{
    QSysInfo::MacVersion mv;

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
    cout<<"\tConstant value QT_VERSION: "<<QT_VERSION<<endl;
    cout<<"\tConstant value QT_VERSION_STR: "<<QT_VERSION_STR<<endl;
    cout<<"\tFunction 'qVersion()': "<<qVersion()<<endl<<endl;
    cout<<"\tVersion of the current QT Library: "<<qVersion()<<endl<<endl;
    cout.flush();

    /* Now, we analyze which platform we are using! */
    cout<<"\tStandard description for the current platform: "<<QSysInfo::buildAbi().toStdString()<<endl<<endl;
    #ifdef Q_OS_AIX

        cout<<"\tCurrent operating system: AIX operating system"<<endl<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_ANDROID

        cout<<"\tCurrent operating system: ANDROID operating system"<<endl<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_BSD4

        cout<<"\tCurrent operating system: any BSD 4.4 operating system"<<endl<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_BSDI

        cout<<"\tCurrent operating system: any BSD operating system"<<endl<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_CYGWIN

        cout<<"\tCurrent operating platform: Cygwin platform"<<endl<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_DARWIN

        cout<<"\tCurrent operating system: Darwin-based operating system (e.g., OS X and iOS, including its open-source version)"<<endl<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_DARWIN64

        cout<<"\tCurrent operating system: 64bit Darwin-based operating system (e.g., OS X and iOS, including its open-source version)"<<endl<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_DGUX

        cout<<"\tCurrent operating system: DG/UX operating system"<<endl<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_DYNIX

        cout<<"\tCurrent operating system: DYNIX/ptx operating system"<<endl<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_FREEBSD

        cout<<"\tCurrent operating system: any FreeBSD operating system"<<endl<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_HPUX

        cout<<"\tCurrent operating system: HP-UX operating system"<<endl<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_HURD

        cout<<"\tCurrent operating system: GNU Hurd operating system"<<endl<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_IOS

        cout<<"\tCurrent operating system: iOS operating system"<<endl<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_IRIX

        cout<<"\tCurrent operating system: SGI Irix operating system"<<endl<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_LINUX

        cout<<"\tCurrent operating system: GNU/Linux"<<endl<<endl;
        cout.flush();

    #endif

    #if Q_OS_LYNX

        cout<<"\tCurrent operating system: LynxOS operating system"<<endl<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_MAC

        cout<<"\tCurrent operating system: any generic Apple operating system (e.g., OS X and iOS)"<<endl<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_NETBSD

        cout<<"\tCurrent operating system: NetBSD operating system"<<endl<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_OPENBSD

        cout<<"\tCurrent operating system: OpenBSD operating system"<<endl<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_OSF

        cout<<"\tCurrent operating system: HP Tru64 UNIX"<<endl<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_OSX

         cout<<"\tCurrent operating system: any version of Apple OS X"<<endl<<endl;
         cout.flush();

    #endif

    #ifdef Q_OS_QNX

        cout<<"\tCurrent operating system: QNX Neutrino"<<endl<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_RELIANT

        cout<<"\tCurrent operating system: Reliant UNIX"<<endl<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_SOLARIS

        cout<<"\tCurrent operating system: SUN Solaris"<<endl<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_SCO

        cout<<"\tCurrent operating system: SCO OpenServer operating system"<<endl<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_ULTRIX

        cout<<"\tCurrent operating system: DEC Ultrix operating system"<<endl<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_UNIX

        cout<<"\tCurrent operating system: any UNIX BSD/SYS V system"<<endl<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_UNIXWARE

        cout<<"\tCurrent operating system: UnixWare 7 (Open Unix 8) operating system"<<endl<<endl;
        cout.flush();

    #endif



    #ifdef Q_OS_WIN

        cout<<"\tCurrent operating system: any version of MS Windows operating system"<<endl<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_WIN32

    cout<<"\tCurrent operating system: any 32-bit version of MS Windows operating system"<<endl<<endl;
    cout.flush();

    #endif

    #ifdef Q_OS_WIN64

        cout<<"\tCurrent operating system: any 64-bit version of MS Windows operating system"<<endl<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_WINCE

        cout<<"\tCurrent operating system: MS Windows CE operating system"<<endl<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_WINPHONE

        cout<<"\tCurrent operating system: MS Windows Phone 8 operating system"<<endl<<endl;
        cout.flush();

    #endif

    #ifdef Q_OS_WINRT

        cout<<"\tCurrent operating platform: any MS Windows Runtime (MS Windows Store Apps) on MS Windows 8, Windows RT, and Windows Phone 8"<<endl<<endl;
        cout.flush();

    #endif

    /* Now, we analyze the current platform (BIG-ENDIAN)! */
    #if Q_BYTE_ORDER==Q_BIG_ENDIAN

        cout<<"\tThe current platform is big-endian"<<endl<<endl;
        cout.flush();

    #endif

    /* Now, we analyze the current platform (LITTLE-ENDIAN)! */
    #if Q_BYTE_ORDER==Q_LITTLE_ENDIAN

        cout<<"\tThe current platform is little-endian"<<endl<<endl;
        cout.flush();

    #endif

    /* Now, we check which compiler is used! */
    #if Q_CC_BOR

        cout<<"\tThis application is compiled using Borland/Turbo C++ compiler"<<end<<endl;
        cout.flush();

    #endif

    #if Q_CC_CDS

        cout<<"\tThis application is compiled using Reliant C++ compiler"<<endl<<endl;
        cout.flush();

    #endif

    #if Q_CC_CLANG

        cout<<"\tThis application is compiled using either CLANG or GNU compiler"<<endl<<endl;
        cout.flush();

    #endif

    #if Q_CC_COMEAU

        cout<<"\tThis application is compiled using Comeau C++ compiler"<<endl<<endl;
        cout.flush();

    #endif

    #if Q_CC_DEC

        cout<<"\tThis application is compiled using DEC C++ compiler"<<endl<<endl;
        cout.flush();

    #endif

    #if Q_CC_EDG

        cout<<"\tThis application is compiled using Edison Design Group C++ compiler"<<endl<<endl;
        cout.flush();

    #endif

    #if Q_CC_GHS

        cout<<"\tThis application is compiled using Green Hills Optimizing C++ Compilers"<<endl<<endl;
        cout.flush();

    #endif

    #if Q_CC_GNU

        cout<<"\tThis application is compiled using either GNU or CLANG compiler"<<endl<<endl;
        cout.flush();

    #endif

    #if Q_CC_HIGHC

        cout<<"\tThis application is compiled using MetaWare High C/C++ compiler"<<endl<<endl;
        cout.flush();

    #endif

    #if Q_CC_HPACC

        cout<<"\tThis application is compiled using HP aC++ compiler"<<endl<<endl;
        cout.flush();

    #endif

    #if Q_CC_INTEL

        cout<<"\tThis application is compiled using Intel C++ compiler (not for MS Windows)"<<endl<<endl;
        cout.flush();

    #endif

    #if Q_CC_KAI

        cout<<"\tThis application is compiled using KAI C++ compiler"<<endl<<endl;
        cout.flush();

    #endif

    #if Q_CC_MIPS

        cout<<"\tThis application is compiled using MIPSpro C++ compiler"<<endl<<endl;
        cout.flush();

    #endif

    #if Q_CC_MSVC

        cout<<"\tThis application is compiled using either MS Visual C/C++ or Intel C++ for MS Windows compiler"<<endl<<endl;
        cout.flush();

    #endif

    #if Q_CC_OC

        cout<<"\tThis application is compiled using CenterLine C++ compiler"<<endl<<endl;
        cout.flush();

    #endif

    #if Q_CC_PGI

        cout<<"\tThis application is compiled using Portland Group C++ compiler"<<endl<<endl;
        cout.flush();

    #endif

    #if Q_CC_SUN

        cout<<"\tThis application is compiled using either Forte Developer or Sun Studio C++ compiler"<<endl<<endl;
        cout.flush();

    #endif

    #if Q_CC_SYM

        cout<<"\tThis application is compiled using Digital Mars C++ (used to be Symantec C++) compiler"<<endl<<endl;
        cout.flush();

    #endif

    #if Q_CC_USLC

        cout<<"\tThis application is compiled using Digital Mars C++ (used to be Symantec C++) compiler"<<endl<<endl;
        cout.flush();

    #endif

    #if Q_CC_WAT

         cout<<"\tThis application is compiled using SCO OUDK and UDK"<<endl<<endl;
         cout.flush();
    #endif

    #if Q_CC_WAT

         cout<<"\tThis application is compiled using Watcom C++"<<endl<<endl;
         cout.flush();

    #endif

    /* Analysis of static functions, offered by 'QSysInfo' */
    cout<<"\tArchitecture of the CPU that QT Library was compiled for: "<<QSysInfo::buildCpuArchitecture().toStdString()<<endl<<endl;
    cout<<"\tArchitecture of the CPU that this application is running on: "<<QSysInfo::currentCpuArchitecture().toStdString()<<endl<<endl;
    cout<<"\tOperating system kernel QT Library was compiled for: "<<QSysInfo::kernelType().toStdString()<<endl<<endl;
    cout<<"\tRelease version of the operating system kernel: "<<QSysInfo::kernelVersion().toStdString()<<endl<<endl;
    mv=QSysInfo::macVersion();
    if(mv!=QSysInfo::MV_None)
    {
        switch (mv)
        {
            case QSysInfo::MV_9:

                cout<<"\tCurrent platform: Mac OS 9"<<endl<<endl;
                cout.flush();
                break;

            case QSysInfo::MV_CHEETAH:

                cout<<"\tCurrent platform: Mac OS 10.0 Cheetah"<<endl<<endl;
                cout.flush();
                break;

            case QSysInfo::MV_PUMA:

                cout<<"\tCurrent platform Mac OS X 10.1 Puma"<<endl<<endl;
                cout.flush();
                break;

            case QSysInfo::MV_JAGUAR:

                cout<<"\tCurrent platform Mac OS X 10.2 Jaguar"<<endl<<endl;
                cout.flush();
                break;

            case QSysInfo::MV_PANTHER:

                cout<<"\tCurrent platform Mac OS X 10.3 Panther"<<endl<<endl;
                cout.flush();
                break;

            case QSysInfo::MV_TIGER:

                cout<<"\tCurrent platform Mac OS X 10.4 Tiger"<<endl<<endl;
                cout.flush();
                break;





            case QSysInfo::MV_MAVERICKS:

                cout<<"\tCurrent platform: Mac OS X 10.9 Mavericks"<<endl<<endl;
                cout.flush();
                break;

            case QSysInfo::MV_YOSEMITE:

                cout<<"\tCurrent platform: Mac OS X 10.10 Yosemite"<<endl<<endl;
                cout.flush();
                break;

            case QSysInfo::MV_ELCAPITAN:

                cout<<"\tCurrent platform: Mac OS X 10.11 El-Capitan"<<endl<<endl;
                cout.flush();
                break;

            case QSysInfo::MV_IOS:

                cout<<"\tCurrent platform: any generic iOS"<<endl<<endl;
                cout.flush();
                break;

            case QSysInfo::MV_IOS_4_3:

                cout<<"\tCurrent platform: iOS 4.3"<<endl<<endl;
                cout.flush();
                break;


            case QSysInfo::MV_IOS_8_4:

                cout<<"\tCurrent platform: iOS 8.4"<<endl<<endl;
                cout.flush();
                break;

            default:

                cout<<"\tCurrent platform: iOS 9"<<endl<<endl;
                cout.flush();
                break;
        }
    }

    cout<<"\tCurrent platform (complete information): "<<QSysInfo::prettyProductName().toStdString()<<endl<<endl;
    cout<<"\tCurrent machine's host name: "<<QSysInfo::machineHostName().toStdString()<<endl<<endl;
    cout<<"\tProduct name of the operating system this application is running in: "<<QSysInfo::productType().toStdString()<<endl<<endl;
    cout<<"\tProduct version of the operating system this application is running in (string form): "<<QSysInfo::productVersion().toStdString()<<endl<<endl;

    /*
    QSysInfo::MV_10_5	Q_MV_OSX( 10, 5 )	Mac OS X 10.5 (unsupported)
    QSysInfo::MV_10_6	Q_MV_OSX( 10, 6 )	Mac OS X 10.6
    QSysInfo::MV_10_7	Q_MV_OSX( 10, 7 )	Mac OS X 10.7
    QSysInfo::MV_10_8	Q_MV_OSX( 10, 8 )	OS X 10.8


    QSysInfo::MV_LEOPARD	MV_10_5	Apple codename for MV_10_5
    QSysInfo::MV_SNOWLEOPARD	MV_10_6	Apple codename for MV_10_6
    QSysInfo::MV_LION	MV_10_7	Apple codename for MV_10_7
    QSysInfo::MV_MOUNTAINLION	MV_10_8	Apple codename for MV_10_8




        ?	iOS 4.3
    QSysInfo::MV_IOS_5_0	?	iOS 5.0
    QSysInfo::MV_IOS_5_1	?	iOS 5.1
    QSysInfo::MV_IOS_6_0	?	iOS 6.0
    QSysInfo::MV_IOS_6_1	?	iOS 6.1
    QSysInfo::MV_IOS_7_0	?	iOS 7.0
    QSysInfo::MV_IOS_7_1	?	iOS 7.1
    QSysInfo::MV_IOS_8_0	?	iOS 8.0
    QSysInfo::MV_IOS_8_1	?	iOS 8.1
    QSysInfo::MV_IOS_8_2	?	iOS 8.2
    QSysInfo::MV_IOS_8_3	?	iOS 8.3


*/

    /* If we arrive here, all is ok! */
    return EXIT_SUCCESS;
}


/*

QString

WinVersion	windowsVersion()
 */
