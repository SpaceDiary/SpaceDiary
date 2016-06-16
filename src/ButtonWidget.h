#ifndef ButtonWidget_H
#define ButtonWidget_H

#include <QtGui>

class ButtonWidget : public QWidget
{
        Q_OBJECT

        public:
            ButtonWidget(QWidget *parent = 0);

        private:

                QPalette pal1;
                QBoxLayout* pbxLayout;

                QPushButton* help;

                QPushButton* complete;
                QMenu* completeMenu;
                QAction *day;
                QAction *period;

                QPushButton* game;
                QMenu* gameMenu;
                QAction* save;
                QAction* close;

};
#endif//ButtonWidget_H
