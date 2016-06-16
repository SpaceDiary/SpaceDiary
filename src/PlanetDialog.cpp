#include "PlanetDialog.h"

PlanetDialog::PlanetDialog(QWidget* pwgt/*= 0*/)
    : QDialog(pwgt, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
{

}

PlanetDialog::PlanetDialog(Planet* planet, QWidget* pwgt/*= 0*/) : QDialog(pwgt, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
{
    PlanetDialog::planet=planet;

    QString s;
    if (planet->getResource()==0)
        s="Life energy";
    if (planet->getResource()==1)
        s="Distruction energy";
    if (planet->getResource()==2)
        s="Struction energy";

    this->setModal(true);
    pbxLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    //pbxLayout->setGeometry(0, 0, 0, 0);
    this->setLayout(pbxLayout);
    this->setMinimumSize(200, 200);
    setWindowTitle(planet->getName());

    QLabel* label = new QLabel(s);
    pbxLayout->addWidget(label);

    spaceShips = new QPushButton("SpaceShips");
    pbxLayout->addWidget(spaceShips);
    spaceShips->setObjectName("spaceShips");
    menuSpaceShips = new QMenu();
    spaceShips->setMenu(menuSpaceShips);

    units = new QPushButton("Units");
    pbxLayout->addWidget(units);
    units->setObjectName("units");
    menuUnits = new QMenu();
    units->setMenu(menuUnits);

    for (int i=0; i<planet->getSpaceShips().size(); i++)
    {
        spaceShip = new QAction(planet->getSpaceShips().at(i)->getName(), spaceShips);
        spaceShip->setObjectName(QString::number(i));
        QObject::connect(spaceShip, SIGNAL(triggered()), this, SLOT(createSpaceShipDialog()));
        menuSpaceShips->addAction(spaceShip);
    }

    for (int i=0; i<planet->getUnits().size(); i++)
    {
        unit = new QAction(planet->getUnits().at(i)->getName(), units);
        unit->setObjectName(QString::number(i));
        QObject::connect(unit, SIGNAL(triggered()), this, SLOT(createUnitDialog()));
        menuUnits->addAction(unit);
    }

    cancel = new QPushButton("Cancel");
    pbxLayout->addWidget(cancel);
    cancel->setObjectName("cancel");
    QObject::connect(this->findChild<QObject*>("cancel"), SIGNAL(clicked()), this, SLOT(hide()));

}

void PlanetDialog::createSpaceShipDialog()
{
    spaceShipDialog=new SpaceShipDialog(PlanetDialog::planet->getSpaceShips().at((sender()->objectName().toInt())));
    spaceShipDialog->show();
}

void PlanetDialog::createUnitDialog()
{
    unitDialog=new UnitDialog(PlanetDialog::planet->getUnits().at((sender()->objectName().toInt())));
    unitDialog->show();
}
