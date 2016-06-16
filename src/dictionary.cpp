#include "dictionary.h"

Dictionary::Dictionary()
{
    races[1] = "Amazon";
    races[2] = "Witch";
    races[3] = "Ghost";
    races[4] = "Clone";
    races[5] = "Monkey";
    races[6] = "Robot";

    amazons[1]="Armor";
    amazons[2]="Blaster";
    amazons[3]="LifeSupport";
    amazons[4]="Megabomb";

    amazons[5]="Health";
    amazons[6]="Agility";
    amazons[7]="Strength";
    amazons[8]="Immunity";

    amazons[9]="Basic acuracy";
    amazons[10]="Advanced acuracy";
    amazons[11]="Expert acuracy";
    amazons[12]="Sniper";

    witches[1]="Confusion";
    witches[2]="Hypnosis";
    witches[3]="Lightning";
    witches[4]="Strong lightning";

    witches[5]="Steal youth";
    witches[6]="Impersonation";
    witches[7]="Re-education";
    witches[8]="Teleport";

    witches[9]="Uterine replicator";
    witches[10]="Magic staff";
    witches[11]="Altar";
    witches[12]="Planet";

    ghosts[1]="Drain life";
    ghosts[2]="Strong drain life";
    ghosts[3]="Flight";
    ghosts[4]="Space flight";

    ghosts[5]="Reincarnation";
    ghosts[6]="Connection";
    ghosts[7]="Necromancy";
    ghosts[8]="Plague";

    ghosts[9]="Health";
    ghosts[10]="Agility";
    ghosts[11]="Strength";
    ghosts[12]="Vampirism";

    clones[1]="";
    clones[2]="";
    clones[3]="";
    clones[4]="";

    clones[5]="Magic wand";
    clones[6]="Sandom";
    clones[7]="Weaponry";
    clones[8]="Clone";

    clones[9]="";
    clones[10]="";
    clones[11]="";
    clones[12]="";

    monkeys[1]="Ambush";
    monkeys[2]="Camouflage";
    monkeys[3]="";
    monkeys[4]="";

    monkeys[5]="Health";
    monkeys[6]="Agility";
    monkeys[7]="Strength";
    monkeys[8]="Claws";

    monkeys[9]="Melee attack";
    monkeys[10]="Strong melee attack";
    monkeys[11]="Dodge";
    monkeys[12]="Deftly dodge";

    robots[1]="Lazer";
    robots[2]="Spanner";
    robots[3]="Sheathing";
    robots[4]="Robot";

    robots[5]="Health";
    robots[6]="Agility";
    robots[7]="Strength";
    robots[8]="Carcass";

    robots[9]="Basic acuracy";
    robots[10]="Advanced acuracy";
    robots[11]="Expert acuracy";
    robots[12]="Sniper";

}

QString Dictionary::getSRace(int iRace)
{
    return races.value(iRace);
}

int Dictionary::getIRace(QString sRace)
{
    return races.key(sRace);
}

QString Dictionary::getSkill(int race, int number)
{
    if (race==1) return amazons.value(number);
    if (race==2) return witches.value(number);
    if (race==3) return ghosts.value(number);
    if (race==4) return clones.value(number);
    if (race==5) return monkeys.value(number);
    if (race==6) return robots.value(number);
    return "";
}

int Dictionary::getNumber(int race, QString skill)
{
    if (race==1) return amazons.key(skill);
    if (race==2) return witches.key(skill);
    if (race==3) return ghosts.key(skill);
    if (race==4) return clones.key(skill);
    if (race==5) return monkeys.key(skill);
    if (race==6) return robots.key(skill);
    return 0;
}

QString Dictionary::getOldSkill(int race, QList<bool> first, QList<bool> second, QList<bool> third, int index)
{
    QList<QString> oldSkills;
    for (int i=0; i<4; i++)
    {
        if ((first.at(i)==true)) oldSkills.append(this->getSkill(race, i+1));
    }
    for (int i=0; i<4; i++)
    {
        if ((second.at(i)==true)) oldSkills.append(this->getSkill(race, i+5));
    }
    for (int i=0; i<4; i++)
    {
        if ((third.at(i)==true)) oldSkills.append(this->getSkill(race, i+9));
    }
    if (index<=oldSkills.length()-1)
    {
        return oldSkills.at(index);
    }
    return "";
}

QString Dictionary::getNewSkill(int race, QList<bool> first, QList<bool> second, QList<bool> third, int index)
{
    QList<QString> newSkills;
    for (int i=0; i<4; i++)
    {
        if ((first.at(i)==false)) newSkills.append(this->getSkill(race, i+1));
    }
    for (int i=0; i<4; i++)
    {
        if ((second.at(i)==false)) newSkills.append(this->getSkill(race, i+5));
    }
    for (int i=0; i<4; i++)
    {
        if ((third.at(i)==false)) newSkills.append(this->getSkill(race, i+9));
    }
    if (index<=newSkills.length()-1)
    {
        return newSkills.at(index);
    }
    return "";

}

bool Dictionary::check(Unit * unit, int number)
{
    int race = unit->getRace();
    if (race==1)
    {
        if ((number==10) && unit->getThird().at(0)==0) return false;
        if ((number==11) && unit->getThird().at(1)==0) return false;
        if ((number==12) && unit->getThird().at(2)==0) return false;
    }
    if (race==2)
    {
        if ((number==2) && unit->getFirst().at(0)==0) return false;
        if ((number==4) && unit->getFirst().at(2)==0) return false;
    }
    if (race==3)
    {
        if ((number==2) && unit->getFirst().at(0)==0) return false;
        if ((number==4) && unit->getFirst().at(2)==0) return false;
    }
    if (race==5)
    {
        if ((number==10) && unit->getThird().at(0)==0) return false;
        if ((number==12) && unit->getThird().at(2)==0) return false;
    }
    if (race==6)
    {
        if ((number==10) && unit->getThird().at(0)==0) return false;
        if ((number==11) && unit->getThird().at(1)==0) return false;
        if ((number==12) && unit->getThird().at(2)==0) return false;
    }
    return true;
}
