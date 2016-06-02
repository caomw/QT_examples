#ifndef WIDGET_H

    #define WIDGET_H

    #include <QLCDNumber>

    class Widget : public QLCDNumber
    {
        Q_OBJECT

        public:

        Widget(QWidget *parent = 0);

        inline virtual ~Widget() { ; }

        private slots:

        void showTime();
    };

#endif
