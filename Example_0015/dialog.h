#ifndef DIALOG_H

    #define DIALOG_H

    #include <QDialog>
    #include "cardlayout.h"

    class Dialog : public QDialog
    {
        Q_OBJECT

        public:

        Dialog(QWidget *parent = 0);

        virtual ~Dialog();

        signals:

        void quit_required();

        void qtinfo_required();

        private:

        CardLayout *clayout;

        private slots:

        void showItem(int ind);
    };

#endif
