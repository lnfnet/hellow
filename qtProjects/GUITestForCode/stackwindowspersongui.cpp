#include "stackwindowspersongui.h"

#include <QLayout>
#include <QHBoxLayout>

stackWindowsPersonGui::stackWindowsPersonGui(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("stackedWidgetsPersonGUI for widgets");
    list = new QListWidget(this);
    list->insertItem(0,tr("人员信息"));
    list->insertItem(1,tr("window1"));
    list->insertItem(2,tr("window2"));

    label1= new QLabel(tr("窗口1"));
    label2= new QLabel(tr("WindwoTest2"));
    label3= new QLabel(tr("WindwoTest3"));

    stack= new QStackedWidget(this);
    person_gui = new personGui();

    stack->addWidget(person_gui);
    stack->addWidget(person_gui);
    stack->addWidget(person_gui);

    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->setMargin(5);
    mainLayout->setSpacing(5);
    mainLayout->addWidget(list);
    mainLayout->addWidget(stack,0,Qt::AlignHCenter);
    mainLayout->setStretchFactor(list,1);
    mainLayout->setStretchFactor(stack,3);

    connect(list,SIGNAL(currentRowChanged(int)),stack,SLOT(setCurrentIndex(int)));
    //用列表的当前行变更信号--绑定stack 里的设置当前索引
}
