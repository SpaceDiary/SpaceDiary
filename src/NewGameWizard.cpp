#include "NewGameWizard.h"

QWizardPage* NewGameWizard::createPlanetsPage()
{
    QWizardPage* planetsPage = new QWizardPage;
    //planetsPage->setTitle("PlanetsPage");
    gLayout = new QGridLayout();
    planetsPage->setLayout(gLayout);

    planetsNumber=1;
    //QLabel* planetsLabel =  new QLabel("Number of planets: ");
    //gLayout->addWidget(planetsLabel, 0, 0, 1, 10);
    //planetsBox=new QSpinBox();
    //planetsBox->setMinimum(1);
    //planetsBox->setMaximum(1);
    //gLayout->addWidget(planetsBox, 0, 1, 1, 10);
    //QObject::connect(planetsBox, SIGNAL(valueChanged(int)), this, SLOT(changePoints(int)));
    QLabel* unitsLeftLabel = new QLabel("Units left ");
    gLayout->addWidget(unitsLeftLabel, 0, 3, 1, 10);
    maxPoints=20;
    busyPoints=0;
    pointsLeft=maxPoints-busyPoints;
    pointsLabel = new QLabel(QString::number(pointsLeft)+"/"+QString::number(maxPoints));
    gLayout->addWidget(pointsLabel, 0, 4, 1, 1);

    QLabel* unitsLabel =  new QLabel("Choose your units races: ");
    gLayout->addWidget(unitsLabel, 1, 0, 1, 1);
    QLabel* amazonsLabel =  new QLabel("Amazons: ");
    gLayout->addWidget(amazonsLabel, 1, 2, 1, 1);
    amazonsBox = new QSpinBox();
    gLayout->addWidget(amazonsBox, 2, 2, 1, 1);
    QObject::connect(amazonsBox, SIGNAL(valueChanged(int)), this, SLOT(changePoints(int)));
    QLabel* witchesLabel =  new QLabel("Witches: ");
    gLayout->addWidget(witchesLabel, 1, 3, 1, 1);
    witchesBox = new QSpinBox();
    gLayout->addWidget(witchesBox, 2, 3, 1, 1);
    QObject::connect(witchesBox, SIGNAL(valueChanged(int)), this, SLOT(changePoints(int)));
    QLabel* ghostsLabel =  new QLabel("Ghosts: ");
    gLayout->addWidget(ghostsLabel, 1, 4, 1, 1);
    ghostsBox = new QSpinBox();
    gLayout->addWidget(ghostsBox, 2, 4, 1, 1);
    QObject::connect(ghostsBox, SIGNAL(valueChanged(int)), this, SLOT(changePoints(int)));
    QLabel* clonesLabel =  new QLabel("Clones: ");
    gLayout->addWidget(clonesLabel, 1, 5, 1, 1);
    clonesBox = new QSpinBox();
    gLayout->addWidget(clonesBox, 2, 5, 1, 1);
    QObject::connect(clonesBox, SIGNAL(valueChanged(int)), this, SLOT(changePoints(int)));
    QLabel* monkeysLabel =  new QLabel("Monkeys: ");
    gLayout->addWidget(monkeysLabel, 1, 6, 1, 1);
    monkeysBox = new QSpinBox();
    gLayout->addWidget(monkeysBox, 2, 6, 1, 1);
    QObject::connect(monkeysBox, SIGNAL(valueChanged(int)), this, SLOT(changePoints(int)));
    QLabel* robotsLabel =  new QLabel("Robots: ");
    gLayout->addWidget(robotsLabel, 1, 7, 1, 1);
    robotsBox = new QSpinBox();
    gLayout->addWidget(robotsBox, 2, 7, 1, 1);
    QObject::connect(robotsBox, SIGNAL(valueChanged(int)), this, SLOT(changePoints(int)));

    return planetsPage;
}

QWizardPage* NewGameWizard::createSkillsPage()
{
    QWizardPage* skillsPage = new QWizardPage;
    //skillsPage->setTitle("SkillsPage");
    gLayout = new QGridLayout();
    skillsPage->setLayout(gLayout);



    return skillsPage;
}

int NewGameWizard::changePoints(int)
{
    busyPoints=0;
    spins.clear();
    QStringList agesTypes;
    agesTypes << "Baby" << "Young" << "Adult" << "Hardened" <<"Veteran";
    spins.append(amazonsBox->value());
    spins.append(witchesBox->value());
    spins.append(ghostsBox->value());
    spins.append(clonesBox->value());
    spins.append(monkeysBox->value());
    spins.append(robotsBox->value());

    for (int i=1; i<7; i++)
    {
        busyPoints+=max(spins)*i;
        spins.removeOne(max(spins));
    }

    //planetsNumber=planetsBox->value();
    maxPoints=planetsNumber*20;
    pointsLeft=maxPoints-busyPoints;
    pointsLabel->setText(QString::number(pointsLeft)+"/"+QString::number(maxPoints));

    return 0;
}

int NewGameWizard::max(QList<int> spins)
{
    int max=0;
    for (int i=0; i<spins.length(); i++)
    {
        if (spins.at(i)>max)
        {
            max=spins.at(i);
        }
    }
    return max;
}

bool NewGameWizard::validateCurrentPage()
{
    if (pointsLeft!=0)
    {
        this->back();
        return false;
    }

    return true;
}


NewGameWizard::NewGameWizard(QWidget *parent)
    : QWizard(parent)
{
    this->setWindowTitle("New game settings");
    this->addPage(createPlanetsPage());
    this->addPage(createSkillsPage());
}

