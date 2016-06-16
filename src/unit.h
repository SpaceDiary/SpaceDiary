#ifndef UNIT_H
#define UNIT_H

#include <QtCore>

#include "planet.h"
#include "sector.h"
#include "model.h"
#include "dictionary.h"

class SpaceSector;
class SpaceShip;
class Planet;
class Dictionary;


class Unit: public QObject
{
    Q_OBJECT
public:
    explicit Unit();
    explicit Unit(QString, SpaceSector*);
    explicit Unit(QString, SpaceShip*);
    explicit Unit(QString, Planet*);
    int getRace() {return race;}
    int getAge() {return age;}
    QString getName() {return name;}
    QList<bool>getFirst() {return first;}
    QList<bool>getSecond() {return second;}
    QList<bool>getThird() {return third;}
    void save();
    QString getAction() {return action;}
    void period();
    SpaceSector* getSpaceSector() {return spaceSector;}
    SpaceShip* getSpaceShip() {return spaceShip;}
    Planet* getPlanet() {return planet;}
    void setRace(int);
    void setName(QString);
    void setAge(int);
    void setSpaceSector(SpaceSector*);
    void setSpaceShip(SpaceShip*);
    void setPlanet(Planet*);
    bool checkUnitName(QString);
    void train(QString);
    void setAction(QString);
private:
    int race;
    int age;
    QString name;
    QList<bool>first;
    QList<bool>second;
    QList<bool>third;
    QString action;
    SpaceSector* spaceSector;
    Planet* planet;
    SpaceShip* spaceShip;
    Dictionary* dictionary;
public slots:
    void slotSetAction();
//private:

//    bool armor;
//    bool blaster;
//    bool lifeSystem;
//    bool megabomb;

//    bool health;
//    bool agility;
//    bool strength;
//    bool immunity;

//    int accuracy;

//    int telepathy;
//    int lightning;

//    bool stealYouth;
//    bool impersonation;
//    bool reEducation;
//    bool teleport;

//    bool uterineReplicator;
//    bool magicStaff;
//    bool altar;
//    bool planet;

//    int drainLife;
//    int flight;

//    bool reincarnation;
//    bool connection;
//    bool necromancy;
//    bool plague;

//    bool vampirism;

//    bool magicWand;
//    bool sandom;
//    bool weaponry;
//    bool clone;

//    bool ambush;
//    bool camouflage;

//    bool claws;

//    int meleeAttack;
//    int meleeDefense;

//    bool lazer;
//    bool spanner;
//    bool sheathing;
//    bool robot;

//    bool carcass;

//    bool spaceShip;
//    bool antiaircrafGun;

};

#endif // UNIT_H
