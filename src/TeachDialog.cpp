#include "TeachDialog.h"

TeachDialog::TeachDialog(QWidget* pwgt/*= 0*/)
    : QDialog(pwgt, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
{

}

TeachDialog::TeachDialog(Unit* unit, int mode, QWidget* pwgt/*= 0*/) : QDialog(pwgt, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
{
    teacher = unit;

    Dictionary* dictionary = new Dictionary();
    this->setModal(true);
    pbxLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    this->setLayout(pbxLayout);
    this->setMinimumSize(200, 200);
    this->setWindowTitle("Training plan of " + unit->getName());

    ok = new QPushButton("Ok");
    pbxLayout->addWidget(ok);
    ok->setObjectName("ok");
    QObject::connect(ok, SIGNAL(clicked()), this, SLOT(saveChecks()));
    QObject::connect(ok, SIGNAL(clicked()), this, SLOT(close()));

    this->mode=mode;
    skills=0;
    disciples=0;

    QString old;
    int k=0;
    while(dictionary->getOldSkill(unit->getRace(), unit->getFirst(), unit->getSecond(), unit->getThird(), k)!="")
    {
        old=dictionary->getOldSkill(unit->getRace(), unit->getFirst(), unit->getSecond(), unit->getThird(), k);
        oldSkills.append(old);
        k++;
    }

    QString new0;
    k=0;
    while(dictionary->getNewSkill(unit->getRace(), unit->getFirst(), unit->getSecond(), unit->getThird(), k)!="")
    {
        new0=dictionary->getNewSkill(unit->getRace(), unit->getFirst(), unit->getSecond(), unit->getThird(), k);
        if (new0!="") newSkills.append(new0);
        k++;
    }

    if (mode==1)
    {
        maxSkills=2;
        maxDisciples=5;
    }

    if (mode==2)
    {
        maxSkills=4;
        maxDisciples=1;
    }

    skillsLayout = new QBoxLayout(QBoxLayout::TopToBottom);
    pbxLayout->addLayout(skillsLayout);
    lSkills = new QLabel("Skills");
    skillsLayout->addWidget(lSkills);
    for (int i=0; i<oldSkills.length(); i++)
    {
        skillBox = new QCheckBox(oldSkills.at(i));
        skillsLayout->addWidget(skillBox);
        skillBox->setObjectName(QString::number(i));       
        skillBoxes.append(skillBox);
        QObject::connect(skillBox, SIGNAL(released()), this, SLOT(changeSkills()));
    }

    disciplesLayout = new QBoxLayout(QBoxLayout::TopToBottom);
    pbxLayout->addLayout(disciplesLayout);
    lDisciples = new QLabel("Disciples");
    disciplesLayout->addWidget(lDisciples);
    if (unit->getSpaceShip()!=NULL)
    {
        units=unit->getSpaceShip()->getUnits();
    }
    if (unit->getPlanet()!=NULL)
    {
        units=unit->getPlanet()->getUnits();
    }
    k=0;
    for (int i=0; i<units.length(); i++)
    {
        if ((units.at(i)->getName()!=unit->getName()) && (units.at(i)->getRace()==unit->getRace()))
        {
            discipleBox = new QCheckBox(units.at(i)->getName());
            disciplesLayout->addWidget(discipleBox);
            discipleBox->setObjectName(QString::number(k));
            QObject::connect(discipleBox, SIGNAL(released()), this, SLOT(changeDisciples()));
            discipleBoxes.append(discipleBox);
            availableUnits.append(units.at(i));
            k++;
        }
    }

    cancel = new QPushButton("Cancel");
    pbxLayout->addWidget(cancel);
    cancel->setObjectName("cancel");
    QObject::connect(cancel, SIGNAL(clicked()), this, SLOT(close()));
}

void TeachDialog::changeDisciples()
{
    QString name = QObject::sender()->objectName();
    int index = name.toInt();

    if (discipleBoxes.at(index)->isCheckable())
    {
        if (discipleBoxes.at(index)->isChecked())
        {
            disciples++;
            checkedDisciples.append(discipleBoxes.at(index)->text());
            checkedUnits.append(availableUnits.at(index));
            if (disciples>=maxDisciples)
            {
                for (int i=0; i<discipleBoxes.length(); i++)
                {
                    if (discipleBoxes.at(i)->isChecked()==false)
                    {
                        discipleBoxes[i]->setCheckable(false);
                    }
                }
            }
        }

        if (discipleBoxes.at(index)->isChecked()==false)
        {
            disciples--;
            checkedDisciples.removeOne(discipleBoxes.at(index)->text());
            checkedUnits.removeOne(availableUnits.at(index));
            if (disciples<maxDisciples)
            {
                for (int i=0; i<discipleBoxes.length(); i++)
                {
                    if (discipleBoxes.at(i)->isChecked()==false)
                    {
                        discipleBoxes[i]->setCheckable(true);
                    }
                }
            }
        }
    }
}

void TeachDialog::changeSkills()
{
    QString name = QObject::sender()->objectName();
    int index = name.toInt();

    if (skillBoxes.at(index)->isCheckable())
    {
        if (skillBoxes.at(index)->isChecked())
        {
            skills++;
            checkedSkills.append(skillBoxes.at(index)->text());
            if (skills>=maxSkills)
            {
                for (int i=0; i<skillBoxes.length(); i++)
                {
                    if (skillBoxes.at(i)->isChecked()==false)
                    {
                        skillBoxes[i]->setCheckable(false);
                    }
                }
            }
        }

        if (skillBoxes.at(index)->isChecked()==false)
        {
            skills--;
            checkedSkills.removeOne(skillBoxes.at(index)->text());
            if (skills<maxSkills)
            {
                for (int i=0; i<skillBoxes.length(); i++)
                {
                    if (skillBoxes.at(i)->isChecked()==false)
                    {
                        skillBoxes[i]->setCheckable(true);
                    }
                }
            }
        }
    }
}

void TeachDialog::saveChecks()
{
    if (mode==1) teacher->setAction("teach group");
    if (mode==2) teacher->setAction("teach disciple");
    for (int i=0; i<checkedUnits.length(); i++)
    {
        checkedUnits.at(i)->setAction("learn ");
        for (int j=0; j<checkedSkills.length(); j++)
        {
            checkedUnits.at(i)->setAction(checkedUnits.at(i)->getAction()+checkedSkills.at(j)+", ");
        }
        checkedUnits.at(i)->setAction(checkedUnits.at(i)->getAction().remove(checkedUnits.at(i)->getAction().length()-2, 2));
    }

}
