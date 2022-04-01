#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include <QIntValidator>
#include <QMessageBox>
#include <QTime>
#include <QtGlobal>
#include <QUrlQuery>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QSslError>

namespace Ui {
class Register;

}

class Register : public QDialog {
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

private slots:
    void showRegister();
    void on_pushButton_cancel_clicked();
    void on_lineEdit_phone_cursorPositionChanged(int arg1, int arg2);//手机号正则
    void on_lineEdit_pass_1_cursorPositionChanged(int arg1, int arg2);//密码正则
    void on_lineEdit_pass_2_textChanged(const QString &arg1);//重复密码
    void on_pushButton_emit_clicked();
    void on_pushButton_ok_clicked();
    void hideRegister();
    void resendCode();//启用发送验证码按钮
    void showForget();

signals:
    void showLogin();//显示登录界面
    void emitRegInfo(QString phone,QString password);//将注册信息传递

private:
    Ui::Register *ui;
    QString content = "";
    QString code = "";
    QNetworkAccessManager manager;
    QString _time;
    QString _random;
    QString _type;


};

#endif // REGISTER_H
