QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    launchwidget.cpp \
    main.cpp \
    mainwidget.cpp \
    sc_address_generator.cpp \
    sc_byte_operator.cpp \
    sc_hex_editor_logic.cpp \
    sc_line_edit.cpp \
    sc_plain_text_edit.cpp \
    startwidget.cpp \
    userdefaults.cpp \
    widget.cpp

HEADERS += \
    launchwidget.h \
    mainwidget.h \
    sc_address_generator.h \
    sc_byte_operator.h \
    sc_hex_editor_logic.h \
    sc_hex_editor_logic_interface.h \
    sc_line_edit.h \
    sc_plain_text_edit.h \
    startwidget.h \
    userdefaults.h \
    widget.h

FORMS += \
    launchwidget.ui \
    mainwidget.ui \
    startwidget.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    fonts/Recursive_VF_1.085.ttf
