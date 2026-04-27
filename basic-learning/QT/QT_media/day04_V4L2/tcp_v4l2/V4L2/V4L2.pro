#-------------------------------------------------
#
# Project created by QtCreator 2019-02-23T10:18:39
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = V4L2
TEMPLATE = app


SOURCES += main.cpp\
        videodisplay.cpp \
    v4l2.cpp

HEADERS  += videodisplay.h \
    v4l2.h

FORMS    += videodisplay.ui
