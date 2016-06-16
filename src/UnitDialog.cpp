#include "UnitDialog.h"

UnitDialog::UnitDialog(QWidget* pwgt/*= 0*/)
    : QDialog(pwgt, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
{

}

UnitDialog::UnitDialog(Unit* unit, QWidget* pwgt/*= 0*/) : QDialog(pwgt, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
{

    UnitDialog::unit=unit;
    Dictionary* dictionary = new Dictionary();

    this->setModal(true);
    pbxLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    this->setLayout(pbxLayout);
    this->setMinimumSize(200, 200);

    if (unit->getAge()==0) sAge="";
    if (unit->getAge()==1) sAge="Baby";
    if (unit->getAge()==2) sAge="Young";
    if (unit->getAge()==3) sAge="Adult";
    if (unit->getAge()==4) sAge="Hardenet";
    if (unit->getAge()==5) sAge="Veteran";

    skillsLayout = new QBoxLayout(QBoxLayout::TopToBottom);
    pbxLayout->addLayout(skillsLayout);

    QString old;
    int i=0;
    while(dictionary->getOldSkill(unit->getRace(), unit->getFirst(), unit->getSecond(), unit->getThird(), i)!="")
    {
        old=dictionary->getOldSkill(unit->getRace(), unit->getFirst(), unit->getSecond(), unit->getThird(), i);
        oldSkills.append(old);
        i++;
    }

    QString new0;
    i=0;
    while(dictionary->getNewSkill(unit->getRace(), unit->getFirst(), unit->getSecond(), unit->getThird(), i)!="")
    {
        new0=dictionary->getNewSkill(unit->getRace(), unit->getFirst(), unit->getSecond(), unit->getThird(), i);
        if (new0!="") newSkills.append(new0);
        i++;
    }


    for (int i=0; i<oldSkills.length(); i++)
    {
        lSkill = new QLabel(oldSkills.at((i)));
        skillsLayout->addWidget(lSkill);
    }

    sRace = dictionary->getSRace(unit->getRace());
    setWindowTitle(sAge+" "+sRace+" "+unit->getName().remove(0, 5));

    actionsLayout = new QBoxLayout(QBoxLayout::TopToBottom);
    pbxLayout->addLayout(actionsLayout);

    if (unit->getAction()=="")
    {
        sAction = "This unit has not made his action yet";

        if ((unit->getAge()!=1) && (unit->getPlanet()))
        {
            extract = new QPushButton("Extract");
            actionsLayout->addWidget(extract);
            extract->setObjectName("extract");
            QObject::connect(this->findChild<QObject*>("extract"), SIGNAL(clicked()), unit, SLOT(slotSetAction()));
            QObject::connect(this->findChild<QObject*>("extract"), SIGNAL(clicked()), this, SLOT(close()));
        }

        if ((unit->getAge()!=1) && (unit->getRace()!=3) && (unit->getRace()!=6))
        {
            breed = new QPushButton("Breed");
            actionsLayout->addWidget(breed);
            breed->setObjectName("breed");
            QObject::connect(this->findChild<QObject*>("breed"), SIGNAL(clicked()), unit, SLOT(slotSetAction()));
            QObject::connect(this->findChild<QObject*>("breed"), SIGNAL(clicked()), this, SLOT(close()));

            teach = new QPushButton("Teach");
            actionsLayout->addWidget(teach);
            teach->setObjectName("teach");
            menuTeach = new QMenu();
            teach->setMenu(menuTeach);

            trainAlone = new QAction("Train alone", teach);
            trainAlone->setObjectName("trainAlone");
            menuTeach->addAction(trainAlone);
            menuTrainAlone = new QMenu();
            trainAlone->setMenu(menuTrainAlone);
            for (int i=0; i<newSkills.length(); i++)
            {
                skillAction = new QAction("Train " + newSkills.at(i), trainAlone);
                skillAction->setObjectName("train " + newSkills.at(i));
                menuTrainAlone->addAction(skillAction);
                QObject::connect(this->findChild<QObject*>("train " + newSkills.at(i)), SIGNAL(triggered()), unit, SLOT(slotSetAction()));
                QObject::connect(this->findChild<QObject*>("train " + newSkills.at(i)), SIGNAL(triggered()), this, SLOT(close()));
            }

            teachGroup = new QAction("Teach group", teach);
            teachGroup->setObjectName("teachGroup");
            menuTeach->addAction(teachGroup);
            QObject::connect(this->findChild<QObject*>("teachGroup"), SIGNAL(triggered()), this, SLOT(teachGroupDialog()));
            QObject::connect(this->findChild<QObject*>("teachGroup"), SIGNAL(triggered()), this, SLOT(close()));

            teachDisciple = new QAction("Teach disciple", teach);
            teachDisciple->setObjectName("teachDisciple");
            menuTeach->addAction(teachDisciple);
            QObject::connect(this->findChild<QObject*>("teachDisciple"), SIGNAL(triggered()), this, SLOT(teachDiscipleDialog()));
            QObject::connect(this->findChild<QObject*>("teachDisciple"), SIGNAL(triggered()), this, SLOT(close()));
        }
    }
    else if (unit->getAction().contains("train"))
    { 
        sAction = "This unit is training ";
        for (int i=6; i<unit->getAction().length(); i++)
        {
            sAction += unit->getAction().at(i);
        }
    }
    else if (unit->getAction().contains("teach"))
    {
        sAction = "This unit is teaching ";
        for (int i=6; i<unit->getAction().length(); i++)
        {
            sAction += unit->getAction().at(i);
        }
    }
    else if (unit->getAction().contains("learn"))
    {
        sAction = "This unit is learning ";
        for (int i=6; i<unit->getAction().length(); i++)
        {
            sAction += unit->getAction().at(i);
        }
    }
    else
    {
        sAction = "This unit is " + unit->getAction()+"ing";
    }

    lAction = new QLabel(sAction);
    actionsLayout->addWidget(lAction);

    cancel = new QPushButton("Cancel");
    pbxLayout->addWidget(cancel);
    cancel->setObjectName("cancel");
    QObject::connect(this->findChild<QObject*>("cancel"), SIGNAL(clicked()), this, SLOT(close()));

}

void UnitDialog::teachGroupDialog()
{
    teachDialog=new TeachDialog(unit, 1);
    teachDialog->show();
}

void UnitDialog::teachDiscipleDialog()
{
    teachDialog=new TeachDialog(unit, 2);
    teachDialog->show();
}
