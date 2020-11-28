QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calendar.cpp \
    formforget.cpp \
    formnew.cpp \
    formwrong.cpp \
    friends.cpp \
    main.cpp \
    redsocial.cpp

HEADERS += \
    avl.h \
    calendar.h \
    formforget.h \
    formnew.h \
    formwrong.h \
    friends.h \
    list.h \
    publicaciones.h \
    queue.h \
    redsocial.h

FORMS += \
    calendar.ui \
    formforget.ui \
    formnew.ui \
    formwrong.ui \
    friends.ui \
    redsocial.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
