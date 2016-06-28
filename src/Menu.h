#ifndef MENU_H
#define MENU_H

#include "model.h"
#include "widget.h"
#include "HelpDialog.h"
#include "NewGameWizard.h"

#include <QtGui>

class Menu : public QWidget
{
    Q_OBJECT
public:
    Menu(QWidget *parent = 0);
    Menu(QDir, QWidget *parent = 0);
    int removeFolder(QDir&);
    void create();
private:

        QPalette pal1;
        QGridLayout* gLayout;

        QDir mainDir;
        QDir savesDir;
        QDir loadDir;

        QVBoxLayout* vLayout;

        QPushButton* new0;

        QPushButton* load;
        QMenu* loadMenu;
        QAction* loadAction;
        QString loadName;

        QPushButton* help;
        HelpDialog* helpDialog;

        QPushButton* exit;

        Model* model;

        QWidget* w;

signals:

public slots:
        void slotLoad();
        void slotSave();
        void slotClose();
        void slotIncDay();
        void slotIncPeriod();
        void slotHelp();
        void slotNew();
};

#endif // MENU_H
