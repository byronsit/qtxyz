android|ios|tvos|winrt {
    warning( "This example is not supported for android, ios, tvos, or winrt." )
}

QT_FOR_CONFIG += 3dcore
QT += 3dcore 3drender 3dinput 3dextras
QT += widgets
QT += 3dcore 3drender 3dinput 3dlogic 3dextras

SOURCES += main.cpp \
    LineEntity.cpp \
    QuaternionAxisEntity.cpp

HEADERS += \
    LineEntity.h \
    QuaternionAxisEntity.h


