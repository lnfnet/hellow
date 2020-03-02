#include "mytask.h"

MyTask::MyTask()
{

}

void MyTask::run()
{
    //tiem consumer
    qDebug()<<"Task Strat";
    int iNumber =0;
    for(int i =0 ;i<100;i++)
    {
        iNumber +=1;
    }
    qDebug()<<"Task Done";
    emit Result(iNumber);

}
