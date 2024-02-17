QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    scaddressgenerator.cpp \
    scbyteoperator.cpp \
    schexeditorlogic.cpp \
    userdefaults.cpp \
    main/main.cpp \
    main/mainwidget.cpp \
    launch/launchwidget.cpp \
    start/startwidget.cpp \
    customwidget/sclineedit.cpp \
    customwidget/scplaintextedit.cpp \
    editormain/editormainwidget.cpp

HEADERS += \
    scaddressgenerator.h \
    scbyteoperator.h \
    schexeditorlogic.h \
    schexeditorlogicinterface.h \
    startwidget.h \
    userdefaults.h \
    main/mainwidget.h \
    launch/launchwidget.h \
    start/startwidget.h \
    customwidget/sclineedit.h \
    customwidget/scplaintextedit.h \
    editormain/editormainwidget.h

FORMS += \
    main/mainwidget.ui \
    launch/launchwidget.ui \
    start/startwidget.ui \
    editormain/editormainwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    fonts/Recursive_VF_1.085.ttf
