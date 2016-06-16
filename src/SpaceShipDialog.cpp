#include "SpaceShipDialog.h"

SpaceShipDialog::SpaceShipDialog(QWidget* pwgt/*= 0*/)
    : QDialog(pwgt, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
{

}

SpaceShipDialog::SpaceShipDialog(SpaceShip* spaceShip, QWidget* pwgt/*= 0*/) : QDialog(pwgt, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
{
    SpaceShipDialog::spaceShip=spaceShip;

    this->setModal(true);
    pbxLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    this->setLayout(pbxLayout);
    this->setMinimumSize(200, 200);
    setWindowTitle(spaceShip->getName());
    skillsLayout = new QBoxLayout(QBoxLayout::TopToBottom);
    pbxLayout->addLayout(skillsLayout);

    QString sLifeSupport;
    sLifeSupport="LifeSupport="+QString::number(spaceShip->getLifeSupport());
    QLabel* lifeSupportLabel = new QLabel(sLifeSupport);
    skillsLayout->addWidget(lifeSupportLabel);

    QString sWeapon;
    sWeapon="Weapon="+QString::number(spaceShip->getWeapon());
    QLabel* weaponLabel = new QLabel(sWeapon);
    skillsLayout->addWidget(weaponLabel);

    QString sArmor;
    sArmor="Armor="+QString::number(spaceShip->getArmor());
    QLabel* armorLabel = new QLabel(sArmor);
    skillsLayout->addWidget(armorLabel);

    units = new QPushButton("Units");
    pbxLayout->addWidget(units);
    units->setObjectName("units");
    menuUnits = new QMenu();
    units->setMenu(menuUnits);

    for (int i=0; i<spaceShip->getUnits().size(); i++)
    {
        unit = new QAction(spaceShip->getUnits().at(i)->getName(), units);
        unit->setObjectName(QString::number(i));
        QObject::connect(unit, SIGNAL(triggered()), this, SLOT(createUnitDialog()));
        menuUnits->addAction(unit);
    }

    cancel = new QPushButton("Cancel");
    pbxLayout->addWidget(cancel);
    cancel->setObjectName("cancel");
    QObject::connect(this->findChild<QObject*>("cancel"), SIGNAL(clicked()), this, SLOT(hide()));
}

void SpaceShipDialog::createUnitDialog()
{
    unitDialog=new UnitDialog(spaceShip->getUnits().at((sender()->objectName()).toInt()));
    unitDialog->show();
}
