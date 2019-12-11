#ifndef DIALGOTEST_H
#define DIALGOTEST_H

#include <QDialog>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include <QFrame>
#include <QComboBox>

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
    QPushButton *sexBtn;
    QComboBox *sexComboBox;

    QPushButton *questionBtn;
    QPushButton *infomationBtn;
    QPushButton *warningBtn;
    QPushButton *criticalBtn;
    QPushButton *aboutBtn;
    QPushButton *aboutQtBtn;


    QGridLayout *mainLayout;


public:
    explicit dialgoTest(QDialog *parent = 0);

signals:

private slots:
    void showFile();
    void showColor();
    void showFont();
    void changeName();
    void changeSex();

    void showQuestionMsg();
    void showInfomaingMsg();
    void showWarningMsg();
    void showCriticalMsg();
    void showAboutMsg();
    void showAboutQtMsg();


};

#endif // DIALGOTEST_H
