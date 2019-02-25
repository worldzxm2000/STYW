#ifndef SH_STYW_H
#define SH_STYW_H

#define SH_STYW_HHARED_EXPORT __declspec(dllexport)
#ifdef SH_STYW_HHARED_EXPORT
#else
#define SH_STYW_HHARED_EXPORT __declspec(dllimport)
#endif

#include<Windows.h>
#include<QJsonObject>
#include<QWidget>
#include<QGroupBox>
#include<QDateTimeEdit>
#include<QLineEdit>
#include<QPushButton>
#include"ControlUI.h"
#define HEADER "BG"
#define TAIL "ED"
#define SH_STYW "17"

//��������
EXTERN_C SH_STYW_HHARED_EXPORT LRESULT Char2Json(QString &buff, QJsonObject &json);
QString Convert2Time(QString strTime);
//��ȡҵ���
EXTERN_C SH_STYW_HHARED_EXPORT int GetServiceTypeID();
//��ȡҵ������
EXTERN_C SH_STYW_HHARED_EXPORT QString GetServiceTypeName();
//��ȡ�˿ں�
EXTERN_C SH_STYW_HHARED_EXPORT int GetPort();
//��ȡ�汾��
EXTERN_C SH_STYW_HHARED_EXPORT QString GetVersionNo();
//���Դ���
EXTERN_C SH_STYW_HHARED_EXPORT void GetControlWidget(QString StationID, uint Socket, QWidget *parent);
//����ʱ��
EXTERN_C SH_STYW_HHARED_EXPORT void SetTime(QString StationID, uint Socket);
//��ʾ����ֵ
EXTERN_C SH_STYW_HHARED_EXPORT void  SetValueToControlWidget(QStringList list);
//��������
EXTERN_C SH_STYW_HHARED_EXPORT void SetCommand(uint Socket, int CommandType, QString Params1, QString Params2, QString StationID);
float HeightOffset;
ControlUI *control_ui;//�ն˴���
bool isActive;//�ж��ն˴����Ƿ���
#endif // SH_STYW_H
