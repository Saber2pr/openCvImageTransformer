#-------------------------------------------------
#
# Project created by QtCreator 2018-08-04T23:28:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = openCvTest1
TEMPLATE = app


SOURCES += main.cpp \
    imagetransformer.cpp

HEADERS  += \
    imagetransformer.h

FORMS    +=

INCLUDEPATH += D://openCV//opencv//build//include//opencv2 \
               D://openCV//opencv//build//include//opencv \
               D://openCV//opencv//build//include

LIBS += D://openCV//opencv//build//x64//vc14//lib//*.lib


