#include "sector.h"

Sector::Sector()
{

}

Sector::Sector(QString name, Model* model)
{
    this->model=model;
    Sector::name = name;
    QFile fSector(name+".txt");
    if (fSector.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&fSector);
        QString str = stream.readLine();
        spaceSector = new SpaceSector(str, this);
        while (!stream.atEnd())
        {
            str = stream.readLine();
            if (str[0]=='W')
            {
                ways.append(str);
            }
            if (str[0]=='P')
            {
                Planet* planet = new Planet(str, this);
                planets.append(planet);
            }
        }
        fSector.close();
    }
}

void Sector::save()
{
    QFile fSector(name+".txt");
    if (fSector.open(QIODevice::WriteOnly))
    {
        QTextStream stream(&fSector);
        QString str = spaceSector->getName();
        stream << str<<endl;
        qDebug()<<str;
        spaceSector->save();
        for (int i=0; i<ways.size(); i++)
        {
            str = ways.at(i);
            stream << str<<endl;
            qDebug()<<str;
        }
        for (int i=0; i<planets.size(); i++)
        {
            str = planets.at(i)->getName();
            stream << str<<endl;
            qDebug()<<str;
            planets.at(i)->save();
        }
        fSector.close();
    }
}

void Sector::period()
{
    spaceSector->period();
    for (int i=0; i<planets.size(); i++)
    {
        planets.at(i)->period();
    }
}

bool Sector::checkUnitName(QString name)
{
    if (spaceSector->checkUnitName(name)) return true;
    for (int i=0; i<planets.size(); i++)
    {
        if (planets.at(i)->checkUnitName(name)) return true;
    }

    return false;
}
