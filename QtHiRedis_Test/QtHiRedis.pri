message("Including QtHiredisLibs")

LIBS += -L$$PWD/QtHiRedis_Lib_PATH/libs -lQtHiRedis

INCLUDEPATH += $$PWD/QtHiRedis_Lib_PATH/include
HEADERS += $$PWD/QtHiRedis_Lib_PATH/include/adapters/qt.h
