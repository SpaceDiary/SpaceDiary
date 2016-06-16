#ifndef SPACESECTORDIALOG_H
#define SPACESECTORDIALOG_H

#include <QtGui>

#include "SpaceShipDialog.h"
#include "UnitDialog.h"
#include "spacesector.h"

class SpaceSectorDialog : public QDialog
{
    Q_OBJECT
public:
    SpaceSectorDialog(QWidget *parent = 0);
    SpaceSectorDialog(SpaceSector* spaceSector, QWidget *parent = 0);

private:
    SpaceSector* spaceSector;

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

#endif // SPACESECTORDIALOG_H
