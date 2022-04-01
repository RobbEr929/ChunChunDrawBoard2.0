#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QDataStream>
#include <QMessageBox>
#include <QPixmap>
#include <QColorDialog>
#include <QMouseEvent>
#include <QActionGroup>
#include <QPainter>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QHttpPart>
#include <QHttpMultiPart>
#include <QProcess>
#include <QDir>
#include <fstream>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool createConnection();//连接数据库

private slots:
    void deleteImg();//删除本地缓存文件
    void getuserdata(QString username,QString password);//获取登录信息
    void getRegInfo(QString phone,QString password);//获取注册信息
    void on_pushButton_pen_clicked();
    void on_pushButton_line_clicked();
    void on_pushButton_circle_clicked();
    void on_pushButton_rectangle_clicked();
    void on_pushButton_red_clicked();
    void on_pushButton_yellow_clicked();
    void on_pushButton_green_clicked();
    void on_pushButton_blue_clicked();
    void on_pushButton_cyan_clicked();
    void on_pushButton_purple_clicked();
    void on_pushButton_black_clicked();
    void on_pushButton_white_clicked();
    void on_pushButton_save_clicked();
    void on_pushButton_clear_clicked();
    void currentIndex_comboBox_Width_Changed();
    void on_pushButton_about_clicked();
    void on_pushButton_colorMore_clicked();
    void on_pushButton_product_clicked();
    void on_pushButton_main_clicked();
    void deleteInfo(QString path);//删除指定图片
    void on_pushButton_change_clicked();

    void on_pushButton_personal_clicked();

    void on_pushButton_yes_clicked();

    void on_pushButton_no_clicked();

signals:
    void loginHide();//隐藏登陆界面
    void hideRegister();//隐藏注册界面
    void showLogin();//显示登录界面
    void resendCode();//启用发送验证码按钮

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QPen mypen;
    std::string AccessKeyId = "";
    std::string AccessKeySecret = "";
    std::string Endpoint = "";
    std::string BucketName = "";
    std::string ObjectName = "";
    QString CurrentUsername = "";
    QString DownloadUrl = "";


protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void paintEvent(QPaintEvent* event);
    void printColorNow();
    void closeEvent(QCloseEvent *event);
    QPixmap pix_One, pix_Two;
    int isDrawing;
    int Selected;
    QPoint Now_point, Begin_point, End_point;

};
#endif // MAINWINDOW_H
