#include "SpaceSectorDialog.h"

SpaceSectorDialog::SpaceSectorDialog(QWidget* pwgt/*= 0*/)
    : QDialog(pwgt, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
{

}

SpaceSectorDialog::SpaceSectorDialog(SpaceSector* spaceSector, QWidget* pwgt/*= 0*/) : QDialog(pwgt, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
{
    SpaceSectorDialog::spaceSector=spaceSector;

    this->setModal(true);
    pbxLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    this->setLayout(pbxLayout);
    this->setMinimumSize(200, 200);
    setWindowTitle(spaceSector->getName());

    spaceShips = new QPushButton("SpaceShips");
    pbxLayout->addWidget(spaceShips, 1);
    spaceShips->setObjectName("spaceShips");
    menuSpaceShips = new QMenu();
    spaceShips->setMenu(menuSpaceShips);

    units = new QPushButton("Units");
    pbxLayout->addWidget(units);
    units->setObjectName("units");
    menuUnits = new QMenu();
    units->setMenu(menuUnits);

    for (int i=0; i<spaceSector->getSpaceShips().size(); i++)
    {
        spaceShip = new QAction(spaceSector->getSpaceShips().at(i)->getName(), spaceShips);
        spaceShip->setObjectName(QString::number(i));
        QObject::connect(spaceShip, SIGNAL(triggered()), this, SLOT(createSpaceShipDialog()));
        menuSpaceShips->addAction(spaceShip);
    }

    for (int i=0; i<spaceSector->getUnits().size(); i++)
    {
        unit = new QAction(spaceSector->getUnits().at(i)->getName(), units);
        unit->setObjectName(QString::number(i));
        QObject::connect(unit, SIGNAL(triggered()), this, SLOT(createUnitDialog()));
        menuUnits->addAction(unit);
    }

    cancel = new QPushButton("Cancel");
    pbxLayout->addWidget(cancel);
    cancel->setObjectName("cancel");
    QObject::connect(this->findChild<QObject*>("cancel"), SIGNAL(clicked()), this, SLOT(hide()));

}

void SpaceSectorDialog::createSpaceShipDialog()
{
    spaceShipDialog=new SpaceShipDialog(SpaceSectorDialog::spaceSector->getSpaceShips().at((sender()->objectName().toInt())));
    spaceShipDialog->show();
}

void SpaceSectorDialog::createUnitDialog()
{
    unitDialog=new UnitDialog(SpaceSectorDialog::spaceSector->getUnits().at((sender()->objectName().toInt())));
    unitDialog->show();
}
