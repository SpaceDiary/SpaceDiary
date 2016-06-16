#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

}

Widget::Widget(Model* model, QWidget *parent)
    : QWidget(parent)
{
    this->model=model;
    this->setWindowFlags(Qt::WindowMinimizeButtonHint);
    this->showFullScreen();
    layout = new QGridLayout;
    this->setLayout(layout);
    this->setMinimumSize(700, 400);
    setWindowTitle(tr("Space diary"));
    this->show();

    bw = new ButtonWidget(this);
    layout->addWidget(bw, 0, 0, 1, 1, 0);

    mw = new MapWidget(model->getSectors(), this);
    layout->addWidget(mw, 1, 0, 9, 1, 0);

    sw = new StatisticWidget(model->getResources(), model->getDate(), this);
    layout->addWidget(sw, 10, 0, 1, 1, 0);
}

Widget::~Widget()
{

}
