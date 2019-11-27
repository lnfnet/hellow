#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QApplication>
#include <QMainWindow>
#include <QListWidget>
#include <QStackedWidget>
#include <QLabel>

class Dialog : public QDialog
{
    Q_OBJECT
private:
    QListWidget *list;
    QStackedWidget *stack;
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
};

#endif // DIALOG_H
