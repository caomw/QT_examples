#include "borderlayout.h"
#include "mainwindow.h"
#include <QTextBrowser>
#include <QFrame>
#include <QVBoxLayout>
#include <QBoxLayout>

MainWindow::MainWindow()
{
    QPushButton *quit_button,*qtinfo_button;
    QTextBrowser *textBrowser;
    BorderLayout *blayout;
    QVBoxLayout *vbox;
    QFrame *cbox;

    /* Now, we construct the central widget! */
    cbox=new QFrame;
    textBrowser=new QTextBrowser;
    textBrowser->setPlainText(tr("This is a custom example of BorderLayout"));
    textBrowser->setReadOnly(true);
    qtinfo_button=new QPushButton(tr("About QT"));
    quit_button=new QPushButton(tr("Quit"));
    connect(qtinfo_button,SIGNAL(clicked()),this,SIGNAL(qtinfo_required()));
    connect(quit_button,SIGNAL(clicked()),this,SIGNAL(quit_required()));
    vbox=new QVBoxLayout();
    vbox->addWidget(textBrowser);
    cbox->setLayout(vbox);
    vbox->addWidget(qtinfo_button);
    vbox->addWidget(quit_button);

    blayout= new BorderLayout;
    blayout->addWidget(cbox,BorderLayout::Center);
    blayout->addWidget(createLabel("Northern Space"), BorderLayout::North);
    blayout->addWidget(createLabel("Western Space"), BorderLayout::West);
    blayout->addWidget(createLabel("Southern Space"), BorderLayout::South);
    blayout->addWidget(createLabel("Eastern Space"), BorderLayout::East);
    this->setLayout(blayout);
}

MainWindow::~MainWindow() { ; }

QLabel * MainWindow::createLabel(const QString &text)
{
    QLabel *label;

    label = new QLabel(text);
    label->setFrameStyle(QFrame::Box | QFrame::Raised);
    return label;
}
