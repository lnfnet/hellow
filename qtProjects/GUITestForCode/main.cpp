#include "mainwindow.h"
#include "stackedwidget.h"
//#include "persongui.h"
#include "stackwindowspersongui.h"
#include "dialgotest.h"

#include <QApplication>
#include <qfont.h>
#include <qsplitter.h>
#include <qtextedit.h>
#include <guitest.h>
#include <dialog.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //设置程序字体
    QFont font("ZYSong18030",12);
    a.setFont(font);
    //主分割
    QSplitter *splitterMain  =new QSplitter(Qt::Horizontal,0);
    QTextEdit *textLeft = new QTextEdit(QObject::tr("Left Widget"),splitterMain);
    textLeft->setAlignment(Qt::AlignCenter);
    //右分割 水平分割
    QSplitter *splitterRight  =new QSplitter(Qt::Vertical,splitterMain);
    splitterRight -> setOpaqueResize(false);

    QTextEdit *textUp = new QTextEdit(QObject::tr("Top Widget"),splitterRight);
    textUp->setAlignment(Qt::AlignCenter);

    QTextEdit *textBottom = new QTextEdit(QObject::tr("Bottom Widget"),splitterRight);
    textBottom->setAlignment(Qt::AlignCenter);

    QTextEdit *textMiddle = new QTextEdit(QObject::tr("Middle Widget"),splitterRight);
    textMiddle->setAlignment(Qt::AlignCenter);

    splitterMain->setStretchFactor(1,1);
    splitterMain->setWindowTitle(QObject::tr("Splitter for main faction"));
    splitterMain->show();
//  ///////////////////////////////////////////////////////////////////////////////

    MainWindow w;
    w.show();

    stackedWidget s;
    s.show();

    guiTest g;
    g.show();

    personGui p;
    p.show();

    stackWindowsPersonGui wp;
    wp.show();

    dialgoTest d;
    d.show();

    Dialog mytoolbox;
    mytoolbox.show();


    return a.exec();
}
