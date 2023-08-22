QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    anonymous.cpp \
    anonymous1.cpp \
    app.cpp \
    date.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    myprofile.cpp \
    organisation.cpp \
    organisation1.cpp \
    otherstweets.cpp \
    own_tweet.cpp \
    personal.cpp \
    personl2.cpp \
    profile.cpp \
    searchs.cpp \
    showuthprof.cpp \
    signup.cpp \
    tweet.cpp \
    user.cpp

HEADERS += \
    anonymous.h \
    anonymous1.h \
    app.h \
    date.h \
    login.h \
    mainwindow.h \
    myprofile.h \
    organisation.h \
    organisation1.h \
    otherstweets.h \
    own_tweet.h \
    personal.h \
    personl2.h \
    profile.h \
    searchs.h \
    showuthprof.h \
    signup.h \
    tweet.h \
    user.h

FORMS += \
    anonymous1.ui \
    app.ui \
    login.ui \
    mainwindow.ui \
    myprofile.ui \
    organisation1.ui \
    otherstweets.ui \
    own_tweet.ui \
    personl2.ui \
    profile.ui \
    searchs.ui \
    showuthprof.ui \
    signup.ui \
    tweet.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    pics.qrc
