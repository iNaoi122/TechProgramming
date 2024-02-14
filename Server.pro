QT -= gui
QT +=network
QT += core5compat

QT += widgets

CONFIG += c++17 console
CONFIG -= app_bundle

TARGET = print-qstringlist


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        db.cpp \
        des.cpp \
        main.cpp \
        mytcpserver.cpp \
        server_logic.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    db.h \
    des.h \
    mytcpserver.h \
    server_logic.h

DISTFILES += \
    Dockerfile
