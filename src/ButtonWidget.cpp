#include "ButtonWidget.h"

ButtonWidget::ButtonWidget(QWidget *parent)
    : QWidget(parent)
{
    pal1.setColor(this->backgroundRole(), Qt::blue);
    this->setPalette(pal1);
    this->setAutoFillBackground(true);
    this->setObjectName("bw");
    pbxLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    this->setLayout(pbxLayout);

    game = new QPushButton("Game");
    pbxLayout->addWidget(game, 1);
    game->setObjectName("game");
    gameMenu = new QMenu();
    game->setMenu(gameMenu);

    save = new QAction(tr("Save"), game);
    gameMenu->addAction(save);
    save->setObjectName("save");

    close = new QAction(tr("Close"), game);
    gameMenu->addAction(close);
    close->setObjectName("close");

    complete = new QPushButton("Complete");
    pbxLayout->addWidget(complete, 1);
    complete->setObjectName("complete");
    completeMenu = new QMenu();
    complete->setMenu(completeMenu);

    day = new QAction(tr("Day"), complete);
    completeMenu->addAction(day);
    day->setObjectName("day");

    period = new QAction(tr("Period"), complete);
    completeMenu->addAction(period);
    period->setObjectName("period");

    help = new QPushButton("Help");
    pbxLayout->addWidget(help, 1);
    help->setObjectName("help");
}







