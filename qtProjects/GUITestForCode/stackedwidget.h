#ifndef STACKEDWIDGET_H
#define STACKEDWIDGET_H

#include <QMainWindow>
#include <QListWidget>
#include <QStackedWidget>
#include <QLabel>
#include <qdialog.h>

class stackedWidget : public QDialog
{
    Q_OBJECT
private:
    QListWidget *list;
    QStackedWidget *stack;
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;


public:
    stackedWidget(QWidget *parent = 0);
    ~stackedWidget();
};

#endif // STACKEDWIDGET_H
