#include "GraphMapWidget.h"

GraphMapWidget::GraphMapWidget(MapWidget *mw) : QWidget()
{
    this->mw=mw;
    QDir::setCurrent(mw->getWidget()->getModel()->getMainDir().path()+"/Pictures");
    pal1.setBrush(this->backgroundRole(), QBrush(QPixmap("space.jpg")));
    QDir::setCurrent(mw->getWidget()->getModel()->getMainDir().path());
    this->setPalette(pal1);
    this->setAutoFillBackground(true);
    this->setObjectName("gmw");

    pbxLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    this->setLayout(pbxLayout);

}

void GraphMapWidget::paintEvent(QPaintEvent *)
{


//    QTime midnight(0,0,0);
//    qsrand(midnight.secsTo(QTime::currentTime()));

//    QPainter painter(this);
//    painter.setRenderHint(QPainter::Antialiasing, true);

//    painter.setPen(QPen(Qt::white, 3, Qt::SolidLine));
//    painter.drawEllipse(QRect(width()/8, height()/8, width()*3/4, height()*3/4));

//    painter.setPen(QPen(Qt::blue, 3, Qt::SolidLine));
//    painter.setBrush(QBrush(Qt::blue, Qt::SolidPattern));
//    qreal r = 3.0/8;
//    qreal x;
//    qreal y;
//    int n = 0;
//    int flag;
//    for (int i=0; i<n; i++)
//    {
//        x = -3.0/8+(qrand() % 6000)*1.0/8000;
//        qDebug()<<"x="<<x;
//        if ((qrand() % 2)==0)
//            flag=-1;
//        else
//            flag=1;
//        y=flag*qSqrt(r*r-x*x);
//        qDebug()<<"y="<<y;
//        painter.drawPoint(width()*(1.0/2+x), height()*(1.0/2+y));
//    }
//    //painter.drawPoint(width()/2, height()/8);
//    //painter.drawPoint(width()*7/8, height()/2);
//    //painter.drawPoint(width()/2, height()*7/8);
//    //painter.drawPoint(width()/8, height()/2);
}
