#ifndef DIALGOTEST_H
#define DIALGOTEST_H

#include <QDialog>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include <QFrame>
#include <QComboBox>
#include <QLabel>


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
    
    QPushButton *customMessageBtn;
    QLabel *label;
    


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
    
    void showCustomMessage();


};

#endif // DIALGOTEST_H
