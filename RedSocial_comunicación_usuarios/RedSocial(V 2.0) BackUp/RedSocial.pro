QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calendar.cpp \
    comentarios.cpp \
    formforget.cpp \
    formnew.cpp \
    formwrong.cpp \
    friends.cpp \
    main.cpp \
    message.cpp \
    redsocial.cpp \
    users.cpp

HEADERS += \
    Lista.h \
    Publicaciones.h \
    avl.h \
    calendar.h \
    comentarios.h \
    formforget.h \
    formnew.h \
    formwrong.h \
    friends.h \
    list.h \
    message.h \
    queue.h \
    redsocial.h \
    struct.h \
    users.h

FORMS += \
    calendar.ui \
    comentarios.ui \
    formforget.ui \
    formnew.ui \
    formwrong.ui \
    friends.ui \
    message.ui \
    redsocial.ui \
    users.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=
