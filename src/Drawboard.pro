QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    mylabel.cpp \
    productinfo.cpp \
    register.cpp

HEADERS += \
    login.h \
    mainwindow.h \
    mylabel.h \
    productinfo.h \
    register.h

FORMS += \
    login.ui \
    mainwindow.ui \
    productinfo.ui \
    register.ui

QT += \
    sql \
    network

INCLUDEPATH += D:/aliyun-oss-cpp-sdk/sdk/include \
               D:/aliyun-oss-cpp-sdk/sdk/src \
               D:/aliyun-oss-cpp-sdk/third_party/include
               D:/wamp/bin/mysql/mysql5.7.31/include

LIBS += -llibcurl
LIBS += -llibeay32
LIBS += -lssleay32
LIBS += -lalibabacloud-oss-cpp-sdk
LIBS += -llibmysql

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    DrawBoard.qrc
