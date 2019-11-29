#ifndef DIALGOTEST_H
#define DIALGOTEST_H

#include <QDialog>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
//#include <QColorDialog>

class dialgoTest : public QDialog
{
    Q_OBJECT
public:
    QPushButton *fileBtn;
    QLineEdit *fileLineEdit;
    //QPushButton *colorBtn;
    //QFrame *colorFrame;


    QGridLayout *mainLayout;

    explicit dialgoTest(QDialog *parent = 0);

signals:

public slots:
    void showFile();
    //void showColor();
};

#endif // DIALGOTEST_H
