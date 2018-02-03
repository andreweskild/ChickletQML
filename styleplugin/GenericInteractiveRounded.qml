import QtQuick 2.0
import styleplugin 1.0

InteractiveGradientItem {
    id: background
    implicitHeight: 20
    implicitWidth: 96
    primaryColor: pressed ? ColorPalette.accentDark :
                    hovered ? ColorPalette.accent : ColorPalette.raised

    secondaryColor: pressed ? ColorPalette.accentLight :
                    hovered ? ColorPalette.accentLight : ColorPalette.raised

    property bool hovered: false
    property bool pressed: false

    Behavior on primaryColor {
        ColorAnimation {
            duration: 100
            easing {
                type: Easing.InOutSine
            }
        }
    }
    Behavior on secondaryColor {
        ColorAnimation {
            duration: 100
            easing {
                type: Easing.InOutSine
            }
        }
    }
}
