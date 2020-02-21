#ifndef PALATTE_H
#define PALATTE_H

#include <QObject>
#include <QDialog>
#include <QComboBox>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QLineEdit>


class palatte : public QDialog
{
    Q_OBJECT
public:
    palatte(QWidget *parent=0);
    ~palatte();
    void createCtrlFrame();
    void createContentFrame();
    void fillColorList(QComboBox *);
private slots:
    void ShowWindow();
    void ShowWindowText();
    void ShowButton();
    void ShowButtonText();
    void ShowBase();

private:
    QFrame *ctrlFrame;
    QFrame *contentFrame;
    
    QLabel *windowLabel;
    QComboBox *windowComboBox;
    
    QLabel *windowTextLabel;
    QComboBox *windowTextComboBox;
    
    QLabel *buttonLabel;
    QComboBox *buttonCombox;
    
    QLabel *buttonTextLabel;
    QComboBox *buttonTextComboBox;
    
    QLabel *baseLabel;
    QComboBox *baseComboBox;

    QLabel *label1;
    QLabel *label2;
    QComboBox *comboBox1;
    QLineEdit *lineEdit2;
    QTextEdit *testEdit;
    QPushButton *okBtn;
    QPushButton *cancelBtn;

    

};

#endif // PALATTE_H
