QT += core network qml jsonserializer restclient

HEADERS += \
	$$PWD/tst_global.h \
	$$PWD/jphpost.h

INCLUDEPATH += $$PWD

SOURCES += \
	$$PWD/jphpost.cpp \
	$$PWD/tst_global.cpp

DISTFILES += \
	$$PWD/rest-db-setup.bat \
	$$PWD/default-test-db.js \
	$$PWD/advanced-test-db.js \
    $$PWD/build-test-db.js \
    $$PWD/rest-db-setup.sh

DEFINES += "TEST_SRC_DIR=\\\"$$PWD\\\""

mac: QMAKE_LFLAGS += '-Wl,-rpath,\'$$OUT_PWD/../../../../lib\''
