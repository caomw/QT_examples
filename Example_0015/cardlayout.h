#ifndef CARDLAYOUT_H

    #define CARDLAYOUT_H

    #include "QLayout"
    #include "QList"

    class CardLayout : public QLayout
    {
        public:

        CardLayout(QWidget *parent);

        virtual ~CardLayout();

        void addItem(QLayoutItem *item);

        void addWidget(QWidget *widget);

        QSize sizeHint() const;

        QSize minimumSize() const;

        int count() const;

        QLayoutItem *itemAt(int idx) const;

        QLayoutItem *takeAt(int);

        void setGeometry(const QRect &r);

        private:

        QList<QLayoutItem*> list;
    };

#endif
