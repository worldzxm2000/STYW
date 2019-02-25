#pragma once

#include <QWidget>
#include "ui_ControlUI.h"
#include<QMouseEvent>
class ControlUI : public QWidget
{
	Q_OBJECT

public:
	ControlUI(QWidget *parent = Q_NULLPTR);
	~ControlUI();
	//ˮλ�궨ֵ
	float* pHeight;
	uint Socket;//Socket��
	void setValue(QStringList list);//����ֵ
	bool *isActive;//�жϴ����Ƿ���
private:
	Ui::ControlUI ui;
	int cmmIndex;//��¼��ǰ��������
	//�����ƶ�
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);
	bool m_Drag;                //�ж��������Ƿ���
	QPoint m_DragPosition;
protected:
	void closeEvent(QCloseEvent *event);
private slots:

    void slot_minWindow();

    void on_RDNOBtn_clicked();

    void on_WNOBtn_clicked();

    void on_RTimeBtn_clicked();

    void on_WTimeBtn_clicked();

    void on_WCAPINTERVALBtn_clicked();

    void on_RESETBtn_clicked();

    void on_WSNAPSHOTBtn_clicked();

    void on_DownBtn_clicked();

    void on_WHOFFSETBtn_clicked();
};
