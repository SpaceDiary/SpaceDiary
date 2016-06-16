#ifndef SECTORDIALOG_H
#define SECTORDIALOG_H

#include <QtGui>

#include "PlanetDialog.h"
#include "SpaceSectorDialog.h"
#include "sector.h"


class SectorDialog : public QDialog
{
    Q_OBJECT
public:
    SectorDialog(QWidget *parent = 0);
    SectorDialog(Sector*, QWidget *parent = 0);

private:
    Sector* sector;

    QBoxLayout* pbxLayout;
    QBoxLayout* waysLayout;

    QPushButton* spaceSector;
    QPushButton* planetSectors;
    QMenu* menuPlanets;
    QPushButton* cancel;

    SpaceSectorDialog* spaceSectorDialog;
    PlanetDialog* planetDialog;
    Planet* tempPlanet;

signals:

public slots:
    void createSpaceSectorDialog();
    void createPlanetDialog();
};

#endif // SECTORDIALOG_H
