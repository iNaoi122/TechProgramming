#include "authregform.h"
#include "ui_authregform.h"

AuthRegForm::AuthRegForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AuthRegForm)
{
    ui->setupUi(this);
    ui->labelEmail->setVisible(false);
    ui->lineEditEmail->setVisible(false);
    ui->pushButtonRegistration->setVisible(false);
}

AuthRegForm::~AuthRegForm()
{
    delete ui;
}

void AuthRegForm::on_pushButtonAuth_clicked()
{
    emit is_auth(ui->lineEditLogin->text(), ui->lineEditPassword->text());
}


void AuthRegForm::on_pushButtonChange_clicked()
{
    bool flag = ui->labelEmail->isVisible();

    ui->labelEmail->setVisible(!flag);
    ui->lineEditEmail->setVisible(!flag);
    ui->pushButtonRegistration->setVisible(!flag);
    ui->pushButtonAuth->setVisible(flag);
    if (flag) {
        ui->pushButtonChange->setText("У меня нет аккаунта");
    } else {
        ui->pushButtonChange->setText("У меня есть аккаунт");
    }
}
/*
FunctionsForClient* AuthRegForm::get_func(){
    return &(this->func);
}*/
