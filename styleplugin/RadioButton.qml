import QtQuick 2.9
import QtQuick.Templates 2.2 as T
import styleplugin 1.0

T.RadioButton {
    id: control

    implicitWidth: Math.max(background ? background.implicitWidth : 0,
                            contentItem.implicitWidth + leftPadding + rightPadding)
    implicitHeight: 20

    spacing: 15


    indicator:Item {
        width: control.height
        height: control.height
        transform: Translate {
            y: control.pressed ? 2 : 0


            Behavior on y {
                NumberAnimation {
                    duration: 100
                    easing {
                        type: Easing.InOutSine
                    }
                }
            }
        }

        ShadowItem {
            anchors.fill: parent
            hidden: control.pressed
            hovered: control.hovered
            radius: parent.height * .5
        }

        GenericInteractiveCircle {
            id: radioBackground
            anchors.fill: parent
            hovered: control.hovered
            pressed: control.pressed


            Rectangle {
                id: toggleIndicator
                anchors.centerIn: parent
                width: control.checked ? control.height * .5 : 0
                height: control.checked ? control.height * .5 : 0
                radius: height * .5
                color: control.hovered ? ColorPalette.contentSecondary :
                                         ColorPalette.content
                opacity: control.checked ? 1 : 0

                Behavior on height {
                    NumberAnimation {
                        duration: 150
                        easing {
                            type: Easing.InOutSine
                        }
                    }
                }


                Behavior on width {
                    NumberAnimation {
                        duration: 150
                        easing {
                            type: Easing.InOutSine
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

                Behavior on opacity {
                    NumberAnimation {
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
        color: ColorPalette.content
        elide: Text.ElideRight
        visible: control.text
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
    }

}
