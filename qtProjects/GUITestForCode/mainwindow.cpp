#include "mainwindow.h"
#include <qpushbutton.h>
#include <qapplication.h>

#include <qdockwidget.h>
#include <qtextedit.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

//窗口停拷
    setWindowTitle(tr("DockWindows  for QMainWindos"));
    QTextEdit *te = new QTextEdit(this);
    te->setText(tr("main windows"));
    te->setAlignment(Qt::AlignCenter);
    setCentralWidget(te); //设成主窗口的中央窗体
//停靠部件1 可以关闭和移动
    QDockWidget *dock1 = new QDockWidget(tr("DockWidget1"),this);
    dock1->setFeatures(QDockWidget::DockWidgetClosable|QDockWidget::DockWidgetFloatable);
    dock1->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
    QTextEdit *te1 = new QTextEdit(this);
    te1->setText(tr("dock1 window"));
    te1->setAlignment(Qt::AlignCenter);
    dock1->setWidget(te1);
    addDockWidget(Qt::RightDockWidgetArea,dock1);
//停靠部件2  所有特性
    QDockWidget *dock2 = new QDockWidget(tr("DockWidget2"),this);
    dock2->setFeatures(QDockWidget::AllDockWidgetFeatures);
    dock2->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
    QTextEdit *te2 = new QTextEdit(this);
    te2->setText(tr("dock2 window"));
    te2->setAlignment(Qt::AlignCenter);
    dock2->setWidget(te2);
    addDockWidget(Qt::RightDockWidgetArea,dock2);
//停靠部件3
    QDockWidget *dock3 = new QDockWidget(tr("DockWidget3"),this);
    dock3->setFeatures(QDockWidget::DockWidgetMovable);
    dock3->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
    QTextEdit *te3 = new QTextEdit(this);
    te3->setText(tr("dock3 window"));
    te3->setAlignment(Qt::AlignCenter);
    dock3->setWidget(te3);
    addDockWidget(Qt::RightDockWidgetArea,dock3);
}

MainWindow::~MainWindow()
{


}
