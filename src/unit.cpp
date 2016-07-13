#include "unit.h"

Unit::Unit() : QObject()
{
    planet=NULL;
    spaceSector=NULL;
    spaceShip=NULL;
    action="";
    age=-1;

    for (int i=0; i<4; i++)
        first.append(0);
    for (int i=0; i<4; i++)
        second.append(0);
    for (int i=0; i<4; i++)
        third.append(0);
}

Unit::Unit(QString name, SpaceSector* spaceSector) : QObject()
{
    dictionary = new Dictionary();

    planet=NULL;
    spaceShip=NULL;
    this->spaceSector=spaceSector;
    this->name = name;
    action="";

    QFile fUnit(name+".txt");
    if (fUnit.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&fUnit);
        QString str = stream.readLine();
        race=str.toInt();
        str = stream.readLine();
        age=str.toInt();
        str = stream.readLine();
        for (int i=0; i<4; i++)
            first.append(str[i].digitValue());
        str = stream.readLine();
        for (int i=0; i<4; i++)
            second.append(str[i].digitValue());
        str = stream.readLine();
        for (int i=0; i<4; i++)
            third.append(str[i].digitValue());
        fUnit.close();
    }

}

Unit::Unit(QString name, SpaceShip* spaceShip) : QObject()
{
    dictionary = new Dictionary();

    planet=NULL;
    spaceSector=NULL;
    this->spaceShip=spaceShip;
    Unit::name = name;
    action="";

    QFile fUnit(name+".txt");
    if (fUnit.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&fUnit);
        QString str = stream.readLine();
        race=str.toInt();
        str = stream.readLine();
        age=str.toInt();
        str = stream.readLine();
        for (int i=0; i<4; i++)
            first.append(str[i].digitValue());
        str = stream.readLine();
        for (int i=0; i<4; i++)
            second.append(str[i].digitValue());
        str = stream.readLine();
        for (int i=0; i<4; i++)
            third.append(str[i].digitValue());
        fUnit.close();
    }

}

Unit::Unit(QString name, Planet* planet) : QObject()
{
    dictionary = new Dictionary();

    spaceShip=NULL;
    spaceSector=NULL;
    this->planet=planet;
    Unit::name = name;
    action="";

    QFile fUnit(name+".txt");
    if (fUnit.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&fUnit);
        QString str = stream.readLine();
        race=str.toInt();
        str = stream.readLine();
        age=str.toInt();
        str = stream.readLine();
        for (int i=0; i<4; i++)
            first.append(str[i].digitValue());
        str = stream.readLine();
        for (int i=0; i<4; i++)
            second.append(str[i].digitValue());
        str = stream.readLine();
        for (int i=0; i<4; i++)
            third.append(str[i].digitValue());
        fUnit.close();
    }

}

void Unit::save()
{
    QFile fSpaceShip(name+".txt");
    if (fSpaceShip.open(QIODevice::WriteOnly))
    {
        QTextStream stream(&fSpaceShip);
        QString str;
        str=QString::number(race);
        stream<<str<<endl;
        qDebug()<<str;
        str=QString::number(age);
        stream<<str<<endl;
        qDebug()<<str;
        str="";
        for (int i=0; i<4; i++)
        {
            str+=QString::number(first.at(i));
        }
        stream<<str<<endl;
        qDebug()<<str;
        str="";
        for (int i=0; i<4; i++)
        {
            str+=QString::number(second.at(i));
        }
        stream<<str<<endl;
        qDebug()<<str;
        str="";
        for (int i=0; i<4; i++)
        {
            str+=QString::number(third.at(i));
        }
        stream<<str<<endl;
        qDebug()<<str;
        fSpaceShip.close();
    }
}

void Unit::slotSetAction()
{
    this->action=QObject::sender()->objectName();
}

void Unit::setAction(QString action)
{
    this->action=action;
}

void Unit::period()
{

    if (action=="extract")
    {
        planet->getSector()->getModel()->extract(planet->getResource());
    }

    if (action=="breed")
    {
        if (spaceShip)
        {
            spaceShip->breed(race);
        }

        if (planet)
        {
            planet->breed(race);
        }
    }

    if (action.contains("train"))
    {
        this->train(action.remove(0, 6));
    }

    if (action.contains("learn"))
    {
        QString s;
        action.remove(0, 5);
        int count;
        count=action.count(",");
        for (int i=0; i<count+1; i++)
        {
            s = action.section(',', i, i);
            s.remove(0, 1);
            this->train(s);
        }

    }

    action="";

    if ((race!=3) && (race!=6))
    {
        age++;
    }
}

bool Unit::checkUnitName(QString name)
{
    if (this->name==name) return true;
    return false;
}

void Unit::setRace(int race)
{
    this->race=race;
}

void Unit::setName(QString name)
{
    this->name=name;
}

void Unit::setAge(int age)
{
    this->age=age;
}
void Unit::setSpaceSector(SpaceSector* spaceSector)
{
    this->spaceSector = spaceSector;
}

void Unit::setSpaceShip(SpaceShip* spaceShip)
{
    this->spaceShip = spaceShip;
}

void Unit::setPlanet(Planet* planet)
{
    this->planet = planet;
}

void Unit::train(QString skill)
{
    int number = dictionary->getNumber(race, skill);
    if (dictionary->check(this, number))
    {
        if (number<=4) first[number-1]=1;
        if ((number>4) && (number<=8)) second[number-5]=1;
        if (number>8) third[number-9]=1;
    }

}

