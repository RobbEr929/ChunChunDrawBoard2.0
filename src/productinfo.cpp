#include "productinfo.h"
#include "ui_productinfo.h"
#include "mainwindow.h"

productInfo::productInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::productInfo) {
    ui->setupUi(this);
}

productInfo::~productInfo() {
    delete ui;
}

void productInfo::getImg(QString name) {
    path = "D:/CCDB2.0";
    path += name.mid(6);
    QImage img;
    img.load(path);
    this->ui->label->setPixmap(QPixmap::fromImage(img).scaled(280,300,Qt::KeepAspectRatio,Qt::SmoothTransformation));
}

void productInfo::on_pushButton_return_clicked() {
    this->hide();
}

void productInfo::on_pushButton_delete_clicked() {
    connect(this,SIGNAL(deleteInfo(QString)),parentWidget(),SLOT(deleteInfo(QString)));
    emit deleteInfo(path);
    this->hide();
}
