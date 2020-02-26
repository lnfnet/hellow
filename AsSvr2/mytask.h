#ifndef MYTASK_H
#define MYTASK_H

#include <QRunnable>
#include <QObject>
#include <QDebug>

class MyTask : public QObject,public QRunnable
{
    Q_OBJECT
public:
    MyTask();
    void run();
};

#endif // MYTASK_H
