#ifndef CUSTOM_DIALOG_H

    #define CUSTOM_DIALOG_H

    #include <QDialog>
    #include <QDialogButtonBox>
    #include <QTextEdit>
    #include <QMenuBar>
    #include <QMenu>
    #include <QAction>
    #include <QGroupBox>
    #include <QPushButton>
    #include <QLabel>
    #include <QLineEdit>

    class CustomDialog : public QDialog
    {
        Q_OBJECT

        public:

        CustomDialog(QWidget *parent=0);

        virtual ~CustomDialog();

        signals:

        void required_qt_info();

        private:

        void initState();

        void createMenu();

        void createHorizontalGroup();

        void createGridGroup();

        void createFormGroup();

        QDialogButtonBox *bbox;

        QTextEdit *bigEditor;

        QMenuBar *menuBar;

        QMenu *fileMenu;

        QAction *exitAction;

        QAction *qtinfoAction;

        QGroupBox *horizontalGroupBox;

        enum { NumGridRows = 3, NumButtons = 4 };

        QPushButton *buttons[NumButtons];

        QLabel *labels[NumGridRows];

        QLineEdit *lineEdits[NumGridRows];

        QGroupBox *gridGroupBox;

        QGroupBox *formGroupBox;

        QTextEdit *smallEditor;
    };

#endif
