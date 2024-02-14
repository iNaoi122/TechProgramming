#ifndef SERVER_LOGIC_H
#define SERVER_LOGIC_H

#include <QObject>

class ServerLogic: public QObject
{
    Q_OBJECT
public:
    void requestAnalyzer(QString request_string);
    ServerLogic()
    {
        requests["auth"] = 1;
        requests["get"] = 2;
    }

private:
    std::map<QString, unsigned> requests;
};

#endif // SERVER_LOGIC_H

