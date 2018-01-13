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



    indicator: Item {
            height: parent.height
            width: parent.height
            y: control.down ? 2 : 0

            Behavior on y {
                NumberAnimation {
                    duration: 100
                    easing {
                        type: Easing.InOutSine
                    }
                }
            }

            ShadowItem {
                anchors.fill: parent
                hidden: control.pressed
                hovered: control.hovered
            }

            GenericInteractiveRounded {
                id: background
                implicitWidth: control.height
                implicitHeight: control.height


                CheckBoxIndicator {
                    id: checkIndicator
                    anchors.fill: parent
                    lineWidth: 2
                    color: control.hovered ? StylePlugin.palette.greyWhite : StylePlugin.palette.greyBlack
                    dashOffset: control.checked ? 0 : 6

                    Behavior on dashOffset {
                        NumberAnimation {
                            duration: 150
                            easing {
                                type: Easing.InOutCubic
                            }
                        }
                    }

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
