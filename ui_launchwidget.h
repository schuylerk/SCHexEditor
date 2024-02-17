/********************************************************************************
** Form generated from reading UI file 'launchwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAUNCHWIDGET_H
#define UI_LAUNCHWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LaunchWidget
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *nameLabel;
    QLabel *versionLabel;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QProgressBar *progressBar;
    QLabel *label_2;

    void setupUi(QWidget *LaunchWidget)
    {
        if (LaunchWidget->objectName().isEmpty())
            LaunchWidget->setObjectName("LaunchWidget");
        LaunchWidget->resize(630, 375);
        LaunchWidget->setStyleSheet(QString::fromUtf8(""));
        widget = new QWidget(LaunchWidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(145, 0, 340, 111));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 4, 0, 0);
        nameLabel = new QLabel(widget);
        nameLabel->setObjectName("nameLabel");
        nameLabel->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(76);
        font.setBold(false);
        font.setItalic(true);
        font.setUnderline(false);
        nameLabel->setFont(font);
        nameLabel->setStyleSheet(QString::fromUtf8("color: rgb(85, 170, 255);"));
        nameLabel->setTextFormat(Qt::RichText);
        nameLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(nameLabel);

        versionLabel = new QLabel(widget);
        versionLabel->setObjectName("versionLabel");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        versionLabel->setFont(font1);
        versionLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        versionLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(versionLabel);

        frame = new QFrame(LaunchWidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(10, 50, 611, 321));
        QFont font2;
        font2.setKerning(true);
        frame->setFont(font2);
        frame->setStyleSheet(QString::fromUtf8("border-radius: 20;\n"
"background-color: rgb(28, 43, 104);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer);

        label = new QLabel(frame);
        label->setObjectName("label");
        QFont font3;
        font3.setPointSize(22);
        label->setFont(font3);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        progressBar = new QProgressBar(frame);
        progressBar->setObjectName("progressBar");
        progressBar->setMaximumSize(QSize(16777215, 2));
        progressBar->setStyleSheet(QString::fromUtf8("color: rgb(11, 0, 255);"));
        progressBar->setValue(24);
        progressBar->setTextVisible(false);
        progressBar->setOrientation(Qt::Horizontal);
        progressBar->setInvertedAppearance(false);

        verticalLayout_2->addWidget(progressBar);

        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(16777215, 20));
        QFont font4;
        font4.setPointSize(9);
        label_2->setFont(font4);
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: rgba(189, 191, 191, 199);"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        frame->raise();
        widget->raise();

        retranslateUi(LaunchWidget);

        QMetaObject::connectSlotsByName(LaunchWidget);
    } // setupUi

    void retranslateUi(QWidget *LaunchWidget)
    {
        LaunchWidget->setWindowTitle(QCoreApplication::translate("LaunchWidget", "Form", nullptr));
        nameLabel->setText(QCoreApplication::translate("LaunchWidget", "SCHex", nullptr));
        versionLabel->setText(QCoreApplication::translate("LaunchWidget", "1.0.0", nullptr));
        label->setText(QCoreApplication::translate("LaunchWidget", "\345\215\201\345\205\255\350\277\233\345\210\266\347\274\226\350\276\221\345\231\250", nullptr));
        label_2->setText(QCoreApplication::translate("LaunchWidget", "developed by kangsiwei", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LaunchWidget: public Ui_LaunchWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAUNCHWIDGET_H
