#ifndef PROGRESSDLG_H
#define PROGRESSDLG_H

#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QGridLayout>
#include <QProgressBar>
#include <QDialog>



class ProgressDlg : public QDialog
{
    Q_OBJECT
public:
    ProgressDlg(QWidget *parent=0);
private slots:
    void startProgress();
private:
    QLabel *FileNum;
    QLineEdit *FileNumLineEdit;
    QLabel *ProgressType;
    QComboBox *comboBox;
    QProgressBar *progressBar;
    QPushButton *startBtn;
    QGridLayout *mainLayout;

};

#endif // PROGRESSDLG_H
