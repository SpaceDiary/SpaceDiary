#include "TeachWizard.h"

TeachWizard::TeachWizard(QWidget* pwgt/*= 0*/)
    : QWizard(pwgt)
{

}

TeachWizard::TeachWizard(int mode, QWidget* pwgt/*= 0*/)
    : QWizard(pwgt)
{
    this->show();
    addPage(createPage(new QLabel("<H1>Label 1</H1>"), "One"));
    addPage(createPage(new QLabel("<H1>Label 2</H1>"), "Two"));
    addPage(createPage(new QLabel("<H1>Label 3</H1>"), "Three"));
}

QWizardPage* TeachWizard::createPage(QWidget* pwgt, QString strTitle)
{
    QWizardPage* ppage = new QWizardPage;
    ppage->setTitle(strTitle);
    QVBoxLayout* playout = new QVBoxLayout;
    playout->addWidget(pwgt);
    ppage->setLayout(playout);
    return ppage;
}
