#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "alibabacloud/oss/OssClient.h"
#include "login.h"
#include "mylabel.h"

using namespace AlibabaCloud::OSS;

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	MainWindow::ui->widget_main->show();
	MainWindow::ui->widget_product->hide();
	MainWindow::ui->widget_about->hide();
	connect(MainWindow::ui->comboBox_width, SIGNAL(currentIndexChanged(int)), this, SLOT(currentIndex_comboBox_Width_Changed()));
	pix_One = QPixmap(700, 750);
	pix_One.fill(0xffffff);
	pix_Two = QPixmap(700, 750);
	pix_Two.fill(0xffffff);
	isDrawing = 0;
	Selected = 1;
	printColorNow();
}
void MainWindow::deleteImg()
{
	QDir dir;
	dir.setPath("D:/CCDB2.0/" + CurrentUsername);
	dir.removeRecursively();
}
void MainWindow::closeEvent(QCloseEvent* event)
{
	QMessageBox::StandardButton res = QMessageBox::warning(NULL, "Do you want to quit?", "Are you sure you want to exit", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
	switch ( res )
	{
	case QMessageBox::Yes:
		deleteImg();
		qApp->quit();
		break;
	case QMessageBox::No:
		//        qDebug()<<"NO";
		break;
	default:
		break;
	}
}

static int Width = 1;
static QColor Color(0, 0, 0, 255);

MainWindow::~MainWindow()
{
	delete ui;
}

bool MainWindow::createConnection()
{
	db = QSqlDatabase::addDatabase("QMYSQL");//选择数据库
	db.setHostName("47.95.214.101");
	db.setPort(3306);
	db.setDatabaseName("drawboard");
	db.setUserName("drawboard");
	db.setPassword("123456");
	db.open();
	if ( !db.open() )
	{
		qDebug("Failed to connect database");
		return false;
	}
	qDebug("Connection successful");
	return true;
}

void MainWindow::getuserdata(QString username, QString password)
{
	//    qDebug()<<"接收"<<username<<endl<<password<<endl;
	QSqlQuery query(db);
	query.prepare("select * from user where username = :name && password = :pass");
	query.bindValue(":name", username);
	query.bindValue(":pass", password);
	query.exec();
	int count = 0;
	while ( query.next() )
	{
		count++;
	}
	if ( count == 0 )
	{
		QMessageBox::warning(NULL, "Wrong account or password!", "Wrong account or password\n,please try again or register");
	}
	else
	{
		CurrentUsername = username;
		emit loginHide();
		this->show();
		QDir* mainFloder = new QDir;
		QDir* floder = new QDir;
		bool exist = mainFloder->exists("D:/CCDB2.0");
		if ( exist )
		{
			QString str = "D:/CCDB2.0/";
			str += CurrentUsername;
			bool res = floder->mkdir(str);
			if ( res )
				qDebug() << "mkdir_ok";
			else
				qDebug() << "dir_exist";
		}
		else
		{
			bool resMain = mainFloder->mkdir("D:/CCDB2.0");
			if ( resMain )
			{
				QString str = "D:/CCDB2.0/";
				str += CurrentUsername;
				bool res = floder->mkdir(str);
				if ( res )
					qDebug() << "mkdir_ok";
				else
					qDebug() << "dir_exist";
			}
		}
	}
}

void MainWindow::getRegInfo(QString phone, QString password)
{
	QSqlQuery query(db);
	query.prepare("select * from user where username = :phone");
	query.bindValue(":phone", phone);
	query.exec();
	int count = 0;
	while ( query.next() )
	{
		count++;
	}
	if ( count == 0 )
	{
		QString str = QString("insert into user(username,password) values(%1,%2)").arg(phone, password);
		if ( query.exec(str) )
		{
			QMessageBox::information(NULL, "Register success!", "Register success\n,click yes to return");
			emit hideRegister();
			emit showLogin();
		}
	}
	else
	{
		QString str = QString("update `user` set `password`='" + password + "' where `username`=" + phone);
		if ( query.exec(str) )
		{
			QMessageBox::information(NULL, "Change success!", "Change success\n,click yes to return");
			emit hideRegister();
			emit showLogin();
		}
		emit resendCode();
	}
}

void MainWindow::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	if ( Selected == 1 )
	{
		QPainter painter_2(&pix_One);
		mypen.setColor(Color);
		mypen.setWidth(Width);
		painter_2.setPen(mypen);
		if ( isDrawing >= 2 )
			painter_2.drawLine(Begin_point, End_point);
		Begin_point = End_point;
		pix_Two = pix_One;
	}
	else if ( Selected < 5 )
	{
		if ( isDrawing >= 2 )
		{
			pix_One = pix_Two;
			QRect obj(Begin_point, End_point);
			QPainter painter_2(&pix_One);
			mypen.setColor(Color);
			mypen.setWidth(Width);
			painter_2.setPen(mypen);
			if ( Selected == 2 )
				painter_2.drawLine(Begin_point, End_point);
			else if ( Selected == 3 )
				painter_2.drawEllipse(obj);
			else if ( Selected == 4 )
				painter_2.drawRect(obj);
		}
		if ( isDrawing == 3 )
		{
			isDrawing = 0;
			pix_Two = pix_One;
		}
	}
	painter.drawPixmap(0, 0, pix_One);
}

void MainWindow::mousePressEvent(QMouseEvent* event)
{
	if ( event->button() == Qt::LeftButton )
	{
		Now_point = event->pos();
		int x = Now_point.x();
		if ( x > 700 )
			return;
		Begin_point = Now_point;
		isDrawing = 1;
	}
}

void MainWindow::mouseMoveEvent(QMouseEvent* event)
{
	if ( isDrawing == 0 )
		return;
	if ( event->buttons() & Qt::LeftButton )
	{
		Now_point = event->pos();
		int x = Now_point.x();
		if ( x > 700 )
			return;
		End_point = Now_point;
		isDrawing = 2;
		update();
	}
}

void MainWindow::mouseReleaseEvent(QMouseEvent* event)
{
	if ( event->button() == Qt::LeftButton )
	{
		Now_point = event->pos();
		int x = Now_point.x();
		if ( x > 700 )
			return;
		End_point = Now_point;
		isDrawing = 3;
		update();
	}
}

void MainWindow::on_pushButton_pen_clicked()
{
	Selected = 1;
	update();
}

void MainWindow::on_pushButton_line_clicked()
{
	Selected = 2;
	update();
}

void MainWindow::on_pushButton_circle_clicked()
{
	Selected = 3;
	update();
}

void MainWindow::on_pushButton_rectangle_clicked()
{
	Selected = 4;
	update();
}

void MainWindow::on_pushButton_red_clicked()
{
	Color.setRgb(255, 0, 0, 255);
	printColorNow();
	update();
}

void MainWindow::on_pushButton_yellow_clicked()
{
	Color.setRgb(255, 255, 0, 255);
	printColorNow();
	update();
}

void MainWindow::on_pushButton_green_clicked()
{
	Color.setRgb(0, 255, 0, 255);
	printColorNow();
	update();
}

void MainWindow::on_pushButton_blue_clicked()
{
	Color.setRgb(0, 0, 255, 255);
	printColorNow();
	update();
}

void MainWindow::on_pushButton_cyan_clicked()
{
	Color.setRgb(0, 255, 255, 255);
	printColorNow();
	update();
}

void MainWindow::on_pushButton_purple_clicked()
{
	Color.setRgb(128, 0, 128, 255);
	printColorNow();
	update();
}

void MainWindow::on_pushButton_black_clicked()
{
	Color.setRgb(0, 0, 0, 255);
	printColorNow();
	update();
}

void MainWindow::on_pushButton_white_clicked()
{
	Color.setRgb(255, 255, 255, 255);
	printColorNow();
	update();
}

void MainWindow::on_pushButton_colorMore_clicked()
{
	Color = QColorDialog::getColor();
	printColorNow();
	update();
}

void MainWindow::on_pushButton_save_clicked()
{
	qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
	int codeInt = qrand() % 1000000007;
	QString integer = QString::number(( codeInt ));
	QString path("D:/");
	QString str = "Picture";
	str += integer;
	str += ".jpg";
	path += str;
	QSize picSize(650, 750);
	QPixmap ret = pix_One.scaled(picSize);
	ret.save(path);
	QMessageBox::StandardButton res = QMessageBox::information(NULL, "File has been saved on D:", "File has been saved on D:\n,Do you want to upload to the cloud?", QMessageBox::Yes | QMessageBox::No);
	switch ( res )
	{
	case QMessageBox::Yes:
		break;;
	case QMessageBox::No:
		return;
	default:
		return;
	}
	InitializeSdk();
	ClientConfiguration conf;
	OssClient client(Endpoint, AccessKeyId, AccessKeySecret, conf);
	std::string localPath = path.toStdString();
	ObjectName = "";
	ObjectName += str.toStdString();
	//    std::cout<<"localPath"<<localPath<<std::endl<<"ObjectName"<<ObjectName<<std::endl;
	std::shared_ptr<std::iostream> content = std::make_shared<std::fstream>(localPath, std::ios::in | std::ios::binary);
	PutObjectRequest request(BucketName, ObjectName, content);
	auto outcome = client.PutObject(request);
	QSqlQuery query(db);
	QString pathCloud = QString::fromStdString(ObjectName);
	//    qDebug()<<CurrentUsername<<" "<<pathCloud<<endl;
	QString strr = QString("insert into draw(username,path) values('%1','%2')").arg(CurrentUsername, pathCloud);
	bool ress = query.exec(strr);
	if ( outcome.isSuccess() && ress )
	{
		QMessageBox::information(NULL, "File has been saved to the cloud ", "File has been saved to the cloud!", QMessageBox::Yes);
	}
	ShutdownSdk();
}

void MainWindow::on_pushButton_clear_clicked()
{
	QPixmap new_pixmap;
	new_pixmap = QPixmap(pix_One.size());
	new_pixmap.fill(0xffffff);
	pix_One = new_pixmap;
	pix_Two = new_pixmap;
	Begin_point.setX(-1);
	Begin_point.setY(-1);
	End_point.setX(-1);
	End_point.setY(-1);
	update();
}

void MainWindow::currentIndex_comboBox_Width_Changed()
{
	Width = MainWindow::ui->comboBox_width->currentText().toInt();
}

void MainWindow::on_pushButton_about_clicked()
{
	QProcess::startDetached("explorer http://47.95.214.101/");
}

void MainWindow::printColorNow()
{
	QPalette Palette = ui->label_color->palette();
	Palette.setColor(QPalette::Background, Color);
	ui->label_color->setAutoFillBackground(true);
	ui->label_color->setPalette(Palette);
}

void MainWindow::on_pushButton_main_clicked()
{
	MainWindow::ui->widget_main->show();
	MainWindow::ui->widget_product->hide();
	MainWindow::ui->widget_about->hide();
}

void MainWindow::on_pushButton_product_clicked()
{
	MainWindow::ui->widget_main->hide();
	MainWindow::ui->widget_product->show();
	MainWindow::ui->widget_about->hide();
	QPalette pal(MainWindow::ui->widget_product->palette());
	pal.setColor(QPalette::Background, Qt::white);
	MainWindow::ui->widget_product->setAutoFillBackground(true);
	MainWindow::ui->widget_product->setPalette(pal);
	QSqlQuery query;
	//    qDebug()<<"YES"<<endl;
	query.prepare("select * from draw where username = " + CurrentUsername);
	query.exec();
	InitializeSdk();
	ClientConfiguration conf;
	OssClient client(Endpoint, AccessKeyId, AccessKeySecret, conf);
	while ( query.next() )
	{
		ObjectName = query.value(2).toString().toStdString();
		std::string path = "D:/CCDB2.0/";
		path += CurrentUsername.toStdString();
		path += "/";
		path += ObjectName;
		GetObjectRequest request(BucketName, ObjectName);
		request.setResponseStreamFactory([=](){return std::make_shared<std::fstream>(path, std::ios_base::out | std::ios_base::in | std::ios_base::trunc | std::ios_base::binary); });
		//        std::cout<<"path:"<<path<<std::endl;
		auto outcome = client.GetObject(request);
	}
	ShutdownSdk();
	QString imgPath = "D:/CCDB2.0/";
	imgPath += CurrentUsername;
	QDir dir;
	dir.setPath(imgPath);
	dir.setNameFilters(QStringList("*.jpg"));
	int imgCount = dir.count();
	int xStep = 0;
	int yStep = 0;
	while ( imgCount-- )
	{
		xStep++;
		QString imgName = imgPath + "/" + dir[xStep + yStep * 6 - 1];
		//         qDebug()<<imgName<<endl;
		QImage img;
		img.load(imgName);
		MyQLabel* lab = new MyQLabel(MainWindow::ui->widget_product);
		lab->setPixmap(QPixmap::fromImage(img).scaled(140, 150, Qt::KeepAspectRatio, Qt::SmoothTransformation));
		lab->move(( xStep - 1 ) * 140, yStep * 150);
		lab->setStyleSheet("border:1px solid black");
		lab->setObjectName("label_" + imgName.mid(10));
		qDebug() << lab->objectName() << endl;
		lab->show();
		if ( xStep == 6 )
			xStep = 0, ++yStep;
	}
}

void MainWindow::deleteInfo(QString path)
{
	QSqlQuery query(db);
	QFile file(path);
	file.remove();
	InitializeSdk();
	ClientConfiguration conf;
	OssClient client(Endpoint, AccessKeyId, AccessKeySecret, conf);
	ObjectName = path.mid(13).toStdString();
	//    std::cout<<ObjectName<<std::endl;
	DeleteObjectRequest request(BucketName, ObjectName);
	auto outcome = client.DeleteObject(request);
	if ( outcome.isSuccess() )
	{
		QString strUser = path.mid(11, 1);
		QString strPath = path.mid(13);
		query.prepare("delete from draw where draw.username = " + strUser + " && draw.path = '" + strPath + "'");
		bool res = query.exec();
		if ( res )
		{
			QList<MyQLabel*> labs = MainWindow::ui->widget_product->findChildren<MyQLabel*>();
			foreach(MyQLabel * lab, labs)
				delete lab;
			QMessageBox::information(NULL, "Delete success", "Delete success\n Press OK to return");
		}
		else
		{
			QMessageBox::information(NULL, "Delete failed", "Delete failed\n Please try later");
		}
		on_pushButton_product_clicked();
	}
}

void MainWindow::on_pushButton_change_clicked()
{
	MainWindow::ui->lineEdit_change->show();
	MainWindow::ui->label_change->show();
	MainWindow::ui->pushButton_yes->show();
	MainWindow::ui->pushButton_no->show();
}

void MainWindow::on_pushButton_personal_clicked()
{
	MainWindow::ui->widget_main->hide();
	MainWindow::ui->widget_product->hide();
	MainWindow::ui->widget_about->show();
	QPalette pal(MainWindow::ui->widget_about->palette());
	pal.setColor(QPalette::Background, Qt::white);
	MainWindow::ui->widget_about->setAutoFillBackground(true);
	MainWindow::ui->widget_about->setPalette(pal);
	MainWindow::ui->label_username->setText(CurrentUsername);
	MainWindow::ui->label_change->hide();
	MainWindow::ui->lineEdit_change->hide();
	MainWindow::ui->pushButton_yes->hide();
	MainWindow::ui->pushButton_no->hide();
}

void MainWindow::on_pushButton_yes_clicked()
{
	QString pass = MainWindow::ui->lineEdit_change->text();
	QSqlQuery query(db);
	query.prepare("update `user` set `password`='" + pass + "' where `username`=" + CurrentUsername);
	if ( query.exec() )
	{
		QMessageBox::information(NULL, "Update success", "Update success");
		MainWindow::ui->label_change->hide();
		MainWindow::ui->lineEdit_change->hide();
		MainWindow::ui->lineEdit_change->setText("");
		MainWindow::ui->pushButton_yes->hide();
		MainWindow::ui->pushButton_no->hide();
	}
	else
	{
		QMessageBox::information(NULL, "Update failed", "Update failed\n please try later");
	}
}

void MainWindow::on_pushButton_no_clicked()
{
	MainWindow::ui->label_change->hide();
	MainWindow::ui->lineEdit_change->hide();
	MainWindow::ui->lineEdit_change->setText("");
	MainWindow::ui->pushButton_yes->hide();
	MainWindow::ui->pushButton_no->hide();
}