import QtQuick 2.10
import QtQuick.Templates 2.3 as T
import styleplugin 1.0

T.Drawer {
    id: control

    parent: T.Overlay.overlay

    implicitWidth: Math.max(background ? background.implicitWidth : 0, contentWidth + leftPadding + rightPadding)
    implicitHeight: Math.max(background ? background.implicitHeight : 0, contentHeight + topPadding + bottomPadding)

    contentWidth: contentItem.implicitWidth || (contentChildren.length === 1 ? contentChildren[0].implicitWidth : 0)
    contentHeight: contentItem.implicitHeight || (contentChildren.length === 1 ? contentChildren[0].implicitHeight : 0)

    enter: Transition { SmoothedAnimation { velocity: 5 } }
    exit: Transition { SmoothedAnimation { velocity: 5 } }


    background: Rectangle {
        color: ColorPalette.raised

        Rectangle {
            readonly property bool horizontal: control.edge === Qt.LeftEdge || control.edge === Qt.RightEdge
            width: horizontal ? Dimensions.borderWidth : parent.width
            height: horizontal ? parent.height : Dimensions.borderWidth
            color: ColorPalette.sunken
            x: control.edge === Qt.LeftEdge ? parent.width - 1 : 0
            y: control.edge === Qt.TopEdge ? parent.height - 1 : 0
        }

    }

    T.Overlay.modal: Rectangle {
        color: "#22000000"
    }

    T.Overlay.modeless: Rectangle {
        color: "#22000000"
    }
}
