#ifndef MAIN_WINDOW_H

    #define MAIN_WINDOW_H

    #include <QLabel>
    #include <QPushButton>
    #include <QString>
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

        private:

        QLabel *createLabel(const QString &text);
    };

#endif
