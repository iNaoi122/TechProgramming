#include <QDebug>
#include<QCoreApplication>
#include <QTcpSocket>
#include "server_logic.h"
#include "des.h"

void ServerLogic::requestAnalyzer(QString request_string, QTcpSocket *socket)
{
    switch(requests[parse_request(request_string)])
    {
    case 1:
        qDebug()<<"login";
        socket->write(login(request_string).toUtf8());
        break;
    case 2:
        qDebug()<<"get_solution";
        solution(request_string);
        break;
    case 3:
        qDebug()<<"signup";
        socket->write(signup(request_string).toUtf8());
        break;
    case 4:
        qDebug()<<"logout";
        socket->write(logout(request_string).toUtf8());
        break;

    default:
        qDebug()<<"not found";

    }
}
QString ServerLogic::login(QString text)
{
    qDebug()<<parse_auth(text);
    return "Successful";
}

QString ServerLogic::logout(QString text)
{
    qDebug()<<parse_auth(text);
    return "Successful";
}

QString ServerLogic::signup(QString text)
{
    qDebug()<<parse_auth(text);
    return "Successful";
}

void ServerLogic::solution(QString text)
{

}

QStringList ServerLogic::parse_auth(QString request_params)
{
    QStringList list;
    int pos = 0;
    while ((pos = request_params.indexOf("=", pos)) != -1) {
        pos++;
        int endPos = request_params.indexOf("&", pos);
        if (endPos == -1) {
            endPos = request_params.length();
        }
        QString value = request_params.mid(pos, endPos - pos);
        list.append(value);
        pos = endPos;
    }
    return list;
}

QString ServerLogic::parse_request(QString request)
{
    QString request_route = request.split("?")[0];
    return request_route;
}
