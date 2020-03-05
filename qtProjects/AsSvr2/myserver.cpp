    #include "myserver.h"

MyServer::MyServer(QObject *parent) : QTcpServer(parent)
{

}
void MyServer::StartServer()
{
    if(listen(QHostAddress::Any,12356))
    {
        qDebug()<<"server was started at 12356 socket port";
    }
    else
    {
        qDebug()<<"server was not started at 12356 socket port";

    }
}


void MyServer::incomingConnection(int handle)
{

    MyClient *client = new MyClient(this);
    client->SetSocket(handle);

}
