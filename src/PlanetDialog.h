#ifndef PLANETDIALOG_H
#define PLANETDIALOG_H

#include <QtGui>

#include "SpaceShipDialog.h"
#include "UnitDialog.h"
#include "planet.h"

class PlanetDialog : public QDialog
{
    Q_OBJECT
public:
    PlanetDialog(QWidget *parent = 0);
    PlanetDialog(Planet* planet, QWidget *parent = 0);

private:
    Planet* planet;

    QBoxLayout* pbxLayout;

    QPushButton* spaceShips;
    QMenu* menuSpaceShips;
    QAction* spaceShip;

    QPushButton* units;
    QMenu* menuUnits;
    QAction* unit;

    QPushButton* cancel;

    SpaceShipDialog* spaceShipDialog;
    UnitDialog* unitDialog;

signals:

public slots:
    void createSpaceShipDialog();
    void createUnitDialog();
};

#endif // PLANETDIALOG_H
