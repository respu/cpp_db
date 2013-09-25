#-------------------------------------------------
#
# Project created by QtCreator 2013-09-11T16:57:55
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = cppdb
CONFIG   += console
CONFIG   -= app_bundle
CONFIG += c++11

TEMPLATE = app


SOURCES += main.cpp \
    connection.cpp \
    ../sqlite/sqlite3.c \
    sql_statement.cpp

HEADERS += \
    nullable.h \
    value_is_null.h \
    nullable_types.h \
    key_value_pair.h \
    coalesce.h \
    null.h \
    test.h \
    connection.h \
    sql_statement.h \
    cpp11_defines.h \
    db_exception.h

INCLUDEPATH += ../sqlite
