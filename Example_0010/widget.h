#ifndef CUSTOMWIDGET_H

    #define CUSTOMWIDGET_H

    #include <QWidget>
    #include <QLCDNumber>
    #include <QPushButton>
    #include<QSpinBox>
    #include<QLabel>

    class Widget : public QWidget
    {
        Q_OBJECT

        public:

        Widget(QWidget *parent = 0);

        virtual ~Widget();

        public slots:

        void buttonPressed(QString lab);

        signals:

        void clickedOnQuitButton();

        void clickedOnInfoButton();

        private:

        QLCDNumber *ris;

        QPushButton *info_butt;

        QPushButton *quit_butt;

        QPushButton *plus_butt;

        QPushButton *minus_butt;

        QPushButton *mult_butt;

        QPushButton *div_butt;

        QSpinBox *box_num1;

        QSpinBox *box_num2;

        QLabel *err_msg;

        void initState();
    };

#endif
