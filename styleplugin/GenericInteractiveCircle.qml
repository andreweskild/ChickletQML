import QtQuick 2.0
import styleplugin 1.0

InteractiveGradientItem {
    id: background
    implicitHeight: 20
    implicitWidth: 20
    shape: InteractiveGradientItem.Circle
    primaryColor: dangerous ?
        (pressed ? ColorPalette.dangerousDark :
                   hovered ? ColorPalette.dangerous : ColorPalette.dangerousLight) :
        (pressed ? ColorPalette.accentDark :
                    hovered ? ColorPalette.accent : ColorPalette.raised)

    secondaryColor: dangerous ?
        (pressed ? ColorPalette.dangerousLight :
                    hovered ? ColorPalette.dangerousLight : ColorPalette.dangerousLight) :
        (pressed ? ColorPalette.accentLight :
                    hovered ? ColorPalette.accentLight : ColorPalette.raised)

    property bool hovered: false
    property bool pressed: false
    property bool dangerous: false

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
