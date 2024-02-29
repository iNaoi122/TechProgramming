#include "functionsforclient.h"

FunctionsForClient::FunctionsForClient() {
    ui_auth = new AuthRegForm;
    ui_auth->show();
    connect(ui_auth, &AuthRegForm::is_auth, this, &FunctionsForClient::is_auth);
}

void FunctionsForClient::is_auth(QString log, QString pass){
    if (log == "1" && pass == "1") {
        delete ui_auth;
        ui_main = new MainWindow;
        ui_main->show();
        //emit this->on_auth_ok();
    }
}
