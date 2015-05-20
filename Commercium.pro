#-------------------------------------------------
#
# Project created by QtCreator 2015-04-25T18:46:27
#
#-------------------------------------------------

QT       += core gui widgets sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Commercium
TEMPLATE = app


SOURCES += main.cpp\
    formakalkulacije.cpp \
    formatrebovanje.cpp \
    formaprijemnica.cpp \
    formaotpremnica.cpp \
    commercium.cpp \
    formafaktura.cpp \
    formaprofaktura.cpp \
    formalogovanja.cpp \
    formanivelacija.cpp

HEADERS  += \
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
    formaotpremnica.h \
    commercium.h \
    formafaktura.h \
    formaprofaktura.h \
    formalogovanja.h \
    formanivelacija.h

FORMS    += commercium.ui \
    formakalkulacije.ui \
    formatrebovanje.ui \
    formaprijemnica.ui \
    formaotpremnica.ui \
    formafaktura.ui \
    formaprofaktura.ui \
    formalogovanja.ui \
    formanivelacija.ui

RESOURCES += \
    slike.qrc
