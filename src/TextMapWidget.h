#ifndef TEXTMAPWIDGET_H
#define TEXTMAPWIDGET_H

#include <QtGui>

#include "SectorWidget.h"
#include "sector.h"

class TextMapWidget : public QWidget
{
    Q_OBJECT

    public:
        TextMapWidget(QWidget *parent = 0);
        TextMapWidget(QList<Sector*> sectors, QWidget *parent = 0);

    private:
        QList<Sector*> sectors;

        QPalette pal1;
        QBoxLayout* pbxLayout;
        SectorWidget* sectorWidget;
};

#endif // TEXTMAPWIDGET_H
