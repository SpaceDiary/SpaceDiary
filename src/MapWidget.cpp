#include "MapWidget.h"

MapWidget::MapWidget(QWidget *parent)
    : QWidget(parent)
{

}

MapWidget::MapWidget(QList<Sector*> sectors, Widget *widget)
    : QWidget()
{
    this->widget=widget;

    pal1.setColor(this->backgroundRole(), Qt::gray);
    this->setPalette(pal1);
    this->setAutoFillBackground(true);
    this->setObjectName("mw");
    pbxLayout = new QBoxLayout(QBoxLayout::LeftToRight);

    MapWidget::sectors=sectors;

    tmw = new TextMapWidget(sectors, this);
    pbxLayout->addWidget(tmw, 1);

    gmw = new GraphMapWidget(this);
    pbxLayout->addWidget(gmw, 1);
    //gmw->hide();





    this->setLayout(pbxLayout);

}


