#ifndef PRODUCTINFO_H
#define PRODUCTINFO_H

#include <QDialog>

namespace Ui {
class productInfo;
}

class productInfo : public QDialog
{
    Q_OBJECT

public:
    explicit productInfo(QWidget *parent = nullptr);
    ~productInfo();

private slots:
    void getImg(QString name);
    void on_pushButton_return_clicked();
    void on_pushButton_delete_clicked();

private:
    Ui::productInfo *ui;
    QString path = "";

signals:
    void deleteInfo(QString path);
};

#endif // PRODUCTINFO_H
