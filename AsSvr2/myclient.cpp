#include "myclient.h"

MyClient::MyClient(QObject *parent) : QObject(parent)
{

}

void MyClient::SetSocket(int Descriptor)
{
    socket = new QTcpSocket(this);
    connect(socket,SIGNAL(connected()),this,SLOT(connected()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()));
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()));
    socket ->setSocketDescriptor(Descriptor);
    qDebug()<<"client connected";

}

void MyClient::connected()
{
     qDebug()<<"client connected event";
}

void MyClient::disconnected()
{
     qDebug()<<"client disconnected event";
}

void MyClient::readyRead()
{
    qDebug()<<socket->readAll();
    //Time Consumer - deadlock

}
void MyClient::TaskResult(int Number)
{

}
