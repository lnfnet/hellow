#include <QCoreApplication>
#include <QDebug>
#include <QList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<int> list;
    for(int j=0;j<10;j++)
    {
        list.insert(list.end(),j);
    }
    QList<int>::iterator i;
    for(i=list.begin();i!=list.end();++i)
    {
        qDebug()<<(*i);
        *i=(*i)*10;
    }
    QList<int>::const_iterator ci;
    for(ci=list.constBegin();ci!=list.constEnd();++ci)
    {
        qDebug()<<*ci;
    }

    return a.exec();
}
