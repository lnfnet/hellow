#ifndef STACKWINDOWSPERSONGUI_H
#define STACKWINDOWSPERSONGUI_H


#include <QMainWindow>
#include <QListWidget>
#include <QStackedWidget>
#include <QLabel>
#include <qdialog.h>
#include "persongui.h"  //注意
#include <QWidget>

class stackWindowsPersonGui : public QWidget
{
    Q_OBJECT

private:
    QListWidget *list;
    QStackedWidget *stack;
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    personGui *person_gui;

public:
    explicit stackWindowsPersonGui(QWidget *parent = 0);

signals:

public slots:
};

#endif // STACKWINDOWSPERSONGUI_H
