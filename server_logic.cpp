#include "server_logic.h"
#include <QDebug>
#include<QCoreApplication>

void ServerLogic::requestAnalyzer(QString request_string)
{
    switch(requests[request_string])
    {
    case 1:
        qDebug()<<"auth";
        break;
    case 2:
        qDebug()<<"get";
        break;
    default:
        qDebug()<<"not found";
    }
}
