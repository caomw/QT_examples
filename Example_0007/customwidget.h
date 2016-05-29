/*************************************************************************************************************************
 * David Canino - canino.david@gmail.com
 *
 * Basic examples for the QT Library
 * Github: https://github.com/davidcanino/QT_examples.git
 *
 * Another basic example for QWidgets. No parameter is required.
 *
 * Definition of a custom widget.
 *
 * Last update: May 2016
 *************************************************************************************************************************/

#ifndef CUSTOMWIDGET_H

    #define CUSTOMWIDGET_H

    #include <QWidget>

    class CustomWidget : public QWidget
    {
        Q_OBJECT

        public:

        CustomWidget(QWidget *parent = 0);

        inline virtual ~CustomWidget() { ; }
    };

#endif
