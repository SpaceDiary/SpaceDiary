#include "SectorWidget.h"

SectorWidget::SectorWidget(QWidget *parent) : QWidget(parent)
{

}

SectorWidget::SectorWidget(Sector* sector, QWidget *parent) : QWidget(parent)
{
    SectorWidget::sector=sector;

    QPalette pal1;
    pal1.setColor(this->backgroundRole(), Qt::white);
    this->setPalette(pal1);
    this->setAutoFillBackground(true);
    this->setObjectName("sectorWidget");
    pbxLayout = new QBoxLayout(QBoxLayout::TopToBottom);
    this->setLayout(pbxLayout);

    lSector = new QLabel(sector->getName());
    pbxLayout->addWidget(lSector);
}

void SectorWidget::mousePressEvent(QMouseEvent*)
{
    sectorDialog = new SectorDialog(sector);
    sectorDialog->show();
}


