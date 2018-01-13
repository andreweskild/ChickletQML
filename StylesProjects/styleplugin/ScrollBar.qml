import QtQuick 2.10
import QtQuick.Templates 2.3 as T
import QtGraphicalEffects 1.0
import styleplugin 1.0

T.ScrollBar {
    id: control

    implicitWidth: Math.max(background ? background.implicitWidth : 0,
                            contentItem.implicitWidth + leftPadding + rightPadding)
    implicitHeight: Math.max(background ? background.implicitHeight : 0,
                             contentItem.implicitHeight + topPadding + bottomPadding)

    clip: false
    padding: 3
    visible: control.policy !== T.ScrollBar.AlwaysOff

    contentItem: Item {
        implicitWidth: control.interactive ? 8 : StylePlugin.dimensions.progressBarWidth
        implicitHeight: control.interactive ? 8 : StylePlugin.dimensions.progressBarWidth

        Rectangle {
            id: handle
            height: parent.height
            width: parent.width
            color: control.interactive ? (control.pressed ? StylePlugin.palette.greyBlack
                                        : control.hovered ? StylePlugin.palette.greyMidDark : StylePlugin.palette.greyDark)
                                       : StylePlugin.palette.greyDark
            radius: height * .5
            y: control.pressed ? 2 : 0
            Behavior on y {
                NumberAnimation {
                    duration: 100
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
        }

    }


}
