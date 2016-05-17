/********************************************************************************************************************************************************
 * David Canino - canino.david@gmail.com
 *
 * Basic examples for the QT Library
 * Github: https://github.com/davidcanino/QT_examples.git
 *
 * This is QT Project file of the basic example for opening a new main window in the current QT Library (Example_0003). No parameter is required.
 *
 * File mainwindow.cpp - custom interface for new main window (implementation). Last update: May 2016
 *******************************************************************************************************************************************************/

#include "mainwindow.h"
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->setToolTip(QString("tooltip is not initialized"));
    this->setToolTip(QString("tooltip is not initialized"));
    this->setToolTipDuration(2000);
}

MainWindow::MainWindow(const QString &title,QWidget *parent) : QMainWindow(parent)
{
    this->setWindowTitle(title);
    this->setToolTip(title);
    this->setToolTipDuration(2000);
}

MainWindow::~MainWindow() { ; }

