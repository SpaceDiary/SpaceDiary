#include "Menu.h"

Menu::Menu(QWidget *parent) : QWidget(parent)
{

}

Menu::Menu(QDir mainDir, QWidget*)
{
    this->setWindowFlags(Qt::WindowMinimizeButtonHint);
    this->showFullScreen();
    QDir::setCurrent(mainDir.path()+"/images");
    pal1.setBrush(this->backgroundRole(), QBrush(QPixmap("space.jpg")));
    QDir::setCurrent(mainDir.path());
    this->setPalette(pal1);
    this->setAutoFillBackground(true);
    this->setObjectName("menu");
    setWindowTitle(tr("Space Chronicles"));
    this->show();
    gLayout = new QGridLayout();
    this->setLayout(gLayout);

    this->mainDir=mainDir;

    vLayout = new QVBoxLayout();
    QVBoxLayout* v2layout = new QVBoxLayout();
    gLayout->addLayout(v2layout, 0, 0, 9, 9);
    gLayout->addLayout(vLayout, 9, 9, 1, 1);

    new0 = new QPushButton("New game");
    vLayout->addWidget(new0, 1);
    new0->setObjectName("new");
    QObject::connect(this->findChild<QObject*>("new"), SIGNAL(clicked()), this, SLOT(slotNew()));


    load = new QPushButton("Load game");
    vLayout->addWidget(load, 1);
    load->setObjectName("load");
    loadMenu = new QMenu();
    load->setMenu(loadMenu);

    savesDir.setPath(mainDir.path()+"/saves");
    for (int i=0; i<savesDir.entryList().size(); i++)
    {
        QDir saveDir;
        saveDir.setPath(savesDir.path()+"/"+savesDir.entryList().at(i));
        if (saveDir.dirName().endsWith(".tlr"))
        {
            loadAction = new QAction(savesDir.entryList().at(i), load);
            loadMenu->addAction(loadAction);
            loadAction->setObjectName(savesDir.entryList().at(i));
            loadName=savesDir.entryList().at(i);
            QObject::connect(this->findChild<QObject*>("load")->findChild<QObject*>(loadName), SIGNAL(triggered()), this, SLOT(slotLoad()));
        }
    }

    help = new QPushButton("Help");
    vLayout->addWidget(help, 1);
    help->setObjectName("help");
    QObject::connect(this->findChild<QObject*>("help"), SIGNAL(clicked()), this, SLOT(slotHelp()));


    exit = new QPushButton("Exit");
    vLayout->addWidget(exit, 1);
    exit->setObjectName("exit");
}

void Menu::slotLoad()
{
    loadDir.setPath(savesDir.path()+"/"+QObject::sender()->objectName());
    model = new Model(mainDir, loadDir);
    create();
    this->hide();
}

void Menu::slotSave()
{
    removeFolder(loadDir);
    loadDir.mkdir(savesDir.path()+"/"+loadDir.dirName());
    model->save(loadDir);
}

void Menu::slotClose()
{
    delete model;
    delete w;
    this->showFullScreen();
}

void Menu::slotIncDay()
{
    model->incDay();
    delete w;
    create();
}

void Menu::slotIncPeriod()
{
    model->incPeriod();
    delete w;
    create();
}

void Menu::create()
{
    w = new Widget(model);
    QObject::connect(w->findChild<QObject*>("bw")->findChild<QObject*>("game")->findChild<QObject*>("save"), SIGNAL(triggered()), this, SLOT(slotSave()));
    QObject::connect(w->findChild<QObject*>("bw")->findChild<QObject*>("game")->findChild<QObject*>("close"), SIGNAL(triggered()), this, SLOT(slotClose()));
    QObject::connect(w->findChild<QObject*>("bw")->findChild<QObject*>("complete")->findChild<QObject*>("day"), SIGNAL(triggered()), this, SLOT(slotIncDay()));
    QObject::connect(w->findChild<QObject*>("bw")->findChild<QObject*>("complete")->findChild<QObject*>("period"), SIGNAL(triggered()), this, SLOT(slotIncPeriod()));
    QObject::connect(w->findChild<QObject*>("bw")->findChild<QObject*>("help"), SIGNAL(clicked()), this, SLOT(slotHelp()));

}

void Menu::slotHelp()
{
    helpDialog = new HelpDialog();
    helpDialog->show();
}

void Menu::slotNew()
{
    NewGameWizard* newGameWizard = new NewGameWizard();
    newGameWizard->show();
}

//Функция удаления папки
int Menu::removeFolder(QDir & dir)
{
  int res = 0;
  //Получаем список каталогов
  QStringList lstDirs = dir.entryList(QDir::Dirs |
                  QDir::AllDirs |
                  QDir::NoDotAndDotDot);
  //Получаем список файлов
  QStringList lstFiles = dir.entryList(QDir::Files);

  //Удаляем файлы
  foreach (QString entry, lstFiles)
  {
   QString entryAbsPath = dir.absolutePath() + "/" + entry;
   QFile::setPermissions(entryAbsPath, QFile::ReadOwner | QFile::WriteOwner);
   QFile::remove(entryAbsPath);
  }

  //Для папок делаем рекурсивный вызов
  foreach (QString entry, lstDirs)
  {
   QString entryAbsPath = dir.absolutePath() + "/" + entry;
   QDir dr(entryAbsPath);
   removeFolder(dr);
  }

  //Удаляем обрабатываемую папку
  if (!QDir().rmdir(dir.absolutePath()))
  {
    res = 1;
  }
  return res;
}
