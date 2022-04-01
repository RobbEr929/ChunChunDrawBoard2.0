/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QLineEdit *lineEdit_phone;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_pass_1;
    QLabel *label_3;
    QLineEdit *lineEdit_pass_2;
    QPushButton *pushButton_emit;
    QLabel *label_4;
    QLineEdit *lineEdit_code;
    QPushButton *pushButton_ok;
    QPushButton *pushButton_cancel;
    QLabel *label_equal;
    QLabel *label_6;

    void setupUi(QDialog *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QString::fromUtf8("Register"));
        Register->resize(400, 300);
        lineEdit_phone = new QLineEdit(Register);
        lineEdit_phone->setObjectName(QString::fromUtf8("lineEdit_phone"));
        lineEdit_phone->setGeometry(QRect(130, 90, 131, 21));
        label = new QLabel(Register);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 90, 91, 16));
        label_2 = new QLabel(Register);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 130, 81, 16));
        lineEdit_pass_1 = new QLineEdit(Register);
        lineEdit_pass_1->setObjectName(QString::fromUtf8("lineEdit_pass_1"));
        lineEdit_pass_1->setGeometry(QRect(130, 130, 131, 21));
        label_3 = new QLabel(Register);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 170, 111, 16));
        lineEdit_pass_2 = new QLineEdit(Register);
        lineEdit_pass_2->setObjectName(QString::fromUtf8("lineEdit_pass_2"));
        lineEdit_pass_2->setGeometry(QRect(130, 170, 131, 21));
        pushButton_emit = new QPushButton(Register);
        pushButton_emit->setObjectName(QString::fromUtf8("pushButton_emit"));
        pushButton_emit->setGeometry(QRect(280, 90, 111, 61));
        label_4 = new QLabel(Register);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 210, 81, 16));
        lineEdit_code = new QLineEdit(Register);
        lineEdit_code->setObjectName(QString::fromUtf8("lineEdit_code"));
        lineEdit_code->setGeometry(QRect(130, 210, 131, 21));
        pushButton_ok = new QPushButton(Register);
        pushButton_ok->setObjectName(QString::fromUtf8("pushButton_ok"));
        pushButton_ok->setGeometry(QRect(40, 250, 93, 28));
        pushButton_cancel = new QPushButton(Register);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(170, 250, 93, 28));
        label_equal = new QLabel(Register);
        label_equal->setObjectName(QString::fromUtf8("label_equal"));
        label_equal->setGeometry(QRect(290, 170, 81, 51));
        label_6 = new QLabel(Register);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(150, 30, 111, 31));
        label_6->setLayoutDirection(Qt::RightToLeft);

        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QDialog *Register)
    {
        Register->setWindowTitle(QApplication::translate("Register", "\346\263\250\345\206\214-\346\267\263\346\267\263\347\224\273\346\235\2772.0", nullptr));
        lineEdit_phone->setPlaceholderText(QApplication::translate("Register", "\350\276\223\345\205\24511\344\275\215\346\211\213\346\234\272\345\217\267", nullptr));
        label->setText(QApplication::translate("Register", "\350\257\267\350\276\223\345\205\245\346\211\213\346\234\272\345\217\267", nullptr));
        label_2->setText(QApplication::translate("Register", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        lineEdit_pass_1->setPlaceholderText(QApplication::translate("Register", "\350\276\223\345\205\2456-16\344\275\215\345\257\206\347\240\201", nullptr));
        label_3->setText(QApplication::translate("Register", "\350\257\267\345\206\215\346\254\241\350\276\223\345\205\245", nullptr));
        lineEdit_pass_2->setPlaceholderText(QApplication::translate("Register", "\345\206\215\346\254\241\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        pushButton_emit->setText(QApplication::translate("Register", "\345\217\221\351\200\201\347\237\255\344\277\241\351\252\214\350\257\201\347\240\201", nullptr));
        label_4->setText(QApplication::translate("Register", "\350\276\223\345\205\245\351\252\214\350\257\201\347\240\201", nullptr));
        pushButton_ok->setText(QApplication::translate("Register", "\347\241\256\350\256\244", nullptr));
        pushButton_cancel->setText(QApplication::translate("Register", "\345\217\226\346\266\210", nullptr));
        label_equal->setText(QApplication::translate("Register", "<html><head/><body><p><span style=\" color:#ff0000;\">\344\270\244\346\254\241\350\276\223\345\205\245\347\232\204</span></p><p><span style=\" color:#ff0000;\">\345\257\206\347\240\201\344\270\215\344\270\200\350\207\264</span></p></body></html>", nullptr));
        label_6->setText(QApplication::translate("Register", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\346\263\250\345\206\214\350\264\246\345\217\267</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
