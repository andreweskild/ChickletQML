import QtQuick 2.10
import QtQuick.Templates 2.3 as T
import styleplugin 1.0

T.SpinBox {
    id: control

    implicitWidth: 96
    implicitHeight: 24
    baselineOffset: contentItem.y + contentItem.baselineOffset

    leftPadding: (control.mirrored ? (up.indicator ? up.indicator.width : 0) : (down.indicator ? down.indicator.width : 0))
    rightPadding: (control.mirrored ? (down.indicator ? down.indicator.width : 0) : (up.indicator ? up.indicator.width : 0))

    validator: IntValidator {
        locale: control.locale.name
        bottom: Math.min(control.from, control.to)
        top: Math.max(control.from, control.to)
    }

    transform: Translate {
        y: control.up.pressed || control.down.pressed ? 2 : 0


        Behavior on y {
            NumberAnimation {
                duration: 100
                easing {
                    type: Easing.InOutSine
                }
            }
        }
    }

    contentItem: Item {
        anchors.horizontalCenter: parent.horizontalCenter

        Rectangle {
            width: parent.width
            height: parent.height
            anchors.centerIn: parent
            color: control.activeFocus ? ColorPalette.contentSecondary :
                    control.hovered ? ColorPalette.accent : ColorPalette.raised
            Behavior on color {
                ColorAnimation {
                    duration: 150
                    easing {
                        type: Easing.InOutSine
                    }
                }
            }
        }

        TextInput {
            id: input
            anchors.fill: parent
            text: control.textFromValue(control.value, control.locale)

            color: control.hovered && !activeFocus ? ColorPalette.contentSecondary :
                activeFocus ? "black" : ColorPalette.content
            selectionColor: ColorPalette.accent
            selectedTextColor: ColorPalette.contentSecondary
            horizontalAlignment: Qt.AlignHCenter
            verticalAlignment: Qt.AlignVCenter
            selectByMouse: true

            cursorDelegate: CursorDelegate{}

            readOnly: !control.editable
            validator: control.validator
            inputMethodHints: control.inputMethodHints
            Behavior on color {
                ColorAnimation {
                    duration: 150
                    easing {
                        type: Easing.InOutSine
                    }
                }
            }
        }
    }

    up.indicator: Item {
        x: control.mirrored ? 0 : parent.width - width
        implicitWidth: parent.height
        implicitHeight: parent.height
        height: parent.height
        width: height


        Rectangle {
            x: (parent.width - width) / 2
            y: (parent.height - height) / 2
            width: Math.min(parent.width / 4, parent.height / 4)
            height: 2
            color: control.hovered || input.activeFocus ? ColorPalette.contentSecondary : ColorPalette.content
            Behavior on color {
                ColorAnimation {
                    duration: 150
                    easing {
                        type: Easing.InOutSine
                    }
                }
            }
        }
        Rectangle {
            x: (parent.width - width) / 2
            y: (parent.height - height) / 2
            width: 2
            height: Math.min(parent.width / 4, parent.height / 4)
            color: control.hovered || input.activeFocus ? ColorPalette.contentSecondary : ColorPalette.content
            Behavior on color {
                ColorAnimation {
                    duration: 150
                    easing {
                        type: Easing.InOutSine
                    }
                }
            }
        }
    }

    down.indicator: Item {
        x: control.mirrored ? parent.width - width : 0
        implicitWidth: control.height
        implicitHeight: control.height
        height: parent.height
        width: height


        Rectangle {
            x: (parent.width - width) / 2
            y: (parent.height - height) / 2
            width: parent.width / 4
            height: 2
            color: control.hovered || input.activeFocus ? ColorPalette.contentSecondary : ColorPalette.content
            Behavior on color {
                ColorAnimation {
                    duration: 150
                    easing {
                        type: Easing.InOutSine
                    }
                }
            }
        }
    }

    background: Item {
        anchors.fill: parent
        ShadowItem {
            height: parent.height
            width: parent.width
            hovered: control.hovered
            hidden: control.up.pressed || control.down.pressed
        }

        GenericInteractiveRounded {
            height: parent.height
            width: parent.width
            hovered: control.hovered || input.activeFocus
            pressed: control.up.pressed || control.down.pressed
        }
    }
}
