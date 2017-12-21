import QtQuick 2.9
import QtQuick.Templates 2.2 as T
import QtGraphicalEffects 1.0
import styleplugin 1.0

T.CheckBox {
    id: control

    implicitWidth: Math.max(background ? background.implicitWidth : 0,
                            contentItem.implicitWidth + leftPadding + rightPadding)
    implicitHeight: StylePlugin.dimensions.checkableHeightWidth

    spacing: 16


    indicator: ActionableGeneric {
        id: checkBoxBackground
        implicitWidth: control.height
        implicitHeight: control.height


        CheckBoxIndicator {
            id: checkIndicator
            anchors.fill: parent
            lineWidth: 2
            color: StylePlugin.palette.greyBlack
            opacity: 0

            states: [
                State {
                    name: "hovered"; extend: "checked"; when: control.hovered && control.checked
                    changes: [
                        PropertyChanges {
                            target: checkIndicator
                            color: StylePlugin.palette.greyWhite
                        }
                    ]
                },
                State {
                    name: "checked"; when: control.checked
                    changes: [
                        PropertyChanges {
                            target: checkIndicator
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

                    ColorAnimation {
                        duration: 100
                        easing.type: Easing.InOutSine
                    }
                ]
            }

        }
    }

    contentItem: Text {
        leftPadding: control.indicator && !control.mirrored ? control.indicator.width + control.spacing : 0
        rightPadding: control.indicator && control.mirrored ? control.indicator.width + control.spacing : 0

        text: control.text
        font: control.font
        color: StylePlugin.palette.greyBlack
        elide: Text.ElideRight
        visible: control.text
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
    }
}
