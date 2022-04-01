#include "mainwindow.h"
#include "login.h"
#include "register.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    Login l;
    Register r;
    l.setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);
    r.setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);
    w.createConnection();
    QObject::connect(&l,SIGNAL(emituserdata(QString,QString)),&w,SLOT(getuserdata(QString,QString)));
    QObject::connect(&w,SIGNAL(loginHide()),&l,SLOT(loginHide()));
    QObject::connect(&l,SIGNAL(showRegister()),&r,SLOT(showRegister()));
    QObject::connect(&r,SIGNAL(showLogin()),&l,SLOT(showLogin()));
    QObject::connect(&l,SIGNAL(showForget()),&r,SLOT(showForget()));
    QObject::connect(&r,SIGNAL(emitRegInfo(QString,QString)),&w,SLOT(getRegInfo(QString,QString)));
    QObject::connect(&w,SIGNAL(hideRegister()),&r,SLOT(hideRegister()));
    QObject::connect(&w,SIGNAL(showLogin()),&l,SLOT(showLogin()));
    QObject::connect(&w,SIGNAL(resendCode()),&r,SLOT(resendCode()));
    l.show();
    return a.exec();
}
