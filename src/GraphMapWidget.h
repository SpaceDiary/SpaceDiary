#ifndef GRAPHMAPWIDGET_H
#define GRAPHMAPWIDGET_H

#include <QtGui>
#include "MapWidget.h"
class MapWidget;

class GraphMapWidget : public QWidget
{
    Q_OBJECT

    public:
        GraphMapWidget(MapWidget *mw = 0);
        void paintEvent(QPaintEvent*);

    private:
        MapWidget* mw;
        QPalette pal1;
        QBoxLayout* pbxLayout;
};

#endif // GRAPHMAPWIDGET_H
