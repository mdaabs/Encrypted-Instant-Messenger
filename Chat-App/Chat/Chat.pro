#-------------------------------------------------
#
# Project created by QtCreator 2014-03-20T18:39:56
#
#-------------------------------------------------



QT       += core

QT       -= gui

QT      +=widgets
QT       += gui
QT +=  network

TARGET = Crypt-Chat
TARGET =../Chat-Executable/Crypt-Chat
CONFIG   += console
CONFIG   -= app_bundle
CONFIG += static


TEMPLATE = app
LIBS += -LC:/usr/include/openssl-lubsec
INCLUDEPATH += C:/usr/include/openssl
 LIBS += -Lc:/mingw/msys/1.0/local/lib  -lssl -lcrypto

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
    settings.cpp \
    Encryption.cpp \
    b64.cpp \
    sendtoclient.cpp \
    client.cpp \
    mythread.cpp \
    addnewfriend.cpp \
    rectest.cpp \
    changepassword.cpp


HEADERS += \
    mainwindow.h \
    user.h \
    tabdialog.h \
    convoTab.h \
    sendtoencrypt.h \
    allusers.h \
    login.h \
    newuser.h \
    settings.h \
    Encryption.h \
    b64.h \
    sendtoclient.h \
    client.h \
    mythread.h \
    addnewfriend.h \
    rectest.h \
    changepassword.h

FORMS += \
    mainwindow.ui \
    tabdialog.ui \
    convoTab.ui \
    login.ui \
    newuser.ui \
    settings.ui \
    addnewfriend.ui \
    rectest.ui \
    changepassword.ui

OTHER_FILES += \
    users.txt \
    convo.txt \
    removed_functions.txt \
    currentuserinfo.txt \
    allen.txt \
    george.txt \
    jon.txt \
    mario.txt \
    Demitri.txt \
    Pomplun.txt

RESOURCES +=



