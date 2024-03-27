#include "singletonclient.h"
#include <QCoreApplication>
#include <iostream>
#include <QString>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::string msg;
    std::cin >> msg;
    SingletonClient::getInstance()->
        send_msg_to_server(QString::fromStdString(msg));

    return a.exec();
}