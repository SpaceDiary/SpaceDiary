#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <QtCore>
#include "unit.h"
class Unit;


class Dictionary
{
public:
    Dictionary();
    QString getSRace(int);
    int getIRace(QString);

    QString getSkill(int, int);
    int getNumber(int, QString);

    QString getOldSkill(int, QList<bool>, QList<bool>, QList<bool>, int);
    QString getNewSkill(int, QList<bool>, QList<bool>, QList<bool>, int);

    bool check(Unit*, int);

private:
    QMap<int, QString> races;

    QMap<int, QString> amazons;
    QMap<int, QString> witches;
    QMap<int, QString> ghosts;
    QMap<int, QString> clones;
    QMap<int, QString> monkeys;
    QMap<int, QString> robots;
};

#endif // DICTIONARY_H
