#include "mylabel.h"
#include "productinfo.h"

MyQLabel::MyQLabel(QWidget *parent)
    :QLabel(parent) {
     connect(this, SIGNAL(clicked()), this, SLOT(Clicked()));
}

MyQLabel::~MyQLabel() {

}

void MyQLabel::Clicked() {
    productInfo *info = new productInfo(parentWidget()->parentWidget()->parentWidget());
    info->setWindowTitle(this->objectName().mid(9));
    info->setWindowFlags(Qt::Dialog|Qt::WindowCloseButtonHint);
    connect(this,SIGNAL(emitImg(QString)),info,SLOT(getImg(QString)));
    emit emitImg(this->objectName());
    info->show();
}

void MyQLabel::mousePressEvent(QMouseEvent* event) {
    emit clicked();
}

