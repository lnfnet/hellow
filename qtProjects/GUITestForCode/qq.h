#ifndef QQ_H
#define QQ_H

#include <QToolBox>
#include <qtoolbutton.h>

class qq : public QToolBox
{
    Q_OBJECT
public:
    explicit qq(QWidget *parent = 0,Qt::WindowFlags f =0);


private:
    QToolButton *toolBtn1_1;
    QToolButton *toolBtn1_2;
    QToolButton *toolBtn1_3;
    QToolButton *toolBtn1_4;
    QToolButton *toolBtn1_5;
    QToolButton *toolBtn2_1;
    QToolButton *toolBtn2_2;
    QToolButton *toolBtn3_1;
    QToolButton *toolBtn3_2;

};

#endif // QQ_H
