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

//    qDebug()<<wait_request(mTcpSocket);

    if(false)
    {
        mTcpSocket->write("Not authorized!");
        mTcpSocket->disconnectFromHost();
    }
    else clients.append(mTcpSocket);

    connect(mTcpSocket, &QTcpSocket::readyRead, this, &MyTcpServer::slotServerRead);
    connect(mTcpSocket, &QTcpSocket::disconnected, this, &MyTcpServer::slotClientDisconnected);
}

void MyTcpServer::slotServerRead()
{
    QTcpSocket *mTcpSocket = qobject_cast<QTcpSocket*>(sender());
    if(!mTcpSocket) return;
    if(!clients.contains(mTcpSocket))
    {
        mTcpSocket->write("Not authorized!");
        mTcpSocket->disconnectFromHost();
    }
       QString res = wait_request(mTcpSocket);
       mTcpSocket->write(res.toUtf8());
       logic.requestAnalyzer(res.chopped(2), mTcpSocket);
}

void MyTcpServer::slotClientDisconnected()
{
    mTcpSocket->close();
    clients.removeOne(mTcpSocket);
}

QString MyTcpServer::wait_request(QTcpSocket *socket)
{
    QString res = "";

    while(mTcpSocket->bytesAvailable()>0)
       {
           QByteArray array =socket->readAll();
       if(array=="\x01")
         {
             socket->write("recieve");
          }
        else
           res.append(array);
       }
    return res;
}
