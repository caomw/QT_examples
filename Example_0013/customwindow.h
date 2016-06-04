#ifndef CUSTOMWINDOW_H

    #define CUSTOMWINDOW_H

    #include <QMainWindow>

    class CustomWindow : public QMainWindow
    {
        Q_OBJECT

        public:

        CustomWindow(QWidget *parent = 0);

        virtual ~CustomWindow();

        signals:

        void quit_required();

        void qtinfo_required();

        private slots:

        void toggleStatusBar();

        private:

        QAction *tsb_action;
    };

#endif
