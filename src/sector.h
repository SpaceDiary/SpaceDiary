#ifndef SECTOR_H
#define SECTOR_H

#include <QtCore>

#include "planet.h"
#include "spacesector.h"
class Model;
class SpaceSector;

class Sector
{
public:
    Sector();
    Sector(QString, Model*);
    QString getName() {return name;}
    SpaceSector* getSpaceSector() {return spaceSector;}
    QList<Planet*> getPlanets() {return planets;}
    QStringList getWays() {return ways;}
    Model* getModel() {return model;}
    void save();
    void period();
    bool checkUnitName(QString);
private:
    Model* model;
    QStringList ways;
    QList<Planet*> planets;
    QString name;
    SpaceSector* spaceSector;
};

#endif // SECTOR_H
