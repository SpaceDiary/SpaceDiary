#include "HelpDialog.h"

HelpDialog::HelpDialog(QWidget* pwgt/*= 0*/)
    : QDialog(pwgt, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
{
    this->setModal(true);
    gLayout = new QGridLayout();
    this->setLayout(gLayout);
    this->setMinimumSize(1000, 1000);

    QTabWidget* tw = new QTabWidget();
    gLayout->addWidget(tw, 0, 0, 9, 9);
    tw->addTab(new QLabel("Something about the game"), "About");
    tw->addTab(new QLabel("something about game process"), "Game process");
    tw->addTab(new QLabel("something about moving"), "Moving");
    tw->addTab(new QLabel("something about economy"), "Economy");
    tw->addTab(new QLabel("something about demography"), "Demography");
    tw->addTab(new QLabel("something about abilities"), "Abilities");
    tw->addTab(new QLabel("something about diplomacy and trade"), "Diplomacy and trade");
    tw->addTab(new QLabel("something about space battle"), "Space battle");

    cancel = new QPushButton("Cancel");
    gLayout->addWidget(cancel, 9, 9, 1, 1);
    cancel->setObjectName("cancel");
    QObject::connect(this->findChild<QObject*>("cancel"), SIGNAL(clicked()), this, SLOT(close()));

    setWindowTitle("Help");
}

void HelpDialog::slotSetText()
{

}

