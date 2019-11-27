#include "stackedwidget.h"
#include <QLayout>
#include <QHBoxLayout>
stackedWidget::stackedWidget(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("stackedWidget for dialog");
    list = new QListWidget(this);
    list->insertItem(0,tr("window0"));
    list->insertItem(1,tr("window1"));
    list->insertItem(2,tr("window2"));

    label1= new QLabel(tr("窗口1"));
    label2= new QLabel(tr("WindwoTest2"));
    label3= new QLabel(tr("WindwoTest3"));

    stack= new QStackedWidget(this);
    stack->addWidget(label1);
    stack->addWidget(label2);
    stack->addWidget(label3);

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

stackedWidget::~stackedWidget()
{
}
