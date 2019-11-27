#ifndef ADDNUMBERDIALOG_H
#define ADDNUMBERDIALOG_H

#include <QDialog>

namespace Ui {
class AddNumberDialog;
}

class AddNumberDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddNumberDialog(QWidget *parent = 0);
    ~AddNumberDialog();

private slots:


    void on_countBtn_clicked();

private:
    Ui::AddNumberDialog *ui;
};

#endif // ADDNUMBERDIALOG_H
