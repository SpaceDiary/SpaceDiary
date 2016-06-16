#ifndef TEACHDIALOG_H
#define TEACHDIALOG_H

#include <QtGui>

#include "unit.h"
#include "dictionary.h"

class TeachDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TeachDialog(QWidget *parent = 0);
    TeachDialog(Unit*, int, QWidget *parent = 0);

private:
    Unit* teacher;
    QList<Unit*> units;

    int mode;
    int maxSkills;
    int skills;
    int maxDisciples;
    int disciples;

    QList<QString> oldSkills;
    QList<QString> newSkills;

    QBoxLayout* pbxLayout;

    QBoxLayout* skillsLayout;
    QLabel* lSkills;
    QCheckBox* skillBox;
    QList<QCheckBox*> skillBoxes;

    QBoxLayout* disciplesLayout;
    QLabel* lDisciples;
    QCheckBox* discipleBox;
    QList<QCheckBox*> discipleBoxes;
    QList<Unit*> availableUnits;


    QList<QString> checkedSkills;
    QList<QString> checkedDisciples;
    QList<Unit*> checkedUnits;

    QPushButton* ok;
    QPushButton* cancel;

public slots:
    void changeSkills();
    void changeDisciples();
    void saveChecks();

};

#endif // TEACHDIALOG_H
