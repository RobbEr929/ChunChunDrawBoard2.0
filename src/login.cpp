#include "login.h"
#include "ui_login.h"
Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login) {
    ui->setupUi(this);
}

Login::~Login() {
    delete ui;
}

void Login::on_pushButton_login_clicked() {
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
//    qDebug()<<username<<typeid (username).name()<<endl<<password<<typeid (password).name()<<endl;
    emit emituserdata(username,password);
}

void Login::loginHide() {
//    qDebug()<<"hide";
    this->hide();
}

void Login::on_pushButton_register_clicked() {
    this->hide();
    emit showRegister();
}

void Login::showLogin() {
    this->show();
}

void Login::on_pushButton_forget_clicked() {
    this->hide();
    emit showForget();
}
