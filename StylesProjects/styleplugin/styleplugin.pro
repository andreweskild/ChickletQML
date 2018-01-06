TEMPLATE = lib
TARGET = styleplugin
QT += qml quick widgets
CONFIG += plugin c++11

TARGET = $$qtLibraryTarget($$TARGET)
uri = styleplugin

# Input
SOURCES += \
    styleplugin_plugin.cpp \
    styleplugin.cpp \
    basepalette.cpp \
    dimensionsprovider.cpp \
    checkboxindicator.cpp \
    interactivegradientitem.cpp \
    rectangleitem.cpp \
    linearrowindicator.cpp \
    interactiveroundbutton.cpp \
    interactivebutton.cpp \
    interactivemenuitem.cpp \
    busyindicatorarc.cpp

HEADERS += \
    styleplugin_plugin.h \
    styleplugin.h \
    basepalette.h \
    dimensionsprovider.h \
    checkboxindicator.h \
    interactivegradientitem.h \
    rectangleitem.h \
    linearrowindicator.h \
    interactiveroundbutton.h \
    interactivebutton.h \
    interactivemenuitem.h \
    busyindicatorarc.h

DISTFILES = qmldir \
    Button.qml \
    TextField.qml \
    Slider.qml \
    ProgressBar.qml \
    CheckBox.qml \
    RadioButton.qml \
    ApplicationWindow.qml \
    ShadowItem.qml \
    ComboBox.qml \
    MenuItem.qml \
    BusyIndicator.qml \
    Frame.qml \
    GroupBox.qml \
    MenuBar.qml \
    Menu.qml \
    MenuBarItem.qml \
    MenuSeparator.qml \
    PageIndicator.qml

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

include($$_PRO_FILE_PWD_/libqnanopainter/include.pri)
