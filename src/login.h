#ifndef LOGIN_H
#define LOGIN_H
#include <QDialog>
#include <QDebug>
#include <QDataStream>

namespace Ui {
class Login;
}

class Login : public QDialog {
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_pushButton_login_clicked();
    void loginHide();//隐藏登陆界面
    void on_pushButton_register_clicked();
    void showLogin();//显示登录界面
    void on_pushButton_forget_clicked();

signals:
    void emituserdata(QString username,QString password);//将获取到的用户信息传输验证
    void showRegister();//显示注册界面
    void showForget();//显示忘记密码界面

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
