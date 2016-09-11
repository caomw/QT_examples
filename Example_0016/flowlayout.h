#ifndef FLOW_LAYOUT_H

    #define FLOW_LAYOUT_H

    #include <QLayout>
    #include <QList>
    #include <QRect>
    #include <QStyle>

    class FlowLayout : public QLayout
    {
        public:

        explicit FlowLayout(QWidget *parent, int margin = -1, int hSpacing = -1, int vSpacing = -1);

        explicit FlowLayout(int margin = -1, int hSpacing = -1, int vSpacing = -1);

        virtual ~FlowLayout();

        void addItem(QLayoutItem *item) Q_DECL_OVERRIDE;

        int count() const Q_DECL_OVERRIDE;

        QLayoutItem *itemAt(int index) const Q_DECL_OVERRIDE;

        QLayoutItem *takeAt(int index) Q_DECL_OVERRIDE;

        Qt::Orientations expandingDirections() const Q_DECL_OVERRIDE;

        QSize sizeHint() const Q_DECL_OVERRIDE;

        bool hasHeightForWidth() const Q_DECL_OVERRIDE;

        int horizontalSpacing() const;

        int verticalSpacing() const;

        int heightForWidth(int) const Q_DECL_OVERRIDE;

        QSize minimumSize() const Q_DECL_OVERRIDE;

        void setGeometry(const QRect &rect) Q_DECL_OVERRIDE;

        private:

        QList< QLayoutItem * > items;

        int m_hSpace;

        int m_vSpace;

        int doLayout(const QRect &rect, bool testOnly) const;

        int smartSpacing(QStyle::PixelMetric pm) const;
    };

#endif