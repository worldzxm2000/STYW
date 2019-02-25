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
	ui.CloseBtn->setToolTipName(QString::fromLocal8Bit("�ر�"));
	ui.MinBtn->setToolTipName(QString::fromLocal8Bit("��С��"));
	connect(ui.MinBtn, SIGNAL(clicked()), this, SLOT(slot_minWindow()));
	connect(ui.CloseBtn, SIGNAL(clicked()), this, SLOT(close()));
	cmmIndex = 0;
	//��ȡini�ļ�����
	QString path = QCoreApplication::applicationDirPath() + "//STYW.ini";
	//��INI�ļ�
	QSettings configIniRead(path, QSettings::IniFormat);
	//�ն��������
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
	//��ȡID
	QString Comm = "ID\r\n";
	QByteArray ba = Comm.toLatin1();
	LPCSTR ch = ba.data();
	int len = Comm.length();
	::send(Socket, ch, len, 0);
}

void ControlUI::on_WNOBtn_clicked()
{
	cmmIndex = 1702;
	//����ID
	QString Comm = "ID " + ui.lineEdit_DNO->text().trimmed() + "\r\n";
	QByteArray ba = Comm.toLatin1();
	LPCSTR ch = ba.data();
	int len = Comm.length();
	::send(Socket, ch, len, 0);
}

void ControlUI::on_RTimeBtn_clicked()
{
	cmmIndex = 1703;
	//��ȡʱ��
	QString Comm = "DATETIME\r\n";
	QByteArray ba = Comm.toLatin1();
	LPCSTR ch = ba.data();
	int len = Comm.length();
	::send(Socket, ch, len, 0);
}

void ControlUI::on_WTimeBtn_clicked()
{
	cmmIndex = 1704;
	//����ʱ��
	QString Time;
	Time = ui.RdateTimeEdit->dateTime().toString("yyyy-MM-dd HH:mm:ss");
	QString Comm = "DATETIME " + Time + "\r\n";
	QByteArray ba = Comm.toLatin1();
	LPCSTR ch = ba.data();
	int len = Comm.length();
	::send(Socket, ch, len, 0);
}

//Զ������
void ControlUI::on_WCAPINTERVALBtn_clicked()
{
	cmmIndex = 1705;
	//Զ������
	QString Comm = "UPDATE\r\n";
	QByteArray ba = Comm.toLatin1();
	LPCSTR ch = ba.data();
	int len = Comm.length();
	::send(Socket, ch, len, 0);
}

void ControlUI::on_RESETBtn_clicked()
{
	cmmIndex = 1706;
	//�����ɼ���
	QString Comm = "RESET\r\n";
	QByteArray ba = Comm.toLatin1();
	LPCSTR ch = ba.data();
	int len = Comm.length();
	::send(Socket, ch, len, 0);
}

void ControlUI::on_WSNAPSHOTBtn_clicked()
{
	cmmIndex = 1707;
	//��ȡʵʱ����
	QString Comm = "SNAPSHOT\r\n";
	QByteArray ba = Comm.toLatin1();
	LPCSTR ch = ba.data();
	int len = Comm.length();
	::send(Socket, ch, len, 0);
}

//��������
void ControlUI::on_DownBtn_clicked()
{
	cmmIndex = 1708;
	//��������
	QString Time_B, Time_E;
	Time_B = ui.BdateTimeEdit->dateTime().toString("yyyy-MM-dd HH:mm");
	Time_E = ui.EdateTimeEdit->dateTime().toString("yyyy-MM-dd HH:mm");
	QString Comm = "DMTD " + Time_B + " " + Time_E + "\r\n";
	QByteArray ba = Comm.toLatin1();
	LPCSTR ch = ba.data();
	int len = Comm.length();
	::send(Socket, ch, len, 0);
}

//ƫ����
void ControlUI::on_WHOFFSETBtn_clicked()
{
	*pHeight = (ui.lineEdit_HOFFSET->text().toDouble())*1000.00;
	QString path = QCoreApplication::applicationDirPath() + "//STYW.ini";
	//��INI�ļ�
	QSettings configIniWrite(path, QSettings::IniFormat);
	configIniWrite.setValue("ATTRIBUTE/HEIGHT", QString::number(*pHeight/1000.0));

}

//�豸����ֵ
void ControlUI::setValue(QStringList list)
{
	switch (cmmIndex)
	{
	case 1701://�豸��
	{
		if (list.count() < 1)
			break;
		ui.lineEdit_DNO->setText(list.at(0));
		break;
	}
	
	case 1703://�豸ʱ��
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
			QMessageBox::about(this, QString::fromLocal8Bit("�豸״̬"), QString::fromLocal8Bit("�����ɹ���"));
		}
		else
		{
			QMessageBox::about(this, QString::fromLocal8Bit("�豸״̬"), QString::fromLocal8Bit("����ʧ�ܣ�"));
		}
		break;
	}
}
