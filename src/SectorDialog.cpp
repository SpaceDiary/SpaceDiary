#include "SectorDialog.h"

SectorDialog::SectorDialog(QWidget* pwgt/*= 0*/)
    : QDialog(pwgt, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
{

}

SectorDialog::SectorDialog(Sector* sector, QWidget* pwgt/*= 0*/) : QDialog(pwgt, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
{
    SectorDialog::sector=sector;

    this->setModal(true);
    pbxLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    this->setLayout(pbxLayout);
    this->setMinimumSize(300, 300);

    waysLayout = new QBoxLayout(QBoxLayout::TopToBottom);
    pbxLayout->addLayout(waysLayout);

    for (int i=0; i<sector->getWays().size(); i++)
    {
        QString s = sector->getWays().at(i);
        QLabel* label = new QLabel(s);
        waysLayout->addWidget(label);

    }

    spaceSector = new QPushButton("SpaceSector");
    pbxLayout->addWidget(spaceSector);
    spaceSector->setObjectName("spaceSector");
    QObject::connect(this->findChild<QObject*>("spaceSector"), SIGNAL(clicked()), this, SLOT(createSpaceSectorDialog()));

    planetSectors = new QPushButton("PlanetSectors");
    pbxLayout->addWidget(planetSectors);
    planetSectors->setObjectName("planetSectors");
    menuPlanets = new QMenu();
    planetSectors->setMenu(menuPlanets);

    for (int i=0; i<sector->getPlanets().size(); i++)
    {
        tempPlanet = sector->getPlanets().at(i);
        QString s = tempPlanet->getName();
        QAction* action = new QAction(s, planetSectors);
        menuPlanets->addAction(action);
        action->setObjectName(s);
        QObject::connect(this->findChild<QObject*>(s), SIGNAL(triggered()), this, SLOT(createPlanetDialog()));

    }


    cancel = new QPushButton("Cancel");
    pbxLayout->addWidget(cancel);
    cancel->setObjectName("cancel");
    QObject::connect(this->findChild<QObject*>("cancel"), SIGNAL(clicked()), this, SLOT(hide()));

    setWindowTitle(sector->getName());

}

void SectorDialog::createSpaceSectorDialog()
{
    spaceSectorDialog = new SpaceSectorDialog(sector->getSpaceSector());
    spaceSectorDialog->show();
}

void SectorDialog::createPlanetDialog()
{
    planetDialog = new PlanetDialog(tempPlanet);
    planetDialog->show();
}
