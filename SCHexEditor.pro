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
    widget.cpp \
    main/*.cpp \
    launch/*.cpp \
    start/*.cpp \
    customwidget/*.cpp

HEADERS += \
    scaddressgenerator.h \
    scbyteoperator.h \
    schexeditorlogic.h \
    schexeditorlogicinterface.h \
    startwidget.h \
    userdefaults.h \
    widget.h \
    main/*.h \
    launch/*.h \
    start/*.h \
    customwidget/.*h

FORMS += \
    widget.ui \
    main/*.ui \
    launch/*.ui \
    start/*.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    fonts/Recursive_VF_1.085.ttf
