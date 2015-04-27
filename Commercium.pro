#-------------------------------------------------
#
# Project created by QtCreator 2015-04-25T18:46:27
#
#-------------------------------------------------

QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Commercium
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    formakalkulacije.cpp \
    formatrebovanje.cpp \
    formaprijemnica.cpp \
    formaotpremnica.cpp

HEADERS  += mainwindow.h \
    artikl.h \
    komitent.h \
    kakulacija.h \
    kepu.h \
    prijemnica.h \
    trebovanje.h \
    faktura.h \
    profaktura.h \
    knjigaedi.h \
    formakalkulacije.h \
    otpremnica.h \
    formatrebovanje.h \
    formaprijemnica.h \
    formaotpremnica.h

FORMS    += commercium.ui \
    formakalkulacije.ui \
    formatrebovanje.ui \
    formaprijemnica.ui \
    formaotpremnica.ui

RESOURCES +=
