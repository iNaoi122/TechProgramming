#include "mytcpserver.h"
#include <QDebug>
#include <QRegExp>

#include <QCoreApplication>
#include "server_logic.h"

MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent)
{
    mTcpServer = new QTcpServer(this);

    connect(mTcpServer, &QTcpServer::newConnection, this, &MyTcpServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 6000)){
        qDebug() << "server is not started";
    } else {
        qDebug() << "server is started";
    }
}

void MyTcpServer::slotNewConnection()
{
    mTcpSocket = mTcpServer->nextPendingConnection();

    mTcpSocket->write("Hello, World!!! I am echo server!\r\n");

    connect(mTcpSocket, &QTcpSocket::readyRead, this, &MyTcpServer::slotServerRead);
    connect(mTcpSocket, &QTcpSocket::disconnected, this, &MyTcpServer::slotClientDisconnected);
}

void MyTcpServer::slotServerRead()
{
    QString res = "";
    while(mTcpSocket->bytesAvailable()>0)
       {
           QByteArray array =mTcpSocket->readAll();
           //qDebug()<<array<<"\n";
           if(array=="\x01")
           {
               mTcpSocket->write(res.toUtf8());
               res = "";
           }
           else
               res.append(array);
       }
       mTcpSocket->write(res.toUtf8());
       ServerLogic logic;
       logic.requestAnalyzer(res.chopped(2));
}

void MyTcpServer::slotClientDisconnected()
{
    mTcpSocket->close();
}
