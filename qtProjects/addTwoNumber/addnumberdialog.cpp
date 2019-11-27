#include "addnumberdialog.h"
#include "ui_addnumberdialog.h"

const static double PI = 3.1416;
AddNumberDialog::AddNumberDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNumberDialog)
{
    ui->setupUi(this);
}

AddNumberDialog::~AddNumberDialog()
{
    delete ui;
}



void AddNumberDialog::on_countBtn_clicked()
{
    bool ok;
    QString tempStr;
    QString valueStr=ui->lineEditRadios->text();
    int valueInt=valueStr.toInt(&ok);
    double area=valueInt*valueInt*PI;
    ui->lineEditArea->setText(tempStr.setNum(area));
}
