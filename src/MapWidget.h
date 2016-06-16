#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include "TextMapWidget.h"
#include "GraphMapWidget.h"
#include "sector.h"
#include "widget.h"

#include <QtGui>

class Widget;
class GraphMapWidget;

class MapWidget : public QWidget
{
        Q_OBJECT

        public:
            MapWidget(QWidget *parent = 0);
            MapWidget(QList<Sector*>, Widget *widget = 0);
            Widget* getWidget() {return widget;}

        private:
            Widget* widget;
            QList<Sector*> sectors;

            QPalette pal1;
            QBoxLayout* pbxLayout;
            QPalette pall;
            TextMapWidget* tmw;
            GraphMapWidget* gmw;
};

#endif // MAPWIDGET_H
