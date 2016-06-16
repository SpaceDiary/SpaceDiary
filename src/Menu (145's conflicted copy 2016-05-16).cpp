#include "Menu.h"

Menu::Menu(QWidget *parent) : QWidget(parent)
{

}

Menu::Menu(QDir savesDir, QWidget *parent)
{
    this->show();
//    this->setWindowFlags(Qt::WindowMinimizeButtonHint);
//    this->showFullScreen();
    pal1.setColor(this->backgroundRole(), Qt::blue);
    this->setPalette(pal1);
    this->setAutoFillBackground(true);
    this->setObjectName("menu");
    this->setFixedSize(200, 100);
    setWindowTitle(tr("Tolerant diary"));
    pbxLayout = new QBoxLayout(QBoxLayout::TopToBottom);
    this->setLayout(pbxLayout);

    this->savesDir=savesDir;

    new0 = new QPushButton("New");
    pbxLayout->addWidget(new0, 1);
    new0->setObjectName("new");

    load = new QPushButton("Load");
    pbxLayout->addWidget(load, 1);
    load->setObjectName("load");
    loadMenu = new QMenu();
    load->setMenu(loadMenu);
    for (int i=0; i<savesDir.entryList().size(); i++)
    {
        loadAction = new QAction(savesDir.entryList().at(i), load);
        loadMenu->addAction(loadAction);
        loadAction->setObjectName(savesDir.entryList().at(i));
        loadName=savesDir.entryList().at(i);
        QObject::connect(this->findChild<QObject*>("load")->findChild<QObject*>(loadName), SIGNAL(triggered()), this, SLOT(slotLoad()));
    }

    exit = new QPushButton("Exit");
    pbxLayout->addWidget(exit, 1);
    exit->setObjectName("exit");
}

void Menu::slotLoad()
{
    QDir saveDir;
    saveDir.setPath(savesDir.path()+"/"+QObject::sender()->objectName());
    Model* model = new Model(saveDir);
    Widget* w = new Widget(model);
    this->hide();
}
