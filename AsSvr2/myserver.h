#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>
#include "myclient.h"

class MyServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit MyServer(QObject *parent = 0);
    void StartServer();

signals:

public slots:
protected :
    void incomingConnection(int handle);

};

#endif // MYSERVER_H
