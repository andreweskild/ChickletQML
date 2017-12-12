import QtQuick 2.9
import QtQuick.Templates 2.2 as T
import styleplugin 1.0

T.RadioButton {
    id: control

    implicitWidth: Math.max(background ? background.implicitWidth : 0,
                            contentItem.implicitWidth + leftPadding + rightPadding)
    implicitHeight: StylePlugin.dimensions.checkableHeightWidth

    spacing: 16

    indicator: ActionableGeneric {
        id: radioBackground
        implicitHeight: control.height
        implicitWidth: control.height
        pressed: control.pressed
        hovered: control.hovered
        radius: height * .5


        Rectangle {
            id: toggleIndicator
            anchors.centerIn: parent
            width: control.height * .5
            height: control.height * .5
            radius: height * .5
            color: StylePlugin.palette.actionableDark
            opacity: control.checked ? 1 : 0
            border.width: 1
            border.color: StylePlugin.palette.actionableMain


            states: [
                State {
                    name: "hovered"; extend: "checked"; when: control.hovered && control.checked
                    changes: [
                        PropertyChanges {
                            target: toggleIndicator
                            color: StylePlugin.palette.textLight
                        },
                        PropertyChanges {
                            target: toggleIndicator
                            border.color: StylePlugin.palette.activeDark
                        }
                    ]
                },
                State {
                    name: "checked"; when: control.checked
                    changes: [
                        PropertyChanges {
                            target: toggleIndicator
                            opacity: 1
                        }
                    ]
                }
            ]

            transitions: Transition {
                reversible: true
                animations: [
                    NumberAnimation {
                        duration: 100
                        properties: "opacity"
                        easing.type: Easing.InOutSine
                    },

                    PropertyAction {
                        target: toggleIndicator; property: "color" }
                ]
            }
        }

    }

    contentItem: Text {
        leftPadding: control.indicator && !control.mirrored ? control.indicator.width + control.spacing : 0
        rightPadding: control.indicator && control.mirrored ? control.indicator.width + control.spacing : 0

        text: control.text
        font: control.font
        color: StylePlugin.palette.textDark
        elide: Text.ElideRight
        visible: control.text
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
    }
}
