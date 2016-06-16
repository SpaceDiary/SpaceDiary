#ifndef STATISTICWIDGET_H
#define STATISTICWIDGET_H

#include <QtGui>

class StatisticWidget : public QWidget
{
        Q_OBJECT

        public:
            StatisticWidget(QWidget *parent = 0);
            StatisticWidget(QList<int>, QList<int>, QWidget *parent = 0);

        private:
//            QList<int> resources;
//            QList<int> date;

            QPalette pal1;
            QBoxLayout* pbxLayout;

            QBoxLayout* resourceLayout;

            QBoxLayout* lifeLayout;
            QWidget* wLife;
            QPalette lifePall;
            int iLife;
            QString sLife;
            QLabel* lLife;

            QBoxLayout* distructionLayout;
            QWidget* wDistruction;
            QPalette distructionPall;
            int iDistruction;
            QString sDistruction;
            QLabel* lDistruction;

            QBoxLayout* creationLayout;
            QWidget* wCreation;
            QPalette creationPall;
            int iCreation;
            QString sCreation;
            QLabel* lCreation;

            QBoxLayout* absLayout;
            QWidget* wAbs;
            QPalette absPall;
            int iAbs;
            QString sAbs;
            QLabel* lAbs;

            QBoxLayout* dateLayout;           
            int iDay;
            QString sDay;
            int iPeriod;
            QString sPeriod;
            QLabel* lDate;

//        public slots:
//            void slotIncDay();
//            void slotIncPeriod();
//            void slotSave();

};

#endif // STATISTICWIDGET_H
