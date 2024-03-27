#include "singletonclient.h"

SingletonClient* SingletonClient::p_instance = nullptr;
SingletonDestroyer SingletonClient::destroyer;

SingletonClient::SingletonClient(QObject* parent) : QObject(parent)
{
    mTcpSocket = new QTcpSocket(this);
    mTcpSocket->connectToHost("127.0.0.1", 33333);

    connect(mTcpSocket, SIGNAL(readyRead()), this, SLOT(slotServerRead()));
}
SingletonClient::~SingletonClient()
{
    delete mTcpSocket;
}
SingletonClient* SingletonClient::getInstance()
{
    if (!p_instance)
    {
        p_instance = new SingletonClient();
        destroyer.initialize(p_instance);
    }
    return p_instance;
}
/*QString SingletonClient::querry_to_server(QString query)
{
    mTcpSocket->write(query.toUtf8());
    qDebug() << "Sent message from client to server: " << query;

    if (!mTcpSocket->waitForReadyRead()) {
        qDebug() << "Timeout while waiting for response from the server.";
        return "";
    }

    QByteArray response = mTcpSocket->readAll();
    QString msg = QString::fromUtf8(response);

    qDebug() << "Received message from server: " << msg;

    return msg;
}*/
QString SingletonClient::querry_to_server(QString query)//реализовать этот метод и удалить все, откуда я скопировал
{
    mTcpSocket->write(query.toUtf8());
    qDebug() << "Sent message from client to server: " << query;
//WAIT
    QString msg = "";
    while (mTcpSocket->bytesAvailable() > 0)
    {
        QByteArray array = mTcpSocket->readAll();
        msg.append(array);
    }
    qDebug() << msg;
    return msg;
}

void SingletonClient::send_msg_to_server(QString query)
{
    mTcpSocket->write(query.toUtf8());
    qDebug() << "Sent message from client to server: " << query;
}

void SingletonClient::slotServerRead()
{
    QString msg = "";
    while (mTcpSocket->bytesAvailable() > 0)
    {
        QByteArray array = mTcpSocket->readAll();
        msg.append(array);
    }
    qDebug() << msg;
    emit message_from_server(msg);
}
