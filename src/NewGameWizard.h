#ifndef NEWGAMEWIZARD_H
#define NEWGAMEWIZARD_H

#include <QtGui>

class NewGameWizard : public QWizard
{
    Q_OBJECT
public:
    NewGameWizard(QWidget *parent = 0);
    QWizardPage* createPlanetsPage();
    QWizardPage* createSkillsPage();
    bool validateCurrentPage();

private:
    QGridLayout* gLayout;

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


signals:

public slots:
    int changePoints(int);

};

#endif // NEWGAMEWIZARD_H
