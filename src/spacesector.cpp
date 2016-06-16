#include "spacesector.h"

SpaceSector::SpaceSector()
{

}

SpaceSector::SpaceSector(QString name, Sector* sector)
{
    this->sector=sector;
    SpaceSector::name = name;
    QFile fSpaceSector(name + ".txt");
    if (fSpaceSector.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&fSpaceSector);
        while (!stream.atEnd())
        {
            QString str = stream.readLine();
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
        fSpaceSector.close();
    }
}

void SpaceSector::save()
{
    QFile fSpaceSector(name+".txt");
    if (fSpaceSector.open(QIODevice::WriteOnly))
    {
        QTextStream stream(&fSpaceSector);
        QString str;
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
        fSpaceSector.close();
    }
}
void SpaceSector::period()
{
    for (int i=0; i<units.size(); i++)
    {
        units.at(i)->period();
    }

    for (int i=0; i<spaceShips.size(); i++)
    {
        spaceShips.at(i)->period();
    }
}

bool SpaceSector::checkUnitName(QString name)
{
    for (int i=0; i<units.size(); i++)
    {
        if (units.at(i)->checkUnitName(name)) return true;
    }

    for (int i=0; i<spaceShips.size(); i++)
    {
        if(spaceShips.at(i)->checkUnitName(name)) return true;
    }

    return false;
}
