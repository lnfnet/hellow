#include "dialgotest.h"
#include <QFileDialog>
#include <QLayout>
#include <qstring.h>
#include <qcolordialog.h>
#include <QFontDialog>
#include <qinputdialog.h>
#include <QMessageBox>

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

    sexBtn = new QPushButton("选择性别");
    sexComboBox =new QComboBox();
    sexComboBox ->addItem(tr("男"));
    sexComboBox ->addItem(tr("女"));

    questionBtn = new QPushButton("问题对话框");
    infomationBtn = new QPushButton("信息框");
    warningBtn = new QPushButton("warning!");
    criticalBtn = new QPushButton("critical!");
    aboutBtn = new QPushButton("about");
    aboutQtBtn = new QPushButton("aboutQt");
    
    customMessageBtn = new QPushButton("自定义");
    label = new QLabel;
    label->setFrameStyle(QFrame::Panel|QFrame::Sunken);

    mainLayout = new QGridLayout(this);
    mainLayout ->addWidget(fileBtn,0,0);
    mainLayout ->addWidget(fileLineEdit,0,1);
    mainLayout ->addWidget(colorBtn,1,0);
    mainLayout ->addWidget(colorFrame,1,1);
    mainLayout ->addWidget(fontBtn,2,0);
    mainLayout ->addWidget(fontLineEdit,2,1);
    mainLayout ->addWidget(nameBtn,3,0);
    mainLayout ->addWidget(nameLineEdit,3,1);
    mainLayout ->addWidget(sexBtn,4,0);
    mainLayout ->addWidget(sexComboBox,4,1);

    mainLayout ->addWidget(questionBtn,5,0);
    mainLayout ->addWidget(infomationBtn,5,1);
    mainLayout ->addWidget(warningBtn,6,0);
    mainLayout ->addWidget(criticalBtn,6,1);
    mainLayout ->addWidget(aboutBtn,7,0);
    mainLayout ->addWidget(aboutQtBtn,7,1);
    mainLayout ->addWidget(customMessageBtn,8,0);
    mainLayout ->addWidget(label,8,1);



    connect(fileBtn,SIGNAL(clicked()),this,SLOT(showFile()));
    connect(colorBtn,SIGNAL(clicked()),this,SLOT(showColor()));
    connect(fontBtn,SIGNAL(clicked()),this,SLOT(showFont()));
    connect(nameBtn,SIGNAL(clicked()),this,SLOT(changeName()));
    connect(sexBtn,SIGNAL(clicked(bool)),this,SLOT(changeSex()));

    connect(questionBtn,SIGNAL(clicked(bool)),this,SLOT(showQuestionMsg()));
    connect(infomationBtn,SIGNAL(clicked(bool)),this,SLOT(showInfomaingMsg()));
    connect(warningBtn,SIGNAL(clicked(bool)),this,SLOT(showWarningMsg()));
    connect(criticalBtn,SIGNAL(clicked(bool)),this,SLOT(showCriticalMsg()));
    connect(aboutBtn,SIGNAL(clicked(bool)),this,SLOT(showAboutMsg()));
    connect(aboutQtBtn,SIGNAL(clicked(bool)),this,SLOT(showAboutQtMsg()));

    connect(customMessageBtn,SIGNAL(clicked(bool)),this,SLOT(showCustomMessage()));

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

void dialgoTest::changeSex()
{
    QStringList SexItems;
    SexItems<<tr("男")<<tr("女");

    bool ok;
    QString SexItem= QInputDialog::getItem(this,tr("选择对话框"),
                                            tr("请选选择："),SexItems,0,false,&ok);

    if(ok && !SexItem.isEmpty())
        sexComboBox ->setCurrentText(SexItem);
}

void dialgoTest::showQuestionMsg()
{
    switch (QMessageBox::question(this,tr("Question消息框"),
                                  tr("您现在修改完成，是否结速程序列"),
                                  QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok))
    {
    case QMessageBox::Ok:
        questionBtn->setText("你选的是OKl");
        break;
    case QMessageBox::Cancel:
        questionBtn->setText("你选的是cancel");
        break;
    default:
        break;
    }
    return;

}

void dialgoTest::showInfomaingMsg()
{
    QMessageBox::information(this,tr("infomation消息框"),tr("这是Infomation"));
    return;
}

void dialgoTest::showWarningMsg()
{
     QMessageBox::warning(this,tr("警告消息框"),tr("这是Infomation"));
     return;
}

void dialgoTest::showCriticalMsg()
{
    QMessageBox::critical(this,tr("严重消息框"),tr("这是Infomation"));
    return;
}

void dialgoTest::showAboutMsg()
{
    QMessageBox::about(this,tr("about消息框"),tr("这是Infomation"));
    return;
}

void dialgoTest::showAboutQtMsg()
{
     QMessageBox::aboutQt(this,tr("aboutQt消息框"));
     return;
}

void dialgoTest::showCustomMessage()
{
    label->setText((tr("custom message box")));

    QMessageBox customMsgBox;
    customMsgBox.setWindowTitle(tr("用户自定义消息框"));
    QPushButton *yesBtn=customMsgBox.addButton(tr("yes"),QMessageBox::ActionRole);
    QPushButton *noBtn=customMsgBox.addButton(tr("no"),QMessageBox::ActionRole);
    QPushButton *cancelBtn=customMsgBox.addButton(tr("cancel"),QMessageBox::ActionRole);

    customMsgBox.setText(tr("这是一个用户自定义的消息框!"));
    customMsgBox.setIconPixmap(QPixmap("qt.png"));
    customMsgBox.exec();

    if(customMsgBox.clickedButton()==yesBtn)
        label->setText(tr("custom message box/yes"));
    if(customMsgBox.clickedButton()==noBtn)
        label->setText(tr("custom message box/no"));
    if(customMsgBox.clickedButton()==cancelBtn)
        label->setText(tr("custom message box/cancel"));
    return;
}
