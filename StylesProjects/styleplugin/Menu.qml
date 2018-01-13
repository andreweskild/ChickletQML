import QtQuick 2.10
import QtQuick.Controls 2.3
import QtQuick.Templates 2.3 as T
import styleplugin 1.0


T.Menu {
    id: control

    implicitWidth: StylePlugin.dimensions.actionableWideWidth
    implicitHeight: Math.max(background ? background.implicitHeight : 0,
                             contentItem ? contentItem.implicitHeight : 0) + topPadding + bottomPadding

    property bool isOpen: false

    topPadding: 8
    bottomPadding: 8





    transformOrigin: !cascade ? Item.Top : (mirrored ? Item.TopRight : Item.TopLeft)

    delegate: MenuItem {}

    enter: Transition {
        // grow_fade_in
        NumberAnimation { property: "scale"; from: 0.9; to: 1.0; easing.type: Easing.OutQuint; duration: 220 }
        NumberAnimation { property: "opacity"; from: 0.0; to: 1.0; easing.type: Easing.OutCubic; duration: 150 }
        PropertyAction { target: control; property: "isOpen"; value: true }
    }

    exit: Transition {
        // shrink_fade_out
        NumberAnimation { property: "scale"; from: 1.0; to: 0.9; easing.type: Easing.OutQuint; duration: 220 }
        NumberAnimation { property: "opacity"; from: 1.0; to: 0.0; easing.type: Easing.OutCubic; duration: 150 }
        PropertyAction { target: control; property: "isOpen"; value: false }
    }

    contentItem: ListView {
        implicitHeight: contentHeight

        model: control.contentModel
        // TODO: improve this?
        interactive: ApplicationWindow.window ? contentHeight > ApplicationWindow.window.height : false
        currentIndex: control.currentIndex

        ScrollIndicator.vertical: ScrollIndicator {}
    }

    background: Item {
        id: background
        width: control.width
        height: control.height

        ShadowItem {
            anchors.fill: parent
        }

        Rectangle {
            height: parent.height
            width: parent.width
            color: StylePlugin.palette.greyLight
            radius: StylePlugin.dimensions.actionableRadius

            Behavior on y {
                NumberAnimation {
                    duration: 100
                    easing {
                        type: Easing.InOutSine
                    }
                }
            }

        }

        Rectangle {
            color: StylePlugin.palette.greyLight
            width: control.parent.width
            y: -2
            height: 6
        }


    }
}
