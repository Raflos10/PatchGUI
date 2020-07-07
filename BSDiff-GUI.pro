#-------------------------------------------------
#
# Project created by QtCreator 2020-07-06T12:09:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BSDiff-GUI
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    include/bsdifflib/bzip2/blocksort.c \
    include/bsdifflib/bzip2/bzlib.c \
    include/bsdifflib/bzip2/compress.c \
    include/bsdifflib/bzip2/crctable.c \
    include/bsdifflib/bzip2/decompress.c \
    include/bsdifflib/bzip2/huffman.c \
    include/bsdifflib/bzip2/randtable.c \
    include/bsdifflib/bsdifflib.c \
    include/bsdifflib/bspatchlib.c

HEADERS += \
        mainwindow.h \
    include/bsdifflib/bzip2/bzlib.h \
    include/bsdifflib/bzip2/bzlib_private.h \
    include/bsdifflib/bsdifflib.h \
    include/bsdifflib/bspatchlib.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
