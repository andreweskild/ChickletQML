TEMPLATE = lib
TARGET = styleplugin
QT += qml quick
CONFIG += plugin c++11

TARGET = $$qtLibraryTarget($$TARGET)
uri = styleplugin

# Input
SOURCES += \
    styleplugin_plugin.cpp \
    styleplugin.cpp \
    basepalette.cpp \
    dimensionsprovider.cpp \
    actionablesurface.cpp \
    bordergroup.cpp \
    checkboxindicator.cpp \
    basicanimator.cpp \
    gradientgroup.cpp

HEADERS += \
    styleplugin_plugin.h \
    styleplugin.h \
    basepalette.h \
    dimensionsprovider.h \
    actionablesurface.h \
    bordergroup.h \
    checkboxindicator.h \
    basicanimator.h \
    gradientgroup.h

DISTFILES = qmldir \
    Button.qml \
    TextField.qml \
    Slider.qml \
    SliderHandle.qml \
    ProgressBar.qml \
    CheckBox.qml \
    ActionableGeneric.qml \
    RadioButton.qml

!equals(_PRO_FILE_PWD_, $$OUT_PWD) {
    copy_qmldir.target = $$OUT_PWD/qmldir
    copy_qmldir.depends = $$_PRO_FILE_PWD_/qmldir
    copy_qmldir.commands = $(COPY_FILE) \"$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)\" \"$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)\"
    QMAKE_EXTRA_TARGETS += copy_qmldir
    PRE_TARGETDEPS += $$copy_qmldir.target
}

qmldir.files = qmldir
unix {
    installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
    qmldir.path = $$installPath
    target.path = $$installPath
    INSTALLS += target qmldir
}

RESOURCES += \
    qml.qrc
