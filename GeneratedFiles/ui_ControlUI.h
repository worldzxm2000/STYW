/********************************************************************************
** Form generated from reading UI file 'ControlUI.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLUI_H
#define UI_CONTROLUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>
#include"MyButton.h"
QT_BEGIN_NAMESPACE

class Ui_ControlUI
{
public:
    QGroupBox *groupBox_3;
    QGroupBox *groupBox;
    QGroupBox *groupBox_time;
    QDateTimeEdit *RdateTimeEdit;
    QPushButton *RTimeBtn;
    QPushButton *WTimeBtn;
    QGroupBox *groupBox_DNO;
    QPushButton *RDNOBtn;
    QPushButton *WNOBtn;
    QLineEdit *lineEdit_DNO;
    QGroupBox *groupBox_HOFFSET;
    QPushButton *WHOFFSETBtn;
    QLineEdit *lineEdit_HOFFSET;
    QLabel *label;
    QGroupBox *groupBox_CAPINTERVAL;
    QPushButton *WCAPINTERVALBtn;
    QGroupBox *groupBox_RESET;
    QPushButton *RESETBtn;
    QGroupBox *groupBox_down;
    QDateTimeEdit *BdateTimeEdit;
    QDateTimeEdit *EdateTimeEdit;
    QPushButton *DownBtn;
    QGroupBox *groupBox_SNAPSHOT;
    QPushButton *WSNAPSHOTBtn;
    QLabel *TiltleLabel;
    QLabel *TitleLabel_Name;
    QGroupBox *groupBox_2;
    QScrollArea *ScrollArea_MinBtn;
    QWidget *ScrollAreaWidgetContents_MinBtn;
	MyButton *MinBtn;
    QScrollArea *ScrollArea_CloseBtn;
    QWidget *ScrollAreaWidgetContents_CloseBtn;
	MyButton *CloseBtn;

    void setupUi(QWidget *ControlUI)
    {
        if (ControlUI->objectName().isEmpty())
            ControlUI->setObjectName(QStringLiteral("ControlUI"));
        ControlUI->resize(469, 391);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        ControlUI->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral("../Image/png/Weather.ico"), QSize(), QIcon::Normal, QIcon::Off);
        ControlUI->setWindowIcon(icon);
        ControlUI->setStyleSheet(QStringLiteral("background:rgb(77,77, 77);color:white"));
        groupBox_3 = new QGroupBox(ControlUI);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 10, 451, 371));
        groupBox_3->setFont(font);
        groupBox = new QGroupBox(groupBox_3);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(15, 45, 421, 311));
        QFont font1;
        groupBox->setFont(font1);
        groupBox_time = new QGroupBox(groupBox);
        groupBox_time->setObjectName(QStringLiteral("groupBox_time"));
        groupBox_time->setGeometry(QRect(210, 10, 191, 91));
        groupBox_time->setFont(font);
        RdateTimeEdit = new QDateTimeEdit(groupBox_time);
        RdateTimeEdit->setObjectName(QStringLiteral("RdateTimeEdit"));
        RdateTimeEdit->setGeometry(QRect(10, 20, 161, 22));
        RdateTimeEdit->setFont(font);
        RdateTimeEdit->setDateTime(QDateTime(QDate(2018, 9, 1), QTime(0, 0, 0)));
        RTimeBtn = new QPushButton(groupBox_time);
        RTimeBtn->setObjectName(QStringLiteral("RTimeBtn"));
        RTimeBtn->setGeometry(QRect(10, 50, 75, 23));
        RTimeBtn->setFont(font);
        WTimeBtn = new QPushButton(groupBox_time);
        WTimeBtn->setObjectName(QStringLiteral("WTimeBtn"));
        WTimeBtn->setGeometry(QRect(90, 50, 75, 23));
        WTimeBtn->setFont(font);
        groupBox_DNO = new QGroupBox(groupBox);
        groupBox_DNO->setObjectName(QStringLiteral("groupBox_DNO"));
        groupBox_DNO->setGeometry(QRect(10, 10, 171, 91));
        groupBox_DNO->setFont(font);
        RDNOBtn = new QPushButton(groupBox_DNO);
        RDNOBtn->setObjectName(QStringLiteral("RDNOBtn"));
        RDNOBtn->setGeometry(QRect(10, 50, 75, 23));
        RDNOBtn->setFont(font);
        WNOBtn = new QPushButton(groupBox_DNO);
        WNOBtn->setObjectName(QStringLiteral("WNOBtn"));
        WNOBtn->setGeometry(QRect(90, 50, 75, 23));
        WNOBtn->setFont(font);
        lineEdit_DNO = new QLineEdit(groupBox_DNO);
        lineEdit_DNO->setObjectName(QStringLiteral("lineEdit_DNO"));
        lineEdit_DNO->setGeometry(QRect(10, 20, 151, 20));
        lineEdit_DNO->setFont(font);
        groupBox_HOFFSET = new QGroupBox(groupBox);
        groupBox_HOFFSET->setObjectName(QStringLiteral("groupBox_HOFFSET"));
        groupBox_HOFFSET->setGeometry(QRect(260, 210, 151, 81));
        groupBox_HOFFSET->setFont(font);
        WHOFFSETBtn = new QPushButton(groupBox_HOFFSET);
        WHOFFSETBtn->setObjectName(QStringLiteral("WHOFFSETBtn"));
        WHOFFSETBtn->setGeometry(QRect(10, 50, 75, 23));
        WHOFFSETBtn->setFont(font);
        lineEdit_HOFFSET = new QLineEdit(groupBox_HOFFSET);
        lineEdit_HOFFSET->setObjectName(QStringLiteral("lineEdit_HOFFSET"));
        lineEdit_HOFFSET->setGeometry(QRect(10, 20, 71, 20));
        lineEdit_HOFFSET->setFont(font);
        label = new QLabel(groupBox_HOFFSET);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(85, 20, 61, 20));
        label->setFont(font);
        groupBox_CAPINTERVAL = new QGroupBox(groupBox);
        groupBox_CAPINTERVAL->setObjectName(QStringLiteral("groupBox_CAPINTERVAL"));
        groupBox_CAPINTERVAL->setGeometry(QRect(10, 110, 101, 71));
        groupBox_CAPINTERVAL->setFont(font);
        WCAPINTERVALBtn = new QPushButton(groupBox_CAPINTERVAL);
        WCAPINTERVALBtn->setObjectName(QStringLiteral("WCAPINTERVALBtn"));
        WCAPINTERVALBtn->setGeometry(QRect(10, 30, 75, 23));
        WCAPINTERVALBtn->setFont(font);
        groupBox_RESET = new QGroupBox(groupBox);
        groupBox_RESET->setObjectName(QStringLiteral("groupBox_RESET"));
        groupBox_RESET->setGeometry(QRect(150, 110, 101, 71));
        groupBox_RESET->setFont(font);
        RESETBtn = new QPushButton(groupBox_RESET);
        RESETBtn->setObjectName(QStringLiteral("RESETBtn"));
        RESETBtn->setGeometry(QRect(10, 30, 75, 23));
        RESETBtn->setFont(font);
        groupBox_down = new QGroupBox(groupBox);
        groupBox_down->setObjectName(QStringLiteral("groupBox_down"));
        groupBox_down->setGeometry(QRect(10, 210, 241, 81));
        groupBox_down->setFont(font);
        BdateTimeEdit = new QDateTimeEdit(groupBox_down);
        BdateTimeEdit->setObjectName(QStringLiteral("BdateTimeEdit"));
        BdateTimeEdit->setGeometry(QRect(10, 20, 141, 22));
        BdateTimeEdit->setFont(font);
        BdateTimeEdit->setDateTime(QDateTime(QDate(2018, 9, 1), QTime(0, 0, 0)));
        EdateTimeEdit = new QDateTimeEdit(groupBox_down);
        EdateTimeEdit->setObjectName(QStringLiteral("EdateTimeEdit"));
        EdateTimeEdit->setGeometry(QRect(10, 50, 141, 22));
        EdateTimeEdit->setFont(font);
        EdateTimeEdit->setDateTime(QDateTime(QDate(2018, 9, 1), QTime(0, 0, 0)));
        DownBtn = new QPushButton(groupBox_down);
        DownBtn->setObjectName(QStringLiteral("DownBtn"));
        DownBtn->setGeometry(QRect(160, 20, 75, 23));
        DownBtn->setFont(font);
        groupBox_SNAPSHOT = new QGroupBox(groupBox);
        groupBox_SNAPSHOT->setObjectName(QStringLiteral("groupBox_SNAPSHOT"));
        groupBox_SNAPSHOT->setGeometry(QRect(290, 110, 101, 71));
        groupBox_SNAPSHOT->setFont(font);
        WSNAPSHOTBtn = new QPushButton(groupBox_SNAPSHOT);
        WSNAPSHOTBtn->setObjectName(QStringLiteral("WSNAPSHOTBtn"));
        WSNAPSHOTBtn->setGeometry(QRect(10, 30, 75, 23));
        WSNAPSHOTBtn->setFont(font);
        TiltleLabel = new QLabel(groupBox_3);
        TiltleLabel->setObjectName(QStringLiteral("TiltleLabel"));
        TiltleLabel->setGeometry(QRect(15, 10, 32, 32));
        TiltleLabel->setFont(font);
        TiltleLabel->setPixmap(QPixmap(QString::fromUtf8("../Image/png/control.png")));
        TitleLabel_Name = new QLabel(groupBox_3);
        TitleLabel_Name->setObjectName(QStringLiteral("TitleLabel_Name"));
        TitleLabel_Name->setGeometry(QRect(50, 15, 71, 16));
        TitleLabel_Name->setFont(font);
        groupBox_2 = new QGroupBox(groupBox_3);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(390, 10, 46, 26));
        groupBox_2->setFont(font1);
        ScrollArea_MinBtn = new QScrollArea(groupBox_2);
        ScrollArea_MinBtn->setObjectName(QStringLiteral("ScrollArea_MinBtn"));
        ScrollArea_MinBtn->setGeometry(QRect(2, 3, 20, 20));
        ScrollArea_MinBtn->setFont(font);
        ScrollArea_MinBtn->setWidgetResizable(true);
        ScrollAreaWidgetContents_MinBtn = new QWidget();
        ScrollAreaWidgetContents_MinBtn->setObjectName(QStringLiteral("ScrollAreaWidgetContents_MinBtn"));
        ScrollAreaWidgetContents_MinBtn->setGeometry(QRect(0, 0, 18, 18));
		MinBtn = new MyButton("../Image/png/Mini.png", 1, ScrollAreaWidgetContents_MinBtn);
        MinBtn->setObjectName(QStringLiteral("MinBtn"));
        MinBtn->setGeometry(QRect(1, 1, 18, 18));
        MinBtn->setFont(font);
        ScrollArea_MinBtn->setWidget(ScrollAreaWidgetContents_MinBtn);
        ScrollArea_CloseBtn = new QScrollArea(groupBox_2);
        ScrollArea_CloseBtn->setObjectName(QStringLiteral("ScrollArea_CloseBtn"));
        ScrollArea_CloseBtn->setGeometry(QRect(24, 3, 20, 20));
        ScrollArea_CloseBtn->setFont(font);
        ScrollArea_CloseBtn->setWidgetResizable(true);
        ScrollAreaWidgetContents_CloseBtn = new QWidget();
        ScrollAreaWidgetContents_CloseBtn->setObjectName(QStringLiteral("ScrollAreaWidgetContents_CloseBtn"));
        ScrollAreaWidgetContents_CloseBtn->setGeometry(QRect(0, 0, 18, 18));
		CloseBtn = new MyButton("../Image/png/Close.png", 1, ScrollAreaWidgetContents_CloseBtn);
        CloseBtn->setObjectName(QStringLiteral("CloseBtn"));
        CloseBtn->setGeometry(QRect(1, 1, 18, 18));
        CloseBtn->setFont(font);
        ScrollArea_CloseBtn->setWidget(ScrollAreaWidgetContents_CloseBtn);
        QWidget::setTabOrder(lineEdit_DNO, RDNOBtn);
        QWidget::setTabOrder(RDNOBtn, WNOBtn);
        QWidget::setTabOrder(WNOBtn, RdateTimeEdit);
        QWidget::setTabOrder(RdateTimeEdit, RTimeBtn);
        QWidget::setTabOrder(RTimeBtn, WTimeBtn);
        QWidget::setTabOrder(WTimeBtn, WCAPINTERVALBtn);
        QWidget::setTabOrder(WCAPINTERVALBtn, RESETBtn);
        QWidget::setTabOrder(RESETBtn, WSNAPSHOTBtn);
        QWidget::setTabOrder(WSNAPSHOTBtn, BdateTimeEdit);
        QWidget::setTabOrder(BdateTimeEdit, EdateTimeEdit);
        QWidget::setTabOrder(EdateTimeEdit, DownBtn);
        QWidget::setTabOrder(DownBtn, lineEdit_HOFFSET);
        QWidget::setTabOrder(lineEdit_HOFFSET, WHOFFSETBtn);
        QWidget::setTabOrder(WHOFFSETBtn, MinBtn);
        QWidget::setTabOrder(MinBtn, CloseBtn);
        QWidget::setTabOrder(CloseBtn, ScrollArea_MinBtn);
        QWidget::setTabOrder(ScrollArea_MinBtn, ScrollArea_CloseBtn);

        retranslateUi(ControlUI);

        QMetaObject::connectSlotsByName(ControlUI);
    } // setupUi

    void retranslateUi(QWidget *ControlUI)
    {
        ControlUI->setWindowTitle(QApplication::translate("ControlUI", "\346\260\264\344\275\223\346\266\262\344\275\215\344\273\252\350\256\276\345\244\207\346\216\247\345\210\266", nullptr));
        groupBox_3->setTitle(QString());
        groupBox->setTitle(QString());
        groupBox_time->setTitle(QApplication::translate("ControlUI", "\350\256\276\345\244\207\346\227\266\351\227\264", nullptr));
        RTimeBtn->setText(QApplication::translate("ControlUI", "\350\257\273\345\217\226\346\227\266\351\222\237", nullptr));
        WTimeBtn->setText(QApplication::translate("ControlUI", "\350\256\276\347\275\256\346\227\266\351\222\237", nullptr));
        groupBox_DNO->setTitle(QApplication::translate("ControlUI", "\350\256\276\345\244\207\345\217\267", nullptr));
        RDNOBtn->setText(QApplication::translate("ControlUI", "\350\257\273\345\217\226\350\256\276\345\244\207\345\217\267", nullptr));
        WNOBtn->setText(QApplication::translate("ControlUI", "\350\256\276\347\275\256\350\256\276\345\244\207\345\217\267", nullptr));
        groupBox_HOFFSET->setTitle(QApplication::translate("ControlUI", "\346\260\264\344\275\215\345\201\217\347\247\273", nullptr));
        WHOFFSETBtn->setText(QApplication::translate("ControlUI", "\350\256\276\347\275\256", nullptr));
        lineEdit_HOFFSET->setText(QApplication::translate("ControlUI", "1", nullptr));
        label->setText(QApplication::translate("ControlUI", "\345\215\225\344\275\215\357\274\210\347\261\263\357\274\211", nullptr));
        groupBox_CAPINTERVAL->setTitle(QApplication::translate("ControlUI", "\350\277\234\347\250\213\345\215\207\347\272\247", nullptr));
        WCAPINTERVALBtn->setText(QApplication::translate("ControlUI", "\350\277\234\347\250\213\345\215\207\347\272\247", nullptr));
        groupBox_RESET->setTitle(QApplication::translate("ControlUI", "\351\207\207\351\233\206\345\231\250", nullptr));
        RESETBtn->setText(QApplication::translate("ControlUI", "\351\207\215\345\220\257", nullptr));
        groupBox_down->setTitle(QApplication::translate("ControlUI", "\346\225\260\346\215\256\350\241\245\346\212\204", nullptr));
        DownBtn->setText(QApplication::translate("ControlUI", "\350\241\245\346\212\204\346\225\260\346\215\256", nullptr));
        groupBox_SNAPSHOT->setTitle(QApplication::translate("ControlUI", "\346\211\213\345\212\250\351\207\207\351\233\206", nullptr));
        WSNAPSHOTBtn->setText(QApplication::translate("ControlUI", "\351\207\207\351\233\206", nullptr));
        TiltleLabel->setText(QString());
        TitleLabel_Name->setText(QApplication::translate("ControlUI", "\346\260\264\344\275\223\346\266\262\344\275\215\344\273\252", nullptr));
        groupBox_2->setTitle(QString());
        MinBtn->setText(QApplication::translate("ControlUI", "PushButton", nullptr));
        CloseBtn->setText(QApplication::translate("ControlUI", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ControlUI: public Ui_ControlUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLUI_H
