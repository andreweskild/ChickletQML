import QtQuick 2.10
import QtQuick.Templates 2.3 as T
import styleplugin 1.0

T.ToolTip {
    id: control

    y: -implicitHeight - 8

    implicitWidth: contentItem.implicitWidth + leftPadding + rightPadding
    implicitHeight: 20


    padding: 2
    leftPadding: padding + 8
    rightPadding: padding + 8

    closePolicy: T.Popup.CloseOnEscape | T.Popup.CloseOnPressOutsideParent | T.Popup.CloseOnReleaseOutsideParent


    enter: Transition {
        // toast_enter
        NumberAnimation { property: "opacity"; from: 0.0; to: 1.0; easing.type: Easing.OutQuad; duration: 500 }
    }

    exit: Transition {
        // toast_exit
        NumberAnimation { property: "opacity"; from: 1.0; to: 0.0; easing.type: Easing.InQuad; duration: 500 }
    }

    contentItem: Text {
        text: control.text
        font: control.font
        // TODO: wrapMode: Label.Wrap
        color: ColorPalette.content
    }

    background: Item {
        anchors.fill: parent
        ShadowItem {
            anchors.fill: parent
        }
        Rectangle {
            anchors.fill: parent

            color: ColorPalette.sunkenDark
            radius: 4
        }
    }
}
