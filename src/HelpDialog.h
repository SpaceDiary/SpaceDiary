#ifndef HELPDIALOG_H
#define HELPDIALOG_H

#include <QtGui>

class HelpDialog : public QDialog
{
    Q_OBJECT
public:
    HelpDialog(QWidget *parent = 0);

private:
    QGridLayout* gLayout;



    QPushButton* cancel;

signals:

public slots:
    void slotSetText();

};

#endif // HELPDIALOG_H
