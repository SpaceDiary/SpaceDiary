#include "spaceship.h"

SpaceShip::SpaceShip()
{

}

SpaceShip::SpaceShip(QString name, SpaceSector* spaceSector)
{
    this->spaceSector=spaceSector;
    SpaceShip::name = name;
    QFile fSpaceShip(name+".txt");
    if (fSpaceShip.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&fSpaceShip);
        int i=0;
        while (!stream.atEnd())
        {
            QString str = stream.readLine();
            if (i==0)
                lifeSupport=str[0].digitValue();
            if (i==1)
                weapon=str[0].digitValue();
            if (i==2)
                armor=str[0].digitValue();
            if (str[0]=='U')
            {
                Unit* unit = new Unit(str, this);
                units.append(unit);
            }
            i++;
        }
        fSpaceShip.close();
    }
}

SpaceShip::SpaceShip(QString name, Planet* planet)
{
    this->planet=planet;
    SpaceShip::name = name;
    QFile fSpaceShip(name+".txt");
    if (fSpaceShip.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&fSpaceShip);
        int i=0;
        while (!stream.atEnd())
        {
            QString str = stream.readLine();
            if (i==0)
                lifeSupport=str[0].digitValue();
            if (i==1)
                weapon=str[0].digitValue();
            if (i==2)
                armor=str[0].digitValue();
            if (str[0]=='U')
            {
                Unit* unit = new Unit(str, this);
                units.append(unit);
            }
            i++;
        }
        fSpaceShip.close();
    }
}

void SpaceShip::save()
{
    QFile fSpaceShip(name+".txt");
    if (fSpaceShip.open(QIODevice::WriteOnly))
    {
        QTextStream stream(&fSpaceShip);
        QString str;
        str=QString::number(lifeSupport);
        stream<<str<<endl;
        qDebug()<<str;
        str=QString::number(weapon);
        stream<<str<<endl;
        qDebug()<<str;
        str=QString::number(armor);
        stream<<str<<endl;
        qDebug()<<str;
        for (int i=0; i<units.size(); i++)
        {
            str = units.at(i)->getName();
            stream << str<<endl;
            qDebug()<<str;
            units.at(i)->save();
        }
        fSpaceShip.close();
    }
}

void SpaceShip::period()
{
    for (int i=0; i<units.size(); i++)
    {
        units.at(i)->period();
        if (units.at(i)->getAge()==6)
        {
            units.removeOne(units.at(i));
        }
    }
}

bool SpaceShip::checkUnitName(QString name)
{
    for (int i=0; i<units.size(); i++)
    {
        if (units.at(i)->checkUnitName(name)) return true;
    }

    return false;
}

void SpaceShip::breed(int race)
{
    QString sRace;
    if (race==1) sRace="Amazon";
    if (race==2) sRace="Witch";
    if (race==4) sRace="Clone";
    if (race==5) sRace="Monkey";
    label:
    QString name = "Unit " + QInputDialog::getText(0, "You have a new unit on " + this->name, "Baby "+ sRace + " Unit", QLineEdit::Normal);
    if (this->getPlanet())
    {
        if (this->getPlanet()->getSector()->getModel()->checkUnitName(name))
        {
            QMessageBox::critical(0, "This name already exists", "Please, choose another name for your new unit", QMessageBox::Cancel);
            goto label;
        }
    }
    if (this->getSpaceSector())
    {
        if (this->getSpaceSector()->getSector()->getModel()->checkUnitName(name))
        {
            QMessageBox::critical(0, "This name already exists", "Please, choose another name for your new unit", QMessageBox::Cancel);
            goto label;
        }
    }
    Unit* unit = new Unit();
    unit->setRace(race);
    unit->setName(name);
    unit->setAge(0);
    unit->setSpaceShip(this);
    units.append(unit);
}
