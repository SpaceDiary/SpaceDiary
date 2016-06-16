#include "planet.h"

Planet::Planet()
{

}

Planet::Planet(QString name, Sector* sector)
{
    this->sector=sector;
    Planet::name = name;
    QFile fPlanet(name+".txt");
    if (fPlanet.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&fPlanet);
        QString str = stream.readLine();
        resource=str.toInt();
        while (!stream.atEnd())
        {
            str = stream.readLine();
            if (str[0]=='S')
            {
                SpaceShip* spaceShip = new SpaceShip(str, this);
                spaceShips.append(spaceShip);
            }
            if (str[0]=='U')
            {
                Unit* unit = new Unit(str, this);
                units.append(unit);
            }
        }
        fPlanet.close();
    }
}

void Planet::save()
{
    QFile fPlanet(name+".txt");
    if (fPlanet.open(QIODevice::WriteOnly))
    {
        QTextStream stream(&fPlanet);
        QString str;
        str=QString::number(resource);
        stream << str<<endl;
        qDebug()<<str;
        for (int i=0; i<units.size(); i++)
        {
            str = units.at(i)->getName();
            stream << str<<endl;
            qDebug()<<str;
            units.at(i)->save();
        }
        for (int i=0; i<spaceShips.size(); i++)
        {
            str = spaceShips.at(i)->getName();
            stream << str<<endl;
            qDebug()<<str;
            spaceShips.at(i)->save();
        }
        fPlanet.close();
    }
}

void Planet::period()
{
    for (int i=0; i<spaceShips.size(); i++)
    {
        spaceShips.at(i)->period();
    }

    for (int i=0; i<units.size(); i++)
    {
        units.at(i)->period();
        if (units.at(i)->getAge()==6)
        {
            units.removeOne(units.at(i));
        }
    }
}

bool Planet::checkUnitName(QString name)
{
    for (int i=0; i<spaceShips.size(); i++)
    {
        if (spaceShips.at(i)->checkUnitName(name)) return true;
    }

    for (int i=0; i<units.size(); i++)
    {
        if (units.at(i)->checkUnitName(name)) return true;
    }

    return false;
}

void Planet::breed(int race)
{
    QString sRace;
    if (race==1) sRace="Amazon";
    if (race==2) sRace="Witch";
    if (race==4) sRace="Clone";
    if (race==5) sRace="Monkey";
    label:
    QString name = "Unit " + QInputDialog::getText(0, "You have a new unit on " + this->name, "Baby "+ sRace + " Unit", QLineEdit::Normal);
    if (this->getSector()->getModel()->checkUnitName(name))
    {
        QMessageBox::critical(0, "This name already exists", "Please, choose another name for your new unit", QMessageBox::Cancel);
        goto label;
    }
    Unit* unit = new Unit();
    unit->setRace(race);
    unit->setName(name);
    unit->setAge(0);
    unit->setPlanet(this);
    units.append(unit);
}
