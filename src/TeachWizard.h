#ifndef TEACHWIZARD_H
#define TEACHWIZARD_H

#include <QtGui>


class TeachWizard : public QWizard
{
    Q_OBJECT

public:
    TeachWizard(QWidget *parent = 0);
    TeachWizard(int, QWidget *parent = 0);

private:
    QWizardPage* createPage(QWidget* pwgt, QString strTitle);
};

#endif // TEACHWIZARD_H
