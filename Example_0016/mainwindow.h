#ifndef MAIN_WINDOW_H

    #define MAIN_WINDOW_H

    #include <QWidget>

    class MainWindow : public QWidget
    {
        Q_OBJECT

        public:

        MainWindow();

        virtual ~MainWindow();

        signals:

        void quit_required();

        void qtinfo_required();
    };

#endif
