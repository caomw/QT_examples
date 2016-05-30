#ifndef CUSTOMWIDGET_H

    #define CUSTOMWIDGET_H

    #include <QWidget>
    #include <QPushButton>

    class CustomWidget : public QWidget
    {
        Q_OBJECT

        public:

        CustomWidget(QWidget *parent = 0);

        virtual ~CustomWidget();

        public slots:

        void enableQuitButton();

        signals:

        void clickedOnQuitButton();

        void clickedOnInfoButton();

        private:

        QPushButton *butt1;

        QPushButton *butt2;

        QPushButton *butt3;

        void initState();
    };

#endif

