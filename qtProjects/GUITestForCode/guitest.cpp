#include "guitest.h"
#include <qfont.h>
#include <qlabel.h>
#include <qdatetime.h>
#include <qtimer.h>
#include <qtextedit.h>
#include <qpushbutton.h>
#include <qapplication.h>

guiTest::guiTest(QWidget *parent) : QWidget(parent)
{


//setMinimumSize(200,120);
//setMaximumSize(800,600);

QPushButton *quit=new QPushButton("quit",this);
quit->setGeometry(62,40,75,30);
quit->setFont(QFont("Times",18,QFont::Bold));

connect(quit,SIGNAL(clicked()),qApp,SLOT(quit()) );

QLabel *datalabel =new QLabel(this);
QDateTime *datatime=new QDateTime(QDateTime::currentDateTime());
datalabel->setText(datatime->date().toString());
datalabel->show();

QTimer *time_clock=new QTimer(parent);
connect(time_clock,SIGNAL(timeout()),this,SLOT(slottimedone()));
time_clock->start(2000);
}
