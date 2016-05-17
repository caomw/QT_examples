/********************************************************************************************************************************************************
 * David Canino - canino.david@gmail.com
 *
 * Basic examples for the QT Library
 * Github: https://github.com/davidcanino/QT_examples.git
 *
 * This is QT Project file of the basic example for opening a new main window in the current QT Library (Example_0003). No parameter is required.
 *
 * File mainwindow.h - custom interface for new main window (interface). Last update: May 2016
 *******************************************************************************************************************************************************/

#ifndef MAINWINDOW_H

    #define MAINWINDOW_H
    #include <QMainWindow>

    class MainWindow : public QMainWindow
    {
        Q_OBJECT

        public:

        MainWindow(QWidget *parent = 0);

        MainWindow(const QString &tite,QWidget *parent=0);

        virtual ~MainWindow();
    };

#endif
