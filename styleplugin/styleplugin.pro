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
    checkboxindicator.cpp \
    interactivegradientitem.cpp \
    linearrowindicator.cpp \
    busyindicatorarc.cpp \
    delaybuttonprogressindicator.cpp

HEADERS += \
    styleplugin_plugin.h \
    styleplugin.h \
    basepalette.h \
    checkboxindicator.h \
    interactivegradientitem.h \
    linearrowindicator.h \
    busyindicatorarc.h \
    delaybuttonprogressindicator.h

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
    PageIndicator.qml \
    Pane.qml \
    ScrollBar.qml \
    Switch.qml \
    ToolTip.qml \
    DelayButton.qml \
    TabBar.qml \
    TabButton.qml \
    StackView.qml \
    GenericInteractiveRounded.qml \
    GenericInteractiveCircle.qml \
    GenericInteractiveRect.qml \
    Drawer.qml \
    Tumbler.qml \
    ToolBar.qml \
    ToolButton.qml \
    RoundButton.qml \
    SpinBox.qml \
    RangeSlider.qml \
    TextArea.qml \
    CursorDelegate.qml \
    ColorPalette.qml \
    Dimensions.qml

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
