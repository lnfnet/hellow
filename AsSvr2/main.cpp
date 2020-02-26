#include <QCoreApplication>
#include <myclient.h>
#include <myserver.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyServer server;
    server.StartServer();


    return a.exec();
}
