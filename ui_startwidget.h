/********************************************************************************
** Form generated from reading UI file 'startwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTWIDGET_H
#define UI_STARTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartWidget
{
public:
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QLabel *nameLabel;
    QLabel *descLabel;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *startLabel;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *openFileButton;
    QPushButton *createFileButton;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *recentOpenLabel;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_5;
    QListWidget *recentOpenList;

    void setupUi(QWidget *StartWidget)
    {
        if (StartWidget->objectName().isEmpty())
            StartWidget->setObjectName("StartWidget");
        StartWidget->resize(911, 511);
        QFont font;
        font.setFamilies({QString::fromUtf8(".AppleSystemUIFont")});
        StartWidget->setFont(font);
        StartWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(28, 43, 104);\n"
"background-color: rgb(108, 129, 255);\n"
"background-color: rgb(145, 151, 255);\n"
"background-color: rgb(100, 79, 255);\n"
"background-color: rgb(73, 99, 139);"));
        frame = new QFrame(StartWidget);
        frame->setObjectName("frame");
        frame->setEnabled(true);
        frame->setGeometry(QRect(10, 10, 261, 101));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(1);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName("verticalLayout");
        nameLabel = new QLabel(frame);
        nameLabel->setObjectName("nameLabel");
        QFont font1;
        font1.setPointSize(53);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setUnderline(false);
        nameLabel->setFont(font1);
        nameLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        nameLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(nameLabel);

        descLabel = new QLabel(frame);
        descLabel->setObjectName("descLabel");
        QFont font2;
        font2.setPointSize(10);
        descLabel->setFont(font2);
        descLabel->setStyleSheet(QString::fromUtf8("color: rgb(230, 233, 233);"));

        verticalLayout->addWidget(descLabel);

        frame_2 = new QFrame(StartWidget);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(40, 160, 81, 81));
        frame_2->setStyleSheet(QString::fromUtf8("border-width: 0.5;\n"
"border-style: solid;\n"
"border-color: rgb(127, 128, 128);\n"
"border-radius: 5;"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        startLabel = new QLabel(frame_2);
        startLabel->setObjectName("startLabel");
        startLabel->setMaximumSize(QSize(16777215, 22));
        startLabel->setFont(font2);
        startLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(150, 153, 255);\n"
"border-width: 0;"));
        startLabel->setMargin(5);

        verticalLayout_2->addWidget(startLabel);

        frame_3 = new QFrame(frame_2);
        frame_3->setObjectName("frame_3");
        frame_3->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"border-width: 0;"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_3);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(5, 0, 0, 0);
        openFileButton = new QPushButton(frame_3);
        openFileButton->setObjectName("openFileButton");
        QFont font3;
        font3.setPointSize(9);
        font3.setUnderline(true);
        openFileButton->setFont(font3);
        openFileButton->setCursor(QCursor(Qt::PointingHandCursor));
        openFileButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 208, 105);\n"
"text-align: left;"));

        verticalLayout_3->addWidget(openFileButton);

        createFileButton = new QPushButton(frame_3);
        createFileButton->setObjectName("createFileButton");
        createFileButton->setFont(font3);
        createFileButton->setCursor(QCursor(Qt::PointingHandCursor));
        createFileButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 208, 105);\n"
"text-align: left;"));

        verticalLayout_3->addWidget(createFileButton);


        verticalLayout_2->addWidget(frame_3);

        frame_4 = new QFrame(StartWidget);
        frame_4->setObjectName("frame_4");
        frame_4->setGeometry(QRect(350, 160, 471, 271));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_4);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        recentOpenLabel = new QLabel(frame_4);
        recentOpenLabel->setObjectName("recentOpenLabel");
        recentOpenLabel->setMaximumSize(QSize(16777215, 22));
        recentOpenLabel->setFont(font2);
        recentOpenLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(150, 153, 255);\n"
"border-width: 0;"));
        recentOpenLabel->setMargin(5);

        verticalLayout_4->addWidget(recentOpenLabel);

        frame_5 = new QFrame(frame_4);
        frame_5->setObjectName("frame_5");
        frame_5->setStyleSheet(QString::fromUtf8(""));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(frame_5);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(5, 5, 5, 5);
        recentOpenList = new QListWidget(frame_5);
        recentOpenList->setObjectName("recentOpenList");
        recentOpenList->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        verticalLayout_5->addWidget(recentOpenList);


        verticalLayout_4->addWidget(frame_5);


        retranslateUi(StartWidget);

        QMetaObject::connectSlotsByName(StartWidget);
    } // setupUi

    void retranslateUi(QWidget *StartWidget)
    {
        StartWidget->setWindowTitle(QCoreApplication::translate("StartWidget", "Form", nullptr));
        nameLabel->setText(QCoreApplication::translate("StartWidget", "SCHex", nullptr));
        descLabel->setText(QCoreApplication::translate("StartWidget", "\344\270\200\344\270\252\344\270\272\351\200\206\345\220\221\345\267\245\347\250\213\345\270\210\343\200\201\347\250\213\345\272\217\345\221\230\346\217\220\344\276\233\347\232\204\345\267\245\345\205\267", nullptr));
        startLabel->setText(QCoreApplication::translate("StartWidget", "\345\274\200\345\247\213", nullptr));
        openFileButton->setText(QCoreApplication::translate("StartWidget", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        createFileButton->setText(QCoreApplication::translate("StartWidget", "\345\210\233\345\273\272\346\226\207\344\273\266", nullptr));
        recentOpenLabel->setText(QCoreApplication::translate("StartWidget", "\346\234\200\350\277\221\346\211\223\345\274\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartWidget: public Ui_StartWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWIDGET_H
