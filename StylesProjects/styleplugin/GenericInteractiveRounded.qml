import QtQuick 2.0
import styleplugin 1.0

InteractiveGradientItem {
    id: background
    height: parent.height
    width: parent.width
    primaryColor: pressed ? StylePlugin.palette.primaryMid :
                    hovered ? StylePlugin.palette.primaryNormal : StylePlugin.palette.greyLight
    secondaryColor: pressed ? StylePlugin.palette.primaryLight :
                    hovered ? StylePlugin.palette.primaryLight : StylePlugin.palette.greyLight

    property bool hovered: false
    property bool pressed: false

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
}
