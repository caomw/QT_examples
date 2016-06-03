#include <customdialog.h>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QComboBox>
#include <QSpinBox>

CustomDialog :: CustomDialog(QWidget *parent) : QDialog(parent)
{
    this->initState();

    /* Creating intermediate panels! */
    this->createMenu();
    this->createHorizontalGroup();
    this->createGridGroup();
    this->createFormGroup();

    /* Creating bottom 'bigEditor' */
    this->bigEditor=new QTextEdit();
    bigEditor->setPlainText(tr("Only the 'Ok' and 'Cancel' buttons are connected to the slots."));
    this->bigEditor->setReadOnly(true);

    /* Creating final buttons 'ok' and 'cancel' */
    this->bbox= new QDialogButtonBox(QDialogButtonBox::Cancel | QDialogButtonBox::Ok);
    connect(bbox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(bbox, SIGNAL(rejected()), this, SLOT(reject()));

    /* Creating vertical box layout and finalizing everything! */
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setMenuBar(this->menuBar);
    mainLayout->addWidget(this->horizontalGroupBox);
    mainLayout->addWidget(this->gridGroupBox);
    mainLayout->addWidget(this->formGroupBox);
    mainLayout->addWidget(this->bigEditor);
    mainLayout->addWidget(this->bbox);
    this->setLayout(mainLayout);
}

CustomDialog::~CustomDialog()
{
    if(this->bbox!=NULL) delete this->bbox;
    if(this->bigEditor!=NULL) delete this->bigEditor;
    for(int i = 0; i < NumButtons; ++i) if(this->buttons[i]!=NULL) delete this->buttons[i];
    for(int i = 0; i < NumGridRows; ++i)
    {
        if(this->labels[i]!=NULL) delete this->labels[i];
        if(this->lineEdits[i]!=NULL) delete this->lineEdits[i];
    }

    this->initState();
}

void CustomDialog::initState()
{
    this->bbox=NULL;
    this->bigEditor=NULL;
    this->menuBar=NULL;
    this->fileMenu=NULL;
    this->exitAction=NULL;
    this->qtinfoAction=NULL;
    this->horizontalGroupBox=NULL;
    for(int i = 0; i < NumButtons; ++i) this->buttons[i]=NULL;
    for(int i = 0; i < NumGridRows; ++i)
    {
        this->labels[i]=NULL;
        this->lineEdits[i]=NULL;
    }
}

void CustomDialog::createMenu()
{
    this->menuBar=new QMenuBar();
    this->fileMenu=new QMenu(tr("&File"), this->menuBar);
    this->menuBar->addMenu(this->fileMenu);
    this->exitAction=this->fileMenu->addAction(tr("E&xit"));
    connect(this->exitAction, SIGNAL(triggered()), this, SLOT(accept()));
    this->qtinfoAction=this->fileMenu->addAction(tr("About QT"));
    connect(this->qtinfoAction, SIGNAL(triggered()), this, SIGNAL(required_qt_info()));
}

void CustomDialog::createHorizontalGroup()
{
    QHBoxLayout *layout;

    /* Creating buttons! */
    layout = new QHBoxLayout();
    for(int i = 0; i < NumButtons; ++i)
    {
        this->buttons[i] = new QPushButton(tr("Button %1").arg(i + 1));
        layout->addWidget(this->buttons[i]);
    }

    /* Finalizing the group! */
    this->buttons[NumButtons-1]->setText("About QT");
    connect(this->buttons[NumButtons-1], SIGNAL(clicked()), this, SIGNAL(required_qt_info()));
    this->horizontalGroupBox = new QGroupBox(tr("Horizontal layout"));
    this->horizontalGroupBox->setLayout(layout);
}

void CustomDialog::createGridGroup()
{
    QGridLayout *layout;

    layout = new QGridLayout();
    for (int i = 0; i < NumGridRows; ++i)
    {
        this->labels[i] = new QLabel(tr("Line %1:").arg(i + 1));
        this->lineEdits[i] = new QLineEdit();
        layout->addWidget(this->labels[i], i + 1, 0);
        layout->addWidget(this->lineEdits[i], i + 1, 1);
    }

    this->smallEditor = new QTextEdit;
    this->smallEditor->setPlainText(tr("This widget takes up about two thirds of the grid layout."));
    this->smallEditor->setReadOnly(true);
    layout->addWidget(this->smallEditor, 0, 2, 4, 1);

    /* Finalyzing the group! */
    this->gridGroupBox = new QGroupBox(tr("Grid layout"));
    layout->setColumnStretch(1, 10);
    layout->setColumnStretch(2, 20);
    this->gridGroupBox->setLayout(layout);
}

void CustomDialog::createFormGroup()
{
    QFormLayout *layout;

    layout=new QFormLayout;
    layout->addRow(new QLabel(tr("Line 1:")), new QLineEdit);
    layout->addRow(new QLabel(tr("Line 2:")), new QComboBox);
    layout->addRow(new QLabel(tr("Line 3:")), new QSpinBox);
    this->formGroupBox = new QGroupBox(tr("Form layout"));
    this->formGroupBox->setLayout(layout);
}
