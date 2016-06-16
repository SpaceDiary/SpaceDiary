#ifndef MODEL_H
#define MODEL_H

#include <QtCore>

#include "sector.h"
class Sector;

//struct Info
//{
//    Sector* sector;
//    SpaceSector* spaceSector;
//    Planet* planet;
//    SpaceShip* spaceShip;
//    Unit* unit;
//};

class Model:public QObject
{
    Q_OBJECT
public:
    Model();
    Model(QDir, QDir);

    QList<Sector*> getSectors() {return sectors;}
    QList<int> getResources() {return resources;}
    QList<int> getDate() {return date;}
    QDir getMainDir() {return mainDir;}

    void save(QDir);
    void saveDate();
    void saveResources();
    void saveSectors();

    void incDay();
    void incPeriod();
    void extract(int);
    bool checkUnitName(QString);

private:
    QDir mainDir;
    QList<Sector*> sectors;
    QList<int> resources;
    QList<int> date;
    //Info info;

public slots:

};

#endif // MODEL_H
