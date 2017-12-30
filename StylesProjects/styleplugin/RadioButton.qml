import QtQuick 2.9
import QtQuick.Templates 2.2 as T
import styleplugin 1.0

T.RadioButton {
    id: control

    implicitWidth: Math.max(background ? background.implicitWidth : 0,
                            contentItem.implicitWidth + leftPadding + rightPadding)
    implicitHeight: StylePlugin.dimensions.checkableHeightWidth

    spacing: 16

    indicator:Item {
        width: control.height
        height: control.height

        y: control.pressed ? 2 : 0

        Behavior on y {
            NumberAnimation {
                duration: 100
                easing {
                    type: Easing.OutSine
                }
            }
        }

        ShadowItem {
            width: parent.width
            height: parent.height
            hidden: control.pressed
        }

        InteractiveGradient {
            id: radioBackground
            implicitHeight: parent.height
            implicitWidth: parent.height
            geometryMode: InteractiveGradient.Circle
            pressed: control.pressed
            hovered: control.hovered


            Rectangle {
                id: toggleIndicator
                anchors.centerIn: parent
                width: control.checked ? control.height * .5 : 0
                height: control.checked ? control.height * .5 : 0
                radius: height * .5
                color: control.hovered ? StylePlugin.palette.greyWhite :
                                         StylePlugin.palette.greyMidDark
                opacity: control.checked ? 1 : 0
                border.width: 1
                border.color: control.hovered ? StylePlugin.palette.primaryMid :
                                                StylePlugin.palette.greyBlack

                Behavior on height {
                    NumberAnimation {
                        duration: 100
                        easing {
                            type: Easing.OutSine
                        }
                    }
                }


                Behavior on width {
                    NumberAnimation {
                        duration: 100
                        easing {
                            type: Easing.OutSine
                        }
                    }
                }

                Behavior on color {
                    ColorAnimation {
                        duration: 100
                        easing {
                            type: Easing.OutSine
                        }
                    }
                }

                Behavior on border.color {
                    ColorAnimation {
                        duration: 100
                        easing {
                            type: Easing.OutSine
                        }
                    }
                }

                Behavior on opacity {
                    NumberAnimation {
                        duration: 100
                        easing {
                            type: Easing.OutSine
                        }
                    }
                }
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
