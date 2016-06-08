#include "dialog.h"
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QComboBox>

Dialog::Dialog(QWidget *parent) : QDialog(parent)
{
    QVBoxLayout *vbox;
    QFrame *box;
    QPushButton *quit_button,*qtinfo_button;
    QComboBox *cbox;

    /* We create box with the CardLayout! */
    box=new QFrame(this);
    this->clayout=new CardLayout(this);
    this->clayout->addWidget(new QLabel("Generic Message",this));
    this->clayout->itemAt(0)->widget()->setVisible(true);
    qtinfo_button=new QPushButton(tr("About QT"),this);
    connect(qtinfo_button,SIGNAL(clicked()),this,SIGNAL(qtinfo_required()));
    this->clayout->addWidget(qtinfo_button);
    this->clayout->itemAt(1)->widget()->setVisible(false);
    quit_button=new QPushButton(tr("Quit"),this);
    connect(quit_button,SIGNAL(clicked()),this,SIGNAL(quit_required()));
    this->clayout->addWidget(quit_button);
    this->clayout->itemAt(2)->widget()->setVisible(false);
    box->setLayout(this->clayout);

    /* Now, we create the combo box! */
    cbox=new QComboBox();
    cbox->addItem("Generic Message");
    cbox->addItem("About QT button");
    cbox->addItem("Quit button");
    cbox->setCurrentIndex(0);
    connect(cbox,SIGNAL(activated(int)),this,SLOT(showItem(int)));

    /* We finalize everything! */
    vbox=new QVBoxLayout();
    vbox->addWidget(new QLabel("Choose what widget you want to visualize ..."));
    vbox->addWidget(cbox);
    vbox->addWidget(box);
    this->setLayout(vbox);
}

Dialog::~Dialog() { ; }

void Dialog::showItem(int ind)
{
    for(int k=0;k<ind;k++) this->clayout->itemAt(k)->widget()->setVisible(false);
    this->clayout->itemAt(ind)->widget()->setVisible(true);
    for(int k=ind+1;k<this->clayout->count();k++) this->clayout->itemAt(k)->widget()->setVisible(false);
}
