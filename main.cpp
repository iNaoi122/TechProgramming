#include <QCoreApplication>
#include<QDebug>
#include<sha.h>



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString input = "slovo";
    QString output = SHA::get_hash(input);
    qDebug()<<output;
    return a.exec();
}
