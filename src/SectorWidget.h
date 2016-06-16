#ifndef SECTORWIDGET_H
#define SECTORWIDGET_H

#include <QtGui>

#include "SectorDialog.h"
#include "sector.h"

class SectorWidget : public QWidget
{
    Q_OBJECT
public:
    SectorWidget(QWidget *parent = 0);
    SectorWidget(Sector* sector, QWidget *parent = 0);

protected:
    virtual void mousePressEvent(QMouseEvent* pe);

private:
    Sector* sector;

    QBoxLayout* pbxLayout;
    QLabel* lSector;
    SectorDialog* sectorDialog;
};

#endif // SECTORWIDGET_H
