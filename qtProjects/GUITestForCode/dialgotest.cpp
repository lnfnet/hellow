#include "dialgotest.h"
#include <QFileDialog>
#include <QLayout>
#include <qstring.h>
#include <qcolordialog.h>
#include <QFontDialog>
#include <qinputdialog.h>

dialgoTest::dialgoTest(QDialog *parent) : QDialog(parent)
{

    fileBtn = new QPushButton();
    fileBtn ->setText(tr("文件标准对话框实例"));
    fileLineEdit = new QLineEdit();

    colorBtn = new QPushButton();
    colorBtn ->setText(tr("着色标准对话框"));
    colorFrame = new QFrame();
    colorFrame ->setFrameShape(QFrame::Box);
    colorFrame ->setAutoFillBackground(true);

    fontBtn = new QPushButton();
    fontBtn ->setText(tr("字体选择对话框"));
    fontLineEdit = new QLineEdit();
    fontLineEdit ->setText("welcome!");

    nameBtn = new QPushButton();
    nameBtn ->setText(tr("改变名字对话框"));
    nameLineEdit = new QLineEdit();
    nameLineEdit ->setText(tr("赖南飞"));

    mainLayout = new QGridLayout(this);
    mainLayout ->addWidget(fileBtn,0,0);
    mainLayout ->addWidget(fileLineEdit,0,1);
    mainLayout ->addWidget(colorBtn,1,0);
    mainLayout ->addWidget(colorFrame,1,1);
    mainLayout ->addWidget(fontBtn,2,0);
    mainLayout ->addWidget(fontLineEdit,2,1);
    mainLayout ->addWidget(nameBtn,3,0);
    mainLayout ->addWidget(nameLineEdit,3,1);

    connect(fileBtn,SIGNAL(clicked()),this,SLOT(showFile()));
    connect(colorBtn,SIGNAL(clicked()),this,SLOT(showColor()));
    connect(fontBtn,SIGNAL(clicked()),this,SLOT(showFont()));
    connect(nameBtn,SIGNAL(clicked()),this,SLOT(changeName()));
}

void dialgoTest::showFile()
{
    QString s = QFileDialog::getOpenFileName(this,"open file dialog","/",
                                             "c++ file(*.cpp)::c file(*.c)::Head files(*.h)");
   //只能过滤 .h后辍文件
    fileLineEdit ->setText(s);
}

void dialgoTest::showColor()
{
    QColor c =QColorDialog::getColor(Qt::blue);
    if(c.isValid())
    {
        colorFrame ->setPalette(QPalette(c));
    }
}

void dialgoTest::showFont()
{
    bool ok;
    QFont f =QFontDialog::getFont(&ok);
    if(ok)
    {
       fontLineEdit->setFont(f);
    }

}

void dialgoTest::changeName()
{
    bool ok;
    QString text=QInputDialog::getText(this,tr("标准字符输入对话框"),
           tr("请输入姓名："),QLineEdit::Normal,nameLineEdit->text(),&ok);
    if(ok&&!text.isEmpty())
    {
        nameLineEdit->setText(text);
    }
}
