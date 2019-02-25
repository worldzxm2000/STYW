#include<WinSock2.h>
#include "sh_styw.h"
#include"dictionary.h"
#include<QObject>
#include<QDateTime>
#include<QFile>
#include<QTextStream>
#include <QCoreApplication>
#include<QDir>
#include<QApplication>
//获取端口号
int GetPort()
{
	return 23008;
}

//获取业务号
int GetServiceTypeID()
{
	return 17;
}

//获取版本号
QString GetVersionNo()
{
	return "1.0";
}

//获取业务名称
QString GetServiceTypeName()
{
	QString name = QString::fromLocal8Bit("湿地水体液位业务");
	return name;
}

//矫正时钟
void SetTime(QString StationID,uint Socket)
{
	QDateTime nowtime = QDateTime::currentDateTime();
	QString datetime = nowtime.toString("yyyy-MM-dd hh:mm:ss");
	QString Comm = "DATETIME " + datetime + "\r\n";
	QByteArray ba = Comm.toLatin1();
	LPCSTR ch = ba.data();
	int len = Comm.length();
	::send(Socket, ch, len, 0);
}

//调试窗体
void  GetControlWidget(QString StationID, uint Socket, QWidget* parent)
{
	if (isActive)
	{
		return;
	}
    control_ui = new ControlUI();
	control_ui->pHeight = &HeightOffset;
	isActive = true;
	control_ui->Socket = Socket;
	control_ui->isActive = &isActive;
	control_ui->show();
}

//返回值反馈
void SetValueToControlWidget(QStringList list)
{
	if (control_ui == nullptr)
		return;
	
	if (isActive)
		control_ui->setValue(list);
}

//终端命令
void SetCommand(uint Socket, int CommandType, QString Params1, QString Params2, QString StationID)
{
	QString Comm;
	int len = Comm.length();
	switch (CommandType)
	{
	case 1701:
		//读取ID
		Comm = "ID\r\n";
		break;
	case 1702:
		//设置ID
		Comm = "ID " + Params1 + "\r\n";
		break;
	case 1703:
		//读取时钟
		Comm = "DATETIME\r\n";
		break;
	case 1704:
	{
		//设置时钟
		QDateTime nowtime = QDateTime::currentDateTime();
		QString datetime = nowtime.toString("yyyy-MM-dd hh:mm:ss");
		Comm = "DATETIME " + datetime + "\r\n";
	}
	break;
	case 1705:
		//远程升级
		Comm = "UPDATE\r\n";
		break;
	case 1706:
		//重启采集器
		Comm = "RESET\r\n";
		break;
	case 1707:
		//读取实时数据
		Comm = "SNAPSHOT\r\n";
		break;
	case 1708:
		//补抄数据
		Comm = "DMTD " + Params1 + " " + Params2 + "\r\n";
		break;
	default:
		break;
	}
	QByteArray ba = Comm.toLatin1();
	LPCSTR ch = ba.data();
	::send(Socket, ch, len, 0);
}

//解析数据
LRESULT Char2Json(QString &buff, QJsonObject &json)
{
	int Count = 0;//数据个数
	int Current_P = buff.length();//当前数据指

    //遍历查找数据
	for (int i = 0; i < buff.length() - 2; i++)
	{
		if (buff[i].toUpper() == 'B' && buff[i + 1].toUpper() == 'G'&&buff[i + 2] == ',')
		{
			Current_P = i;//指针指向帧头
			for (int j = i + 2; j < buff.length() - 2; j++)
			{
				if (buff[j] == ','&&buff[j + 1].toUpper() == 'E'&&buff[j + 2].toUpper() == 'D')
				{
					
					Dictionary dic;
					Current_P = j + 3;//指针移动到帧尾下一个字符
					
					QString strBuff = buff.mid(i, j - i + 3);
					QStringList strlist = strBuff.split(",");
					QJsonObject SubJson;
					SubJson.insert("DataType", 1);//数据类型 观测数据
												  //区站号
					SubJson.insert("StationID", strlist.at(1));
					//17水体液位
					SubJson.insert("ServiceTypeID", SH_STYW);
					//是否为手动采集
					SubJson.insert("SNAPSHOT",strlist.at(3).toInt());
					//设备ID
					SubJson.insert("DeviceID", strlist.at(4));
					//时间
					QString time = Convert2Time(strlist.at(5));
					SubJson.insert("ObserveTime", time);

					int CountOfFeature = ((QString)strlist.at(6)).toInt();
					SubJson.insert("CountOfFeature", CountOfFeature);
					int CountOfFacilitiesStatus = ((QString)strlist.at(7)).toInt();
					SubJson.insert("CountOfFacilitiesStatus", CountOfFacilitiesStatus);
					//判断数据完整性
					if (strlist.count() < CountOfFeature * 2 + CountOfFacilitiesStatus * 2 + 8)
					{
						i = j + 2;//当前循环
						continue;
					}
					//观察要素
					QString strFeatureName;

					for (int i = 8; i < CountOfFeature * 2 + 8; i += 2)
					{
						QString key = dic.Find(QString(strlist.at(i)).toLower());
						if (key != NULL)
						{
							float value = strlist.at(i + 1).toDouble();
							SubJson.insert(key, HeightOffset-value);
					
							//质量控制码
							if (i == 8)
							{
								strFeatureName = key;
							}
							else
							{
								strFeatureName += ",";
								strFeatureName += key;
							}
						}
					}
					//设备状态
					for (int i = CountOfFeature * 2 + 8; i < CountOfFeature * 2 + CountOfFacilitiesStatus * 2 + 8; i += 2)
					{
						QString key = dic.Find(QString(strlist.at(i)).toLower());
						if (key != NULL)
							SubJson.insert(key, strlist.at(i + 1));
					}
					Count += 1;//数据个数
					//数据备份
					QDateTime current_date_time = QDateTime::currentDateTime();
					QString current_date = current_date_time.toString("yyyy.MM.dd hh:mm:ss");
					QString current_day = current_date_time.toString("yyyy-MM-dd");
					QString fileName = QCoreApplication::applicationDirPath() + "\\SH\\STYW\\" + strlist.at(4) + "\\" + current_day;
					QDir dir(fileName);
					if (!dir.exists())
						dir.mkpath(fileName);//创建多级目录
					fileName += "\\data.txt";
					QFile file(fileName);
					if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
					{
					}
					QTextStream in(&file);
					in << current_date << "\r\n" << strBuff << "\r\n";
					file.close();
					json.insert(QString::number(Count), SubJson);
					i = j + 2;//当前循环
					break;
				}
			}
		}
		else if (buff[i] == '<')
		{
			Current_P = i;//指针指向帧头
			for (int j = i + 1; j < buff.length(); j++)
			{
				if (buff[j] == '>')
				{
					Current_P = j + 1;//指针移动到帧尾
					Count += 1;//数据个数
					QString subStr = buff.mid(i + 1, j - i - 1);
					QStringList strlist = subStr.split(",");
					QJsonObject SubJson;
					i = j;
					switch (strlist.count())
					{
					//心跳
					case 2:
					{
						SubJson.insert("DataType", 3);//数据类型 3心跳数据
						SubJson.insert("ServiceTypeID",SH_STYW);
						SubJson.insert("StationID", strlist.at(1));
						SubJson.insert("DeviceID", strlist.at(2));
						json.insert(QString::number(Count), SubJson);
						break;
					}
					//操作返回值
					case 6:
					{
						SubJson.insert("DataType", 2);//数据类型 2操作数据
						SubJson.insert("ValueCount", 7);
						SubJson.insert("ServiceTypeID", strlist.at(0));
						SubJson.insert("StationID", strlist.at(1));
						SubJson.insert("DeviceID", strlist.at(2));
						SubJson.insert("Command", strlist.at(3));
						SubJson.insert("RecvValue1", strlist.at(4));
						SubJson.insert("RecvValue2", strlist.at(5));
						SubJson.insert("RecvValue3", "NULL");
						SubJson.insert("RecvValue4", "NULL");
						json.insert(QString::number(Count), SubJson);
						break;
					}
					//无效数据
					default:
						break;
					}
					break;
				}
			}
		}
	}
	json.insert("DataLength", Count);//JSON数据个数
	if (Current_P >= buff.length())//判断当前指针位置
	{
		buff.clear();
	}//清除内存
	else
	{
		buff.remove(0, Current_P);
	}//将剩余字节存入缓存
	return 1;
}

QString Convert2Time(QString strTime)
{
	QString tmp;
	tmp = "to_date('" + strTime.mid(0, 4) + "-" + strTime.mid(4, 2) + "-" + strTime.mid(6, 2) + " " + strTime.mid(8, 2) + ":" + strTime.mid(10, 2) + ":" + strTime.mid(12, 2) + "', 'yyyy-mm-dd hh24:mi:ss')";
	return tmp;
}

