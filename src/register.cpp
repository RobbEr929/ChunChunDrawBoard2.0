#include "register.h"
#include "ui_register.h"

Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register) {
    ui->setupUi(this);
    ui->label_equal->hide();
}

Register::~Register() {
    delete ui;
}

void Register::showRegister() {
    this->show();
}

void Register::on_pushButton_cancel_clicked() {
    this->hide();
    ui->pushButton_emit->setEnabled(true);
    emit showLogin();
}


void Register::on_lineEdit_phone_cursorPositionChanged(int arg1, int arg2) {
    QRegExp rx("[0-9/]{11}");
    ui->lineEdit_phone->setValidator(new QRegExpValidator(rx, this));
}

void Register::on_lineEdit_pass_1_cursorPositionChanged(int arg1, int arg2) {
    QRegExp rx("[a-z A-Z 0-9 !?+*/]{6,16}");
    ui->lineEdit_phone->setValidator(new QRegExpValidator(rx, this));
}

void Register::on_lineEdit_pass_2_textChanged(const QString &arg1) {
    QString str1 = ui->lineEdit_pass_1->text();
    QString str2 = ui->lineEdit_pass_2->text();
    if(str1!=str2){
        ui->label_equal->show();
    }else if(str1==str2){
        ui->label_equal->hide();
    }
}

void Register::on_pushButton_emit_clicked() {
    ui->pushButton_emit->setEnabled(false);
    QString str1 = ui->lineEdit_pass_1->text();
    QString str2 = ui->lineEdit_pass_2->text();
    QString phone = ui->lineEdit_phone->text();
    if(str1 != str2 && (phone.isEmpty() || str1.isEmpty())) {
        QMessageBox::warning(NULL, "The input error", "The input error. Please verify and try again!");
        return;
    }
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    int codeInt = qrand()%8999 + 1000;   //随机生成4位随机数
    code = QString::number((codeInt));
//    qDebug()<<code<<endl;
    QUrl url("http://api.sms.cn/sms/");
    QUrlQuery urlQuery;
    urlQuery.addQueryItem("ac","send");
    urlQuery.addQueryItem("uid", "zhongchun929");
    urlQuery.addQueryItem("pwd", "4c46b8b9b66d7942d185370b1ba4b2d0");
    urlQuery.addQueryItem("template", "549058");
    urlQuery.addQueryItem("mobile", phone);
    urlQuery.addQueryItem("content", QString("{\"code\":\"%1\"}").arg(code));
    url.setQuery(urlQuery);
    QNetworkAccessManager *manager = new QNetworkAccessManager;
    manager->get(QNetworkRequest(url));
//    qDebug()<<data;
}

void Register::on_pushButton_ok_clicked() {
    QString phone = ui->lineEdit_phone->text();
    QString password = ui->lineEdit_pass_1->text();
    QString codeIn = ui->lineEdit_code->text();
    if(code == codeIn && !codeIn.isEmpty()){
        emit emitRegInfo(phone,password);
    }else {
        QMessageBox::warning(NULL, "The code error", "The code error. Please verify ,quit and try again!");
    }
}

void Register::hideRegister() {
    this->hide();
}

void Register::resendCode() {
    ui->pushButton_emit->setEnabled(true);
}

void Register::showForget() {
    this->show();
    this->ui->label_6->setText("重置密码");
}
