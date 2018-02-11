QT       += core quick multimedia
QT       += sql
QT       += core gui

TARGET = QtPlayground
CONFIG   -= console
CONFIG   += thread
CONFIG  += debug
QMAKE_CXXFLAGS += -std=c++11

TEMPLATE = app

target.path = /home/root

INSTALLS += target

SOURCES += main.cpp

include(MainWindow/MainWindow.pri)
include(Domain/Domain.pri)

RESOURCES += \
    MainWindow/presentation/view/MainWindow.qrc \
    presentation/view/app.qrc

OTHER_FILES += \
    presentation/view/app.qml

DISTFILES += \
    Domain/Domain.pri \
    Domain/Domain.pri
