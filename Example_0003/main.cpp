/*************************************************************************************************************************
 * David Canino - canino.david@gmail.com
 *
 * Basic examples for the QT Library
 * Github: https://github.com/davidcanino/QT_examples.git
 *
 * This is the basic example for manipulating date and time in the current QT Library. No parameter is required.
 *
 * Last update: May 2016
 *************************************************************************************************************************/

#include <iostream>
#include <string>
#include <QTextStream>
#include <QTime>
#include <QDate>
#include <QList>
#include <QDateTime>
#include <ctime>
#include <QTimeZone>
using namespace std;

/* No parameter is required! */
int main(int argc,char **argv)
{
    QTextStream out(stdout);
    QDate cd,dt1,dt2,xmas;
    QTime ct,tm1(17,30,12,55),tm2;
    QList<int> years({2010, 2011, 2012, 2013, 2014, 2015, 2016});
    int wd,m;
    QList<QString> months;
    QList<QDate> dates({QDate(2016, 5, 11), QDate(2016, 8, 1), QDate(2016, 2, 30)});
    QDateTime cdt,uep;
    time_t t;

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

    /* Test #1 - extracting the current date. */
    cd=QDate::currentDate();
    out<<"\tThe current date is (wrt 'text date' version): "<<cd.toString(Qt::TextDate)<<endl;
    out <<"\tThe current date is (wrt locale settings of the current application, long version): " << cd.toString(Qt::DefaultLocaleLongDate)<<endl;
    out <<"\tThe current date is (wrt locale settings of the current application, short version): " << cd.toString(Qt::DefaultLocaleShortDate)<<endl;
    out <<"\tThe current date is (wrt locale settings of the current OS, long version): " << cd.toString(Qt::SystemLocaleLongDate)<<endl;
    out <<"\tThe current date is (wrt locale settings of the current OS, short version): " << cd.toString(Qt::SystemLocaleShortDate)<<endl<<endl;
    out << "\tThe current date is (wrt custom format 'yyyy-MM-dd'): " << cd.toString("yyyy-MM-dd") << endl;
    out << "\tThe current date is (wrt custom format 'yy/M/dd'): "<< cd.toString("yy/M/dd") << endl;
    out << "\tThe current date is (wrt custom format 'd. M. yyyy'): "<< cd.toString("d. M. yyyy") << endl;
    out << "\tThe current date is (wrt custom format 'd-MMMM-yyy'): "<< cd.toString("d-MMMM-yyyy") << endl;
    wd=cd.dayOfWeek();
    out << "\tDay of a week for the current date (short version): "<<QDate::shortDayName(wd)<<endl;
    out << "\tDay of a week for the current date (long version): "<<QDate::longDayName(wd)<<endl<<endl;
    out<<"\tPress the RETURN key to continue"<<endl;
    getchar();

    /* Test #2 - setting dates. */
    dt1.setDate(1776,7,4);
    out << "\tA very famous and important date (in default format) is: " << dt1.toString(  ) << endl;
    wd=dt1.dayOfWeek();
    out << "\tDay of a week for this date (short version): "<<QDate::shortDayName(wd)<<endl;
    out << "\tDay of a week for this date (long version): "<<QDate::longDayName(wd)<<endl<<endl;
    dt1.setDate(1944,6,6);
    out << "\tA very famous and important date (wrt the RFC 2822 format) is: "<<dt1.toString(Qt::RFC2822Date)<<endl;
    wd=dt1.dayOfWeek();
    out << "\tDay of a week for this date (short version): "<<QDate::shortDayName(wd)<<endl;
    out << "\tDay of a week for this date (long version): "<<QDate::longDayName(wd)<<endl<<endl;
    dt2.setDate(1945,4,25);
    out << "\tA very famous and important date (wrt the ISO 8601 format) is: " << dt2.toString(Qt::ISODate) << endl;
    wd=dt1.dayOfWeek();
    out << "\tDay of a week for this date (short version): "<<QDate::shortDayName(wd)<<endl;
    out << "\tDay of a week for this date (long version): "<<QDate::longDayName(wd)<<endl<<endl;
    out<<"\tPress the RETURN key to continue"<<endl;
    getchar();

    /* Test #3 - comparing dates! */
    dt1.setDate(2015,4,5);
    dt2.setDate(2014,4,5);
    out<<"\tFirst date to be compared: "<<dt1.toString(Qt::ISODate)<<endl;
    out<<"\tSecond date to be compared: "<<dt2.toString(Qt::ISODate)<<endl;
    if (dt1 < dt2) { out << "\tDate '"<<dt1.toString(Qt::ISODate) <<"'' comes before '"<< dt2.toString(Qt::ISODate) <<"'"<<endl<<endl; }
    else { out <<"\tDate '"<<dt1.toString(Qt::ISODate) <<"'' comes after '"<< dt2.toString(Qt::ISODate) <<"'"<<endl<<endl; }
    out<<"\tPress the RETURN key to continue"<<endl;
    getchar();

    /* Test #4 - finding leap years! */
    foreach (int year, years)
    {
        if (QDate::isLeapYear(year)) { out <<"\tyear "<<year <<" was a leap year" << endl<<endl; }
        else { out <<"\tyear "<<year<<" was not a leap year" << endl<<endl; }
    }

    /* Test #5 - number of days in months */
    out<<"\tPress the RETURN key to continue";
    out.flush();
    getchar();
    months.append("January");
    months.append("February");
    months.append("March");
    months.append("April");
    months.append("May");
    months.append("June");
    months.append("July");
    months.append("August");
    months.append("September");
    months.append("October");
    months.append("November");
    months.append("December");
    for(int k=0;k<months.size();k++)
    {
        dt1.setDate(2015,k+1,1);
        out<<endl<<"\tMonth "<<months.at(k)<<" (2015) had "<<dt1.daysInMonth()<<" days";
    }

    out<<endl<<endl<<"\tYear "<<dt1.year()<<" had "<<dt1.daysInYear()<<" days"<<endl;
    for(int k=0;k<months.size();k++)
    {
        dt1.setDate(2016,k+1,1);
        out<<endl<<"\tMonth "<<months.at(k)<<" (2016) had "<<dt1.daysInMonth()<<" days";
    }

    /* Test #6 - checking valid dates! */
    out<<endl<<endl;
    out<<"\tPress the RETURN key to continue"<<endl;
    out.flush();
    getchar();
    out<<"\tYear "<<dt1.year()<<" had "<<dt1.daysInYear()<<" days"<<endl;
    m=0;
    foreach(QDate d,dates)
    {
        if(d.isValid()) out<<endl<<"\tDate '"<<d.toString()<<"' (in position "<<m<<") is valid"<<endl;
        else out<<endl<<"\tDate '"<<d.toString()<<"' (in position "<<m<<") is not valid"<<endl;
        m=m+1;
    }

    /* Test #7 - adding days */
    out<<endl;
    out<<"\tPress the RETURN key to continue"<<endl;
    out.flush();
    getchar();
    xmas.setDate(cd.year(),12,25);
    out<<"\tCurrent date is: "<<cd.toString();
    out<<endl<<"\tThere are "<<cd.daysTo(xmas)<<" days to Christmas: "<<xmas.toString()<<endl;
    out<<"\tIn fact, the resulting date, after adding "<<cd.daysTo(xmas)<<" days, is: ";
    dt1=cd.addDays(cd.daysTo(xmas));
    out<<dt1.toString()<<endl<<endl;
    out<<"\tPress the RETURN key to continue"<<endl;
    getchar();

    /* Test #8 - analyzing the current time! */
    ct=QTime::currentTime();
    out <<"\tThe current time (in default format) is: " << ct.toString();
    out <<endl<<"\tThe current time (wrt the ISO 8601 format) is: " << ct.toString(Qt::ISODate);
    out <<endl<<"\tThe current time (wrt locale settings of the current OS, long version) is: " << ct.toString(Qt::SystemLocaleLongDate);
    out <<endl<<"\tThe current time (wrt locale settings of the current OS, short version) is: " << ct.toString(Qt::SystemLocaleShortDate);
    out <<endl<<"\tThe current time (wrt locale settings of the current application, long version) is: " << ct.toString(Qt::DefaultLocaleLongDate);
    out <<endl<<"\tThe current time (wrt locale settings of the current application, short version) is: " << ct.toString(Qt::DefaultLocaleShortDate);
    out <<endl<<"\tThe current time (wrt custom format 'hh:mm:ss.zzz') is: " << ct.toString("hh:mm:ss.zzz");
    out <<endl<<"\tThe current time (wrt custom format 'h:m:s a') is: " << ct.toString("h:m:s a");
    out <<endl<<"\tThe current time (wrt custom format 'H:m:s A') is: " << ct.toString("H:m:s A");
    out <<endl<<"\tThe current time (wrt custom format 'h:m AP') is: " << ct.toString("h:m AP")<<endl<<endl;
    out<<"\tPress the RETURN key to continue"<<endl;
    getchar();

    /* Test #9 - setting of custom times! */
    out << "\tCustom example of time (in default format): "<<tm1.toString()<<endl;
    out << "\tCustom example of time (wrt the RFC 2822 format): "<<tm1.toString(Qt::RFC2822Date)<<endl;
    out << "\tCustom example of time (wrt the ISO 8601 format) is: "<< tm1.toString(Qt::ISODate)<<endl<<endl;
    out << "\tCustom example of time (wrt custom format 'hh:mm:ss.zzz') is: " << tm1.toString("hh:mm:ss.zzz") << endl;
    tm2.setHMS(13, 52, 45, 155);
    out << "\tAnother example of time (wrt custom format 'hh:mm:ss.zzz') is: " << tm2.toString("hh:mm:ss.zzz") << endl<<endl;
    out<<"\tPress the RETURN key to continue"<<endl;
    getchar();

    /* Test #10 - manipulating QDateTime */
    cdt = QDateTime::currentDateTime();
    out<<"\tThe current datetime is: "<<cdt.toString()<<endl<<endl;
    out<<"\tThe current Gregorian date is: "<<cdt.date().toString(Qt::ISODate)<<endl;
    out<<"\tThe Julian day (wrt Julian period) for the current date is: "<<cdt.date().toJulianDay()<<endl<<endl;
    dt1.setDate(1944,6,6);
    out<<"\tThe Julian day (wrt Julian period) for the D-Day "<<dt1.toString()<<": "<<dt1.toJulianDay()<<endl;
    out<<"\t#Days since the D-Day: "<<(cdt.date().toJulianDay()-dt1.toJulianDay())<<endl;
    dt2.setDate(1776,7,4);
    out<<"\tThe Julian day (wrt Julian period) for the Independence Day "<<dt2.toString()<<": "<<dt2.toJulianDay()<<endl;
    out<<"\t#Days since the D-Day: "<<(cdt.date().toJulianDay()-dt2.toJulianDay())<<endl;
    out<<"\t#Days between the D-Day and the Independence Day: "<<(dt1.toJulianDay()-dt2.toJulianDay())<<endl<<endl;
    out<<"\tPress the RETURN key to continue"<<endl;
    getchar();

    /* Test #11 - UTC time and Unix-time */
    out<<"\tThe current time is: "<<cdt.time().toString()<<endl;
    out<<"\tThe Universal datetime for the current datetime is: "<<cdt.toUTC().toString()<<endl;
    out<<"\tThe local datetime for the current datetime is: "<< cdt.toLocalTime().toString() << endl<<endl;
    t = time(0);
    out <<"\tAt this particular moment (with the Standard C library), "<<t<<" seconds have passed since the Unix epoch ";
    uep=QDateTime::fromTime_t(0);
    out<<uep.toString()<<endl;
    cdt.setTime_t(t);
    out<<"\tDatetime, corresponding to "<<t<<" seconds from the Unix epoch (with the QT Library): "<<cdt.toString()<<endl<<endl;
    if(cdt.isDaylightTime()) out<<"\tThe current datetime fails in the Daylight-Saving Time"<<endl;
    else out<<"\tThe current datetime does not fail in the Daylight-Saving Time"<<endl<<endl;
    out<<"\tThe complete version of the curren datetime is: "<<cdt.toString()<<" "<<cdt.timeZoneAbbreviation()<<" "<<cdt.timeZone().comment()<<" "<<QLocale::countryToString(cdt.timeZone().country())<<endl<<endl;
    return EXIT_SUCCESS;
}
