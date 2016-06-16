#ifndef UNITDIALOG_H
#define UNITDIALOG_H

#include <QtGui>

#include "unit.h"
#include "dictionary.h"
#include "TeachDialog.h"

class UnitDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UnitDialog(QWidget *parent = 0);
    UnitDialog(Unit* unit, QWidget *parent = 0);

private:
    Unit* unit;
    QString sRace;
    QString sAge;
    QString sSkill;
    QLabel* lSkill;
    QString sAction;
    QLabel* lAction;
    QList<QString> oldSkills;
    QList<QString> newSkills;

    QBoxLayout* pbxLayout;
    QBoxLayout* skillsLayout;
    QBoxLayout* actionsLayout;

    QPushButton* extract;
    QPushButton* breed;

    QPushButton* teach;
    QMenu* menuTeach;

    QAction* trainAlone;
    QMenu* menuTrainAlone;
    QAction* skillAction;

    QAction* teachGroup;
    TeachDialog* teachDialog;

    QAction* teachDisciple;

    QPushButton* cancel;


signals:

public slots:
    void teachGroupDialog();
    void teachDiscipleDialog();


};

#endif // UNITDIALOG_H
