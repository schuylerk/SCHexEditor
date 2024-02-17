/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <customwidget/scplaintextedit.h>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *addressFrame;
    QVBoxLayout *verticalLayout;
    QLabel *label_address;
    SCPlainTextEdit *addressPlainTextEdit;
    QFrame *hexFrame;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_byte;
    SCPlainTextEdit *hexPlainTextEdit;
    QFrame *asciiFrame;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_ascii;
    SCPlainTextEdit *asciiPlainTextEdit;
    QFrame *scrollBarFrame;
    QVBoxLayout *verticalLayout_4;
    QScrollBar *verticalScrollBar;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(1024, 671);
        Widget->setWindowOpacity(1.000000000000000);
        Widget->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        horizontalLayout = new QHBoxLayout(Widget);
        horizontalLayout->setObjectName("horizontalLayout");
        addressFrame = new QFrame(Widget);
        addressFrame->setObjectName("addressFrame");
        addressFrame->setMaximumSize(QSize(200, 16777215));
        addressFrame->setFrameShape(QFrame::StyledPanel);
        addressFrame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(addressFrame);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_address = new QLabel(addressFrame);
        label_address->setObjectName("label_address");
        label_address->setMaximumSize(QSize(100, 16777215));
        QFont font;
        font.setFamilies({QString::fromUtf8("Fixedsys")});
        font.setPointSize(12);
        label_address->setFont(font);
        label_address->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_address->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_address->setIndent(4);

        verticalLayout->addWidget(label_address);

        addressPlainTextEdit = new SCPlainTextEdit(addressFrame);
        addressPlainTextEdit->setObjectName("addressPlainTextEdit");
        addressPlainTextEdit->setMinimumSize(QSize(120, 0));
        addressPlainTextEdit->setMaximumSize(QSize(120, 16777215));
        addressPlainTextEdit->setFont(font);
        addressPlainTextEdit->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        addressPlainTextEdit->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255, 0);"));
        addressPlainTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        addressPlainTextEdit->setBackgroundVisible(false);

        verticalLayout->addWidget(addressPlainTextEdit);


        horizontalLayout->addWidget(addressFrame);

        hexFrame = new QFrame(Widget);
        hexFrame->setObjectName("hexFrame");
        hexFrame->setFrameShape(QFrame::StyledPanel);
        hexFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(hexFrame);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_byte = new QLabel(hexFrame);
        label_byte->setObjectName("label_byte");
        label_byte->setFont(font);
        label_byte->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_byte->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_byte->setMargin(0);
        label_byte->setIndent(4);

        verticalLayout_3->addWidget(label_byte);

        hexPlainTextEdit = new SCPlainTextEdit(hexFrame);
        hexPlainTextEdit->setObjectName("hexPlainTextEdit");
        hexPlainTextEdit->setEnabled(true);
        hexPlainTextEdit->setMinimumSize(QSize(600, 0));
        hexPlainTextEdit->setFont(font);
        hexPlainTextEdit->setMouseTracking(false);
        hexPlainTextEdit->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"selection-background-color: rgb(255, 170, 0);\n"
"selection-color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255, 0);"));
        hexPlainTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout_3->addWidget(hexPlainTextEdit);


        horizontalLayout->addWidget(hexFrame);

        asciiFrame = new QFrame(Widget);
        asciiFrame->setObjectName("asciiFrame");
        asciiFrame->setMaximumSize(QSize(200, 16777215));
        asciiFrame->setFrameShape(QFrame::StyledPanel);
        asciiFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(asciiFrame);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_ascii = new QLabel(asciiFrame);
        label_ascii->setObjectName("label_ascii");
        label_ascii->setMaximumSize(QSize(16777215, 16777215));
        label_ascii->setFont(font);
        label_ascii->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_ascii->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_ascii->setIndent(4);

        verticalLayout_2->addWidget(label_ascii);

        asciiPlainTextEdit = new SCPlainTextEdit(asciiFrame);
        asciiPlainTextEdit->setObjectName("asciiPlainTextEdit");
        asciiPlainTextEdit->setMinimumSize(QSize(160, 0));
        asciiPlainTextEdit->setMaximumSize(QSize(16777215, 16777215));
        asciiPlainTextEdit->setFont(font);
        asciiPlainTextEdit->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255, 0);"));
        asciiPlainTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout_2->addWidget(asciiPlainTextEdit);


        horizontalLayout->addWidget(asciiFrame);

        scrollBarFrame = new QFrame(Widget);
        scrollBarFrame->setObjectName("scrollBarFrame");
        scrollBarFrame->setMaximumSize(QSize(8, 16777215));
        scrollBarFrame->setFrameShape(QFrame::StyledPanel);
        scrollBarFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(scrollBarFrame);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalScrollBar = new QScrollBar(scrollBarFrame);
        verticalScrollBar->setObjectName("verticalScrollBar");
        verticalScrollBar->setStyleSheet(QString::fromUtf8("QScrollBar:vertical {\n"
"border: none;\n"
"background: transparent;\n"
"width: 6px;\n"
"} \n"
"QScrollBar::handle:vertical \n"
"{\n"
"background-color: rgba(255,255,255,1);\n"
"min-height: 30px;\n"
"border-radius:3px;\n"
"width: 6px;\n"
"}\n"
"QScrollBar::add-line:vertical \n"
"{\n"
"border: none;\n"
"height: 0px;\n"
"} \n"
"QScrollBar::sub-line:vertical \n"
"{\n"
"border: none;\n"
"height: 0px;\n"
"} \n"
"QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical \n"
"{\n"
"background:transparent;\n"
"border-radius:3px;\n"
"}"));
        verticalScrollBar->setOrientation(Qt::Vertical);

        verticalLayout_4->addWidget(verticalScrollBar);


        horizontalLayout->addWidget(scrollBarFrame);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label_address->setText(QCoreApplication::translate("Widget", "Address", nullptr));
        label_byte->setText(QCoreApplication::translate("Widget", "00  01  02  03  04  05  06  07    08  09  0A  0B  0C  0D  0E  0F", nullptr));
        label_ascii->setText(QCoreApplication::translate("Widget", "ASCII", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
