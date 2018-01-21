import QtQuick 2.10
import QtQuick.Templates 2.3 as T
import QtGraphicalEffects 1.0
import styleplugin 1.0

T.ScrollBar {
    id: control

    implicitWidth: interactive ? Dimensions.commonHeight : Dimensions.progressBarWidth
    implicitHeight: interactive ? Dimensions.commonHeight : Dimensions.progressBarWidth

    clip: false
    visible: control.policy !== T.ScrollBar.AlwaysOff

    contentItem: Item {

        transform: Translate {
            y: control.vertical ?
                   (control.pressed ? Dimensions.elevation : 0) :
                   (control.pressed ? 0 : -Dimensions.elevation)


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
            visible: control.interactive

        }

        Rectangle {
            id: nonInteractiveHandle
            anchors.fill: parent
            color: ColorPalette.sunkenDark
            visible: !control.interactive
            radius: height / 2
        }

    }

    background: Item {
        anchors.fill: parent
        visible: control.interactive


        Rectangle {
            anchors.fill: parent
            radius: Dimensions.cornerRadius
            color: ColorPalette.sunken
        }
        Rectangle {
            width: control.horizontal ? control.position * control.width + handle.width : parent.width
            height: control.vertical ? control.position * control.height + handle.height + Dimensions.elevation : parent.height
            color: ColorPalette.sunkenDark
            radius: Dimensions.cornerRadius
        }
    }


}
