TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        employee.cpp \
        main.cpp \
        manager.cpp \
        saleman.cpp \
        salemanger.cpp \
        technician.cpp

HEADERS += \
    employee.h \
    manager.h \
    saleman.h \
    salemanger.h \
    technician.h
