#ifndef GUITEST_H
#define GUITEST_H

#include <QWidget>

class guiTest : public QWidget
{
    Q_OBJECT
public:
    explicit guiTest(QWidget *parent = 0);

signals:

public slots:
   void slottimedone();
};

#endif // GUITEST_H
