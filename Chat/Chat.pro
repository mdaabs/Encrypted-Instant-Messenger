#-------------------------------------------------
#
# Project created by QtCreator 2014-03-20T18:39:56
#
#-------------------------------------------------



QT       += core

QT       -= gui

QT      +=widgets
QT       += gui


TARGET = Chat
CONFIG   += console
CONFIG   -= app_bundle
CONFIG += static

TEMPLATE = app


SOURCES += \
    mainwindow.cpp \
    main.cpp \
    user.cpp \
    tabdialog.cpp \
    convoTab.cpp \
    sendtoencrypt.cpp \
    allusers.cpp \
    login.cpp \
    newuser.cpp \
    settings.cpp


HEADERS += \
    mainwindow.h \
    user.h \
    tabdialog.h \
    convoTab.h \
    sendtoencrypt.h \
    allusers.h \
    login.h \
    newuser.h \
    settings.h

FORMS += \
    mainwindow.ui \
    tabdialog.ui \
    convoTab.ui \
    login.ui \
    newuser.ui \
    settings.ui

OTHER_FILES += \
    text.txt \
    users.txt \
    convo.txt \
    removed_functions.txt \
    all.txt \
    currentuserinfo.txt



