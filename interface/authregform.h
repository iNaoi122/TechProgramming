#ifndef AUTHREGFORM_H
#define AUTHREGFORM_H

#include <QWidget>
//#include "functionsforclient.h"

namespace Ui {
class AuthRegForm;
}

class AuthRegForm : public QWidget
{
    Q_OBJECT

public:
    explicit AuthRegForm(QWidget *parent = nullptr);
    ~AuthRegForm();
    void clearFields();
    //FunctionsForClient* get_func();

signals:
    void is_auth(QString, QString);

private slots:
    void on_pushButtonAuth_clicked();
    void on_pushButtonChange_clicked();

private:
    Ui::AuthRegForm *ui;
  //FunctionsForClient func;
};

#endif // AUTHREGFORM_H
