#-------------------------------------------------
#
# Project created by QtCreator 2018-11-30T20:40:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ACNL_SpotpassFileCreator
TEMPLATE = app
RC_ICONS = icon.ico

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

@
CONFIG(release, debug|release):DEFINES += QT_NO_DEBUG_OUTPUT
@

CONFIG += c++11

DEFINES += CBC=0
DEFINES += ECB=0
DEFINES += CTR=1

SOURCES += \
        Sources/main.cpp \
        Sources/mainwindow.cpp \
        Sources/rvcreator.cpp \
        Sources/values.cpp \
        Sources/checksum.cpp \
        Sources/boss.cpp \
        Sources/aes.c \
        Sources/file.cpp \
        Sources/utils.cpp \
        Sources/presentcreator.cpp \
        Sources/aboutwindow.cpp

HEADERS += \
        Headers/mainwindow.h \
        Headers/rvcreator.h \
        Headers/values.h \
        Headers/checksum.h \
        Headers/boss.h \
        Sources/aes.hpp \
        Headers/file.h \
        Headers/utils.hpp \
        Headers/presentcreator.h \
        Headers/aboutwindow.h

FORMS += \
        Forms/mainwindow.ui \
        Forms/rvcreator.ui \
        Forms/presentcreator.ui \
        Forms/aboutwindow.ui
        
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
