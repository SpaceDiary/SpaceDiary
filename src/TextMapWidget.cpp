#include "TextMapWidget.h"

TextMapWidget::TextMapWidget(QWidget *parent) : QWidget(parent)
{

}

TextMapWidget::TextMapWidget(QList<Sector*> sectors, QWidget *parent) : QWidget(parent)
{
    TextMapWidget::sectors=sectors;

    pal1.setColor(this->backgroundRole(), Qt::green);
    this->setPalette(pal1);
    this->setAutoFillBackground(true);
    this->setObjectName("mw");

    pbxLayout = new QBoxLayout(QBoxLayout::TopToBottom);
    this->setLayout(pbxLayout);

    for (int i=0; i<sectors.size(); i++)
    {
        sectorWidget = new SectorWidget(sectors.at(i), this);
        pbxLayout->addWidget(sectorWidget, 1);
    }
}



