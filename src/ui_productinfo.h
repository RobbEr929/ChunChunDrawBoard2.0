/********************************************************************************
** Form generated from reading UI file 'productinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCTINFO_H
#define UI_PRODUCTINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_productInfo
{
public:
    QPushButton *pushButton_return;
    QPushButton *pushButton_delete;
    QLabel *label;

    void setupUi(QDialog *productInfo)
    {
        if (productInfo->objectName().isEmpty())
            productInfo->setObjectName(QString::fromUtf8("productInfo"));
        productInfo->resize(450, 500);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(productInfo->sizePolicy().hasHeightForWidth());
        productInfo->setSizePolicy(sizePolicy);
        productInfo->setMinimumSize(QSize(450, 500));
        productInfo->setMaximumSize(QSize(450, 500));
        pushButton_return = new QPushButton(productInfo);
        pushButton_return->setObjectName(QString::fromUtf8("pushButton_return"));
        pushButton_return->setGeometry(QRect(80, 397, 93, 51));
        pushButton_delete = new QPushButton(productInfo);
        pushButton_delete->setObjectName(QString::fromUtf8("pushButton_delete"));
        pushButton_delete->setGeometry(QRect(280, 397, 93, 51));
        label = new QLabel(productInfo);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(85, 40, 280, 300));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        retranslateUi(productInfo);

        QMetaObject::connectSlotsByName(productInfo);
    } // setupUi

    void retranslateUi(QDialog *productInfo)
    {
        productInfo->setWindowTitle(QApplication::translate("productInfo", "Dialog", nullptr));
        pushButton_return->setText(QApplication::translate("productInfo", "\350\277\224\345\233\236", nullptr));
        pushButton_delete->setText(QApplication::translate("productInfo", "\345\210\240\351\231\244", nullptr));
        label->setText(QApplication::translate("productInfo", "Picture could not be loaded", nullptr));
    } // retranslateUi

};

namespace Ui {
    class productInfo: public Ui_productInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTINFO_H
