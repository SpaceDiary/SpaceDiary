#ifndef SPACESHIPDIALOG_H
#define SPACESHIPDIALOG_H

#include <QtGui>

#include "UnitDialog.h"
#include "spaceship.h"

class SpaceShipDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SpaceShipDialog(QWidget *parent = 0);
    SpaceShipDialog(SpaceShip* spaceShip, QWidget *parent = 0);

private:
    SpaceShip* spaceShip;

    QBoxLayout* pbxLayout;
    QBoxLayout* skillsLayout;

    QPushButton* units;
    QMenu* menuUnits;
    QAction* unit;

    QPushButton* cancel;

    UnitDialog* unitDialog;
    
signals:
    
public slots:
    void createUnitDialog();
    
};

#endif // SPACESHIPDIALOG_H
