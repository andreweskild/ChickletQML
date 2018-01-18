import QtQuick 2.10
import QtQuick.Templates 2.3 as T
import QtGraphicalEffects 1.0
import styleplugin 1.0

T.ScrollBar {
    id: control

    implicitWidth: 24
    implicitHeight: 24

    clip: false
    visible: control.policy !== T.ScrollBar.AlwaysOff

    contentItem: Item {
        implicitWidth: control.interactive ? 8 : StylePlugin.dimensions.progressBarWidth
        implicitHeight: control.interactive ? 8 : StylePlugin.dimensions.progressBarWidth

        transform: Translate {
            y: control.vertical ?
                   (control.pressed ? 2 : 0) :
                   (control.pressed ? 0 : -2)


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
        }

        GenericInteractiveRounded {
            id: handle
            anchors.fill: parent
            hovered: control.hovered
            pressed: control.pressed

        }


    }

    background: Item {
        anchors.fill: parent


        Rectangle {
            anchors.fill: parent
            radius: 4
            color: StylePlugin.palette.greyMid
        }
        Rectangle {
            width: control.horizontal ? control.position * control.width + handle.width : parent.width
            height: control.vertical ? control.position * control.height + handle.height + 2 : parent.height
            color: StylePlugin.palette.greyDark
            radius: 4
        }
    }


}
