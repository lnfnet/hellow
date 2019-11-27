#ifndef PERSONGUI_H
#define PERSONGUI_H

#include <QMainWindow>
#include <qlabel.h>
#include <qlineedit.h>
#include <qcombobox.h>
#include <QHBoxLayout>
#include <qtextedit.h>
#include <qpushbutton.h>
#include <qdialog.h>

class personGui : public QDialog
{
    Q_OBJECT
private:
    QLabel *UserNameLabel;
    QLabel *NameLabel;
    QLabel *SexLabel;
    QLabel *DepartmentLabel;
    QLabel *AgeLabel;
    QLabel *OtherLabel;
    QLineEdit *UserNameLinEdit;
    QLineEdit *NameLineEdit;
    QComboBox *SexCoBox;
    QTextEdit *DepartmentTextEdit;
    QLineEdit *AgeLineEdit;

    QGridLayout *leftLayout;

    QLabel *HeadLabel;
    QLabel *HeadIconLabel;
    QPushButton *UpdateHeadBtn;
    QHBoxLayout *TopRightLayout;

    QLabel *IntroductionLabel;
    QTextEdit *IntroductionTextEdit;
    QVBoxLayout * RightLayout;

    QPushButton *okBtn;
    QPushButton *CancelBtn;
    QHBoxLayout *ButtomLayout;



public:
    explicit personGui(QWidget *parent = 0);

signals:

public slots:
};

#endif // PERSONGUI_H
