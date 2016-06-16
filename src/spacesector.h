#ifndef SPACESECTOR_H
#define SPACESECTOR_H

#include <QtCore>

#include "spaceship.h"
#include "unit.h"

class Sector;

class SpaceSector
{
public:
    SpaceSector();
    SpaceSector(QString, Sector*);
    QString getName() {return name;}
    QList<Unit*> getUnits() {return units;}
    QList<SpaceShip*> getSpaceShips() {return spaceShips;}
    Sector* getSector() {return sector;}
    void save();
    void period();
    bool checkUnitName(QString);
private:
    QList<Unit*> units;
    QList<SpaceShip*> spaceShips;
    QString name;
    Sector* sector;
};

#endif // SPACESECTOR_H
