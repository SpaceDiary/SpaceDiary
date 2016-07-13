#include "NewGameWizard.h"

QWizardPage* NewGameWizard::createFirstPage()
{
    pageNumber=1;
    QWizardPage* firstPage = new QWizardPage;
    firstPage->setTitle("Choose your units races");
    gLayout = new QGridLayout();
    firstPage->setLayout(gLayout);

    planetsNumber=1;
    //QLabel* planetsLabel =  new QLabel("Number of planets: ");
    //gLayout->addWidget(planetsLabel, 0, 0, 1, 10);
    //planetsBox=new QSpinBox();
    //planetsBox->setMinimum(1);
    //planetsBox->setMaximum(1);
    //gLayout->addWidget(planetsBox, 0, 1, 1, 10);
    //QObject::connect(planetsBox, SIGNAL(valueChanged(int)), this, SLOT(changePoints(int)));
    QLabel* unitsLeftLabel = new QLabel("Points left ");
    gLayout->addWidget(unitsLeftLabel, 0, 3, 1, 10);
    maxPoints=20;
    busyPoints=0;
    pointsLeft=maxPoints-busyPoints;
    pointsLabel = new QLabel(QString::number(pointsLeft)+"/"+QString::number(maxPoints));
    gLayout->addWidget(pointsLabel, 0, 4, 1, 1);

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

    return firstPage;
}

QWizardPage* NewGameWizard::createSecondPage()
{
    pageNumber=2;
    QWizardPage* secondPage = new QWizardPage;
    secondPage->setTitle("Choose your units ages and names");
    gLayout = new QGridLayout();
    secondPage->setLayout(gLayout);

    QStringList agesTypes;
    agesTypes <<"Choose" << "Baby" << "Young" << "Adult" << "Hardened" <<"Veteran";
    QLabel* ageLabel = new QLabel("Age");
    gLayout->addWidget(ageLabel, 0, 0, 1, 1);   
    QLabel* raceLabel = new QLabel("Race");
    gLayout->addWidget(raceLabel, 0, 1, 1, 1);
    QLabel* unitLabel = new QLabel("Unit");
    gLayout->addWidget(unitLabel, 0, 2, 1, 1);
    QLabel* nameLabel = new QLabel("Name");
    gLayout->addWidget(nameLabel, 0, 3, 1, 1);

    int sum=0;
    for (int i=0; i<amazonsNumber; i++)
    {
        QComboBox* cb = new QComboBox();
        gLayout->addWidget(cb, i+1+sum, 0, 1, 1);
        cb->addItems(agesTypes);
        QObject::connect(cb, SIGNAL(currentIndexChanged(int)), units.at(i+sum), SLOT(setAge(int)));

        QLabel* raceLabel = new QLabel("amazon");
        gLayout->addWidget(raceLabel, i+1+sum, 1, 1, 1);

        QLabel* unitLabel = new QLabel("Unit");
        gLayout->addWidget(unitLabel, i+1+sum, 2, 1, 1);

        QTextEdit* name = new QTextEdit();
        gLayout->addWidget(name, i+1+sum, 3, 1, 1);
    }
    sum+=amazonsNumber;
    for (int i=0; i<witchesNumber; i++)
    {
        QComboBox* cb = new QComboBox();
        gLayout->addWidget(cb, i+1+sum, 0, 1, 1);
        cb->addItems(agesTypes);
        QObject::connect(cb, SIGNAL(currentIndexChanged(int)), units.at(i+sum), SLOT(setAge(int)));


        QLabel* raceLabel = new QLabel("witch");
        gLayout->addWidget(raceLabel, i+1+sum, 1, 1, 1);

        QLabel* unitLabel = new QLabel("Unit");
        gLayout->addWidget(unitLabel, i+1+sum, 2, 1, 1);

        QTextEdit* name = new QTextEdit();
        gLayout->addWidget(name, i+1+sum, 3, 1, 1);
    }
    sum+=witchesNumber;
    for (int i=0; i<ghostsNumber; i++)
    {
        QLabel* undyingLabel = new QLabel("Undying");
        gLayout->addWidget(undyingLabel, i+1+sum, 0, 1, 1);

        QLabel* raceLabel = new QLabel("ghost");
        gLayout->addWidget(raceLabel, i+1+sum, 1, 1, 1);

        QLabel* unitLabel = new QLabel("Unit");
        gLayout->addWidget(unitLabel, i+1+sum, 2, 1, 1);

        QTextEdit* name = new QTextEdit();
        gLayout->addWidget(name, i+1+sum, 3, 1, 1);
    }
    sum+=ghostsNumber;
    for (int i=0; i<clonesNumber; i++)
    {
        QComboBox* cb = new QComboBox();
        gLayout->addWidget(cb, i+1+sum, 0, 1, 1);
        cb->addItems(agesTypes);
        QObject::connect(cb, SIGNAL(currentIndexChanged(int)), units.at(i+sum), SLOT(setAge(int)));


        QLabel* raceLabel = new QLabel("clone");
        gLayout->addWidget(raceLabel, i+1+sum, 1, 1, 1);

        QLabel* unitLabel = new QLabel("Unit");
        gLayout->addWidget(unitLabel, i+1+sum, 2, 1, 1);

        QTextEdit* name = new QTextEdit();
        gLayout->addWidget(name, i+1+sum, 3, 1, 1);
    }
    sum+=clonesNumber;
    for (int i=0; i<monkeysNumber; i++)
    {
        QComboBox* cb = new QComboBox();
        gLayout->addWidget(cb, i+1+sum, 0, 1, 1);
        cb->addItems(agesTypes);
        QObject::connect(cb, SIGNAL(currentIndexChanged(int)), units.at(i+sum), SLOT(setAge(int)));


        QLabel* raceLabel = new QLabel("monkey");
        gLayout->addWidget(raceLabel, i+1+sum, 1, 1, 1);

        QLabel* unitLabel = new QLabel("Unit");
        gLayout->addWidget(unitLabel, i+1+sum, 2, 1, 1);

        QTextEdit* name = new QTextEdit();
        gLayout->addWidget(name, i+1+sum, 3, 1, 1);
    }
    sum+=monkeysNumber;
    for (int i=0; i<robotsNumber; i++)
    {
        QLabel* undyingLabel = new QLabel("Undying");
        gLayout->addWidget(undyingLabel, i+1+sum, 0, 1, 1);

        QLabel* raceLabel = new QLabel("robot");
        gLayout->addWidget(raceLabel, i+1+sum, 1, 1, 1);

        QLabel* unitLabel = new QLabel("Unit");
        gLayout->addWidget(unitLabel, i+1+sum, 2, 1, 1);

        QTextEdit* name = new QTextEdit();
        gLayout->addWidget(name, i+1+sum, 3, 1, 1);
    }
    sum+=robotsNumber;

    return secondPage;
}

QWizardPage* NewGameWizard::createThirdPage()
{
    pageNumber=3;
    QWizardPage* thirdPage = new QWizardPage;
    thirdPage->setTitle("Choose your units skills");
    gLayout = new QGridLayout();
    thirdPage->setLayout(gLayout);

    return thirdPage;
}

void NewGameWizard::changePoints(int)
{
    busyPoints=0;
    spins.clear();
    spins.append(amazonsBox->value());
    amazonsNumber=amazonsBox->value();
    spins.append(witchesBox->value());
    witchesNumber=witchesBox->value();
    spins.append(ghostsBox->value());
    ghostsNumber=ghostsBox->value();
    spins.append(clonesBox->value());
    clonesNumber=ghostsBox->value();
    spins.append(monkeysBox->value());
    monkeysNumber=monkeysBox->value();
    spins.append(robotsBox->value());
    robotsNumber=robotsBox->value();

    for (int i=1; i<7; i++)
    {
        busyPoints+=max(spins)*i;
        spins.removeOne(max(spins));
    }

    //planetsNumber=planetsBox->value();
    maxPoints=planetsNumber*20;
    pointsLeft=maxPoints-busyPoints;
    pointsLabel->setText(QString::number(pointsLeft)+"/"+QString::number(maxPoints));

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
    if (pageNumber==1)
    {
        if (pointsLeft!=0)
        {
            this->back();
            return false;
        }

        for (int i=0; i<amazonsNumber; i++)
        {
            Unit* unit = new Unit();
            unit->setRace(1);
            units.append(unit);
        }
        for (int i=0; i<witchesNumber; i++)
        {
            Unit* unit = new Unit();
            unit->setRace(2);
            units.append(unit);
        }
        for (int i=0; i<ghostsNumber; i++)
        {
            Unit* unit = new Unit();
            unit->setRace(3);
            units.append(unit);
        }
        for (int i=0; i<clonesNumber; i++)
        {
            Unit* unit = new Unit();
            unit->setRace(4);
            units.append(unit);
        }
        for (int i=0; i<monkeysNumber; i++)
        {
            Unit* unit = new Unit();
            unit->setRace(5);
            units.append(unit);
        }
        for (int i=0; i<robotsNumber; i++)
        {
            Unit* unit = new Unit();
            unit->setRace(6);
            units.append(unit);
        }

        this->removePage(1);
        this->addPage(createSecondPage());
        this->addPage(new QWizardPage);
        return true;
    }

    if (pageNumber==2)
    {
        for (int i=0; i<units.length(); i++)
        {
            if (units.at(i)->getAge()==-1)
            {
                this->removePage(2);
                pageNumber=1;
                this->back();
                return false;
            }
        }

        this->removePage(2);
        this->addPage(createThirdPage());
        return true;
    }

    return true;

}


NewGameWizard::NewGameWizard(QWidget *parent)
    : QWizard(parent)
{
    pageNumber=0;
    this->setWindowTitle("New game settings");
    this->addPage(createFirstPage());
    this->addPage(new QWizardPage);
}

