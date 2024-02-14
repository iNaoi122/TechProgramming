#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include "server_logic.h"
class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = 0);
     ServerLogic logic;

public slots:
    void slotNewConnection();
    void slotServerRead();
    void slotClientDisconnected();

private:
    QList<QTcpSocket*> clients;
    QTcpServer * mTcpServer;
    QTcpSocket * mTcpSocket;
    QString wait_request(QTcpSocket *socket);

};


#endif // MYTCPSERVER_H
