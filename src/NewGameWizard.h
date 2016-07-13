#ifndef NEWGAMEWIZARD_H
#define NEWGAMEWIZARD_H

#include "unit.h"
#include "dictionary.h"

#include <QtGui>

class NewGameWizard : public QWizard
{
    Q_OBJECT
public:
    NewGameWizard(QWidget *parent = 0);
    QWizardPage* createFirstPage();
    QWizardPage* createSecondPage();
    QWizardPage* createThirdPage();
    bool validateCurrentPage();

private:
    QGridLayout* gLayout;

    int pageNumber;

    QSpinBox* planetsBox;
    int planetsNumber;
    int maxPoints;
    int busyPoints;
    int pointsLeft;
    QLabel* pointsLabel;
    QList<int> busyPointsList;

    QSpinBox* amazonsBox;
    int amazonsNumber;
    QSpinBox* witchesBox;
    int witchesNumber;
    QSpinBox* ghostsBox;
    int ghostsNumber;
    QSpinBox* clonesBox;
    int clonesNumber;
    QSpinBox* monkeysBox;
    int monkeysNumber;
    QSpinBox* robotsBox;
    int robotsNumber;
    QList<int> spins;
    int max(QList<int>);

    QList<Unit*> units;
    QList<int> ages;
    QList<QString> names;


signals:

public slots:
    void changePoints(int);

};

#endif // NEWGAMEWIZARD_H
