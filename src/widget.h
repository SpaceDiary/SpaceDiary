#ifndef WIDGET_H
#define WIDGET_H

#include "ButtonWidget.h"
#include "MapWidget.h"
#include "StatisticWidget.h"
#include "model.h"

#include <QtGui>

class MapWidget;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    Widget(Model*, QWidget *parent = 0);
    ~Widget();
    Model* getModel() {return model;}

private:
    Model* model;
    ButtonWidget* bw;
    MapWidget* mw;
    StatisticWidget* sw;
    QGridLayout* layout;

};

#endif // WIDGET_H
