#include "ControlUI.h"
#include<QMessageBox>
#include<WinSock2.h>
#include<Windows.h>
#include<QSettings>
ControlUI::ControlUI(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::WindowCloseButtonHint | Qt::FramelessWindowHint);
	ui.CloseBtn->setToolTipName(QString::fromLocal8Bit("关闭"));
	ui.MinBtn->setToolTipName(QString::fromLocal8Bit("最小化"));
	connect(ui.MinBtn, SIGNAL(clicked()), this, SLOT(slot_minWindow()));
	connect(ui.CloseBtn, SIGNAL(clicked()), this, SLOT(close()));
	cmmIndex = 0;
	//读取ini文件设置
	QString path = QCoreApplication::applicationDirPath() + "//STYW.ini";
	//打开INI文件
	QSettings configIniRead(path, QSettings::IniFormat);
	//终端命令个数
	float Height = configIniRead.value("ATTRIBUTE/HEIGHT").toDouble();
	ui.lineEdit_HOFFSET->setText(QString::number(Height));
}

ControlUI::~ControlUI()
{
}

void ControlUI::closeEvent(QCloseEvent *event)
{
	QWidget::close();
	*isActive = false;
	delete this;
}
void ControlUI::slot_minWindow()
{
	this->showMinimized();
}

void ControlUI::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton) {
		m_Drag = true;
		m_DragPosition = event->globalPos() - this->pos();
		event->accept();
	}
}

void ControlUI::mouseMoveEvent(QMouseEvent *event)
{
	if (m_Drag && (event->buttons() && Qt::LeftButton)) {
		move(event->globalPos() - m_DragPosition);
		event->accept();
	}
}

void ControlUI::mouseReleaseEvent(QMouseEvent *event)
{
	m_Drag = false;
}

void ControlUI::on_RDNOBtn_clicked()
{
	cmmIndex = 1701;
	//读取ID
	QString Comm = "ID\r\n";
	QByteArray ba = Comm.toLatin1();
	LPCSTR ch = ba.data();
	int len = Comm.length();
	::send(Socket, ch, len, 0);
}

void ControlUI::on_WNOBtn_clicked()
{
	cmmIndex = 1702;
	//设置ID
	QString Comm = "ID " + ui.lineEdit_DNO->text().trimmed() + "\r\n";
	QByteArray ba = Comm.toLatin1();
	LPCSTR ch = ba.data();
	int len = Comm.length();
	::send(Socket, ch, len, 0);
}

void ControlUI::on_RTimeBtn_clicked()
{
	cmmIndex = 1703;
	//读取时钟
	QString Comm = "DATETIME\r\n";
	QByteArray ba = Comm.toLatin1();
	LPCSTR ch = ba.data();
	int len = Comm.length();
	::send(Socket, ch, len, 0);
}

void ControlUI::on_WTimeBtn_clicked()
{
	cmmIndex = 1704;
	//设置时钟
	QString Time;
	Time = ui.RdateTimeEdit->dateTime().toString("yyyy-MM-dd HH:mm:ss");
	QString Comm = "DATETIME " + Time + "\r\n";
	QByteArray ba = Comm.toLatin1();
	LPCSTR ch = ba.data();
	int len = Comm.length();
	::send(Socket, ch, len, 0);
}

//远程升级
void ControlUI::on_WCAPINTERVALBtn_clicked()
{
	cmmIndex = 1705;
	//远程升级
	QString Comm = "UPDATE\r\n";
	QByteArray ba = Comm.toLatin1();
	LPCSTR ch = ba.data();
	int len = Comm.length();
	::send(Socket, ch, len, 0);
}

void ControlUI::on_RESETBtn_clicked()
{
	cmmIndex = 1706;
	//重启采集器
	QString Comm = "RESET\r\n";
	QByteArray ba = Comm.toLatin1();
	LPCSTR ch = ba.data();
	int len = Comm.length();
	::send(Socket, ch, len, 0);
}

void ControlUI::on_WSNAPSHOTBtn_clicked()
{
	cmmIndex = 1707;
	//读取实时数据
	QString Comm = "SNAPSHOT\r\n";
	QByteArray ba = Comm.toLatin1();
	LPCSTR ch = ba.data();
	int len = Comm.length();
	::send(Socket, ch, len, 0);
}

//补抄数据
void ControlUI::on_DownBtn_clicked()
{
	cmmIndex = 1708;
	//补抄数据
	QString Time_B, Time_E;
	Time_B = ui.BdateTimeEdit->dateTime().toString("yyyy-MM-dd HH:mm");
	Time_E = ui.EdateTimeEdit->dateTime().toString("yyyy-MM-dd HH:mm");
	QString Comm = "DMTD " + Time_B + " " + Time_E + "\r\n";
	QByteArray ba = Comm.toLatin1();
	LPCSTR ch = ba.data();
	int len = Comm.length();
	::send(Socket, ch, len, 0);
}

//偏移量
void ControlUI::on_WHOFFSETBtn_clicked()
{
	*pHeight = (ui.lineEdit_HOFFSET->text().toDouble())*1000.00;
	QString path = QCoreApplication::applicationDirPath() + "//STYW.ini";
	//打开INI文件
	QSettings configIniWrite(path, QSettings::IniFormat);
	configIniWrite.setValue("ATTRIBUTE/HEIGHT", QString::number(*pHeight/1000.0));

}

//设备返回值
void ControlUI::setValue(QStringList list)
{
	switch (cmmIndex)
	{
	case 1701://设备号
	{
		if (list.count() < 1)
			break;
		ui.lineEdit_DNO->setText(list.at(0));
		break;
	}
	
	case 1703://设备时间
	{
		if (list.count() < 1)
			break;
		QDateTime time = QDateTime::fromString(list.at(0), "yyyy-MM-dd hh:mm:ss");
		ui.RdateTimeEdit->setDateTime(time);
		break;
	}
	default:
		if (list.count() < 1)
			break;
		QString r = list.at(0);
		if (r.toUpper().compare("T") == 0)
		{
			QMessageBox::about(this, QString::fromLocal8Bit("设备状态"), QString::fromLocal8Bit("操作成功！"));
		}
		else
		{
			QMessageBox::about(this, QString::fromLocal8Bit("设备状态"), QString::fromLocal8Bit("操作失败！"));
		}
		break;
	}
}
