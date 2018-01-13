import QtQuick 2.0
import styleplugin 1.0

InteractiveGradientItem {
    id: background
    height: parent.height
    width: parent.width
    shape: InteractiveGradientItem.Rect
    primaryColor: control.pressed ? StylePlugin.palette.primaryMid :
                    control.hovered ? StylePlugin.palette.primaryNormal : StylePlugin.palette.greyLight
    secondaryColor: control.hovered ? StylePlugin.palette.primaryLight : StylePlugin.palette.greyLight

    Behavior on primaryColor {
        ColorAnimation {
            duration: 150
            easing {
                type: Easing.InOutSine
            }
        }
    }
    Behavior on secondaryColor {
        ColorAnimation {
            duration: 150
            easing {
                type: Easing.InOutSine
            }
        }
    }
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
