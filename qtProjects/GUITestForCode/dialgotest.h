#ifndef DIALGOTEST_H
#define DIALGOTEST_H

#include <QDialog>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include <QFrame>

class dialgoTest : public QDialog
{
    Q_OBJECT
private:
    QPushButton *fileBtn;
    QLineEdit *fileLineEdit;
    QPushButton *colorBtn;
    QFrame *colorFrame;
    QPushButton *fontBtn;
    QLineEdit *fontLineEdit;
    QPushButton *nameBtn;
    QLineEdit *nameLineEdit;
    QGridLayout *mainLayout;
public:
    explicit dialgoTest(QDialog *parent = 0);

signals:

private slots:
    void showFile();
    void showColor();
    void showFont();
    void changeName();

};

#endif // DIALGOTEST_H
