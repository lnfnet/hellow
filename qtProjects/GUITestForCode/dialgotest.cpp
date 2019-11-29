#include "dialgotest.h"
#include <QFileDialog>
#include <QLayout>
#include <qstring.h>
//#include <qcolordialog.h>

dialgoTest::dialgoTest(QDialog *parent) : QDialog(parent)
{

    fileBtn = new QPushButton();
    fileBtn ->setText(tr("文件标准对话框实例"));
    fileLineEdit = new QLineEdit();

   // colorBtn = new QPushButton();
    //colorBtn ->setText(tr("着色标准对话框"));
   // colorFrame = new QFrame;
    //colorFrame ->setFrameShape(QFrame::Box);
    //colorFrame ->setAutoFillBackground(true);

    mainLayout = new QGridLayout(this);
    mainLayout ->addWidget(fileBtn,0,0);
    mainLayout ->addWidget(fileLineEdit,0,1);
    //mainLayout ->addWidget(colorBtn,1,0);
    //mainLayout ->addWidget(colorFrame,1,1);

    connect(fileBtn,SIGNAL(clicked()),this,SLOT(showFile()));
    //connect(colorBtn,SIGNAL(clicked()),this,SLOT(showColor()));
}

void dialgoTest::showFile()
{
    QString s = QFileDialog::getOpenFileName(this,"open file dialog","/",
                                             "c++ file(*.cpp)::c file(*.c)::Head files(*.h)");
   //只能过滤 .h后辍文件
    fileLineEdit ->setText(s);

}

/*
void dialgoTest::showColor()
{
    QColor c =QColorDialog::getColor(Qt::blue);
    if(c.isValid())
    {
        colorFrame ->setPalette(QPalette(c));
    }
}
*/
