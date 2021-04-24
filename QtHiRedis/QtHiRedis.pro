QT -= gui

TEMPLATE = lib
DEFINES += QTHIREDIS_LIBRARY

CONFIG += c++11

# Windows平台下使用了Winsock套接字
# Visual Studio下使用 #pragma comment(lib, "ws2_32")
# 引用ws2_32静态库
LIBS += -lws2_32

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0



SOURCES += \
    src/alloc.c \
    src/async.c \
    src/dict.c \
    src/hiredis.c \
    src/net.c \
    src/read.c \
    src/sds.c \
    src/sockcompat.c

HEADERS += \
    src/alloc.h \
    src/async.h \
    src/async_private.h \
    src/dict.h \
    src/fmacros.h \
    src/hiredis.h \
    src/hiredis_ssl.h \
    src/net.h \
    src/read.h \
    src/sds.h \
    src/sdsalloc.h \
    src/sockcompat.h \
    src/win32.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
