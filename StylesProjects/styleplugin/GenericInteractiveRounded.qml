import QtQuick 2.0
import styleplugin 1.0

InteractiveGradientItem {
    id: background
    height: parent.height
    width: parent.width
    primaryColor: pressed ? Theme.primaryMid :
                    hovered ? Theme.primaryNormal : Theme.greyLight
    secondaryColor: pressed ? Theme.primaryLight :
                    hovered ? Theme.primaryLight : Theme.greyLight

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
