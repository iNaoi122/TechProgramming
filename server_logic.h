#ifndef SERVER_LOGIC_H
#define SERVER_LOGIC_H

#include <QObject>
#include <QTcpSocket>


class ServerLogic: public QObject
{
    Q_OBJECT
public:
    void requestAnalyzer(QString request_string, QTcpSocket *socket);
    ServerLogic()
    {
        requests["login"] = 1;
        requests["get_solution"] = 2;
        requests["signup"] = 3;
        requests["logout"] = 4;
    }

private:
    std::map<QString, unsigned> requests;
    QString login(QString);
    QString logout(QString);
    QString signup(QString);
    void solution(QString);
    QStringList parse_auth(QString);
    QString parse_request(QString);


};

#endif // SERVER_LOGIC_H

