import QtQuick 2.10
import QtQuick.Controls 2.3
import QtQuick.Controls.impl 2.3
import QtQuick.Templates 2.3 as T
import styleplugin 1.0

T.Tumbler {
    id: control
    implicitWidth: 24
    implicitHeight: 72 + topPadding + bottomPadding
    visibleItemCount: 3

    topPadding: 6
    bottomPadding: 6

    background: Rectangle {
        anchors.fill: parent
        color: control.hovered ? ColorPalette.sunkenDark : ColorPalette.sunken
        Behavior on color {
            ColorAnimation {
                duration: 150
                easing {
                    type: Easing.InOutSine
                }
            }
        }
    }

    delegate: Text {
        id: label
        text: modelData
        color: control.hovered ? ColorPalette.contentSecondary : ColorPalette.content
        opacity: 0.4 + Math.max(0, 1 - Math.abs(Tumbler.displacement)) * 0.6
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        Behavior on color {
            ColorAnimation {
                duration: 150
                easing {
                    type: Easing.InOutSine
                }
            }
        }
    }

    contentItem: TumblerView {
        id: tumblerView
        model: control.model
        delegate: control.delegate
        path: Path {
            startX: tumblerView.width / 2
            startY: -tumblerView.delegateHeight / 2
            PathLine {
                x: tumblerView.width / 2
                y: (control.visibleItemCount + 1) * tumblerView.delegateHeight - tumblerView.delegateHeight / 2
            }
        }

        property real delegateHeight: control.availableHeight / control.visibleItemCount
    }
}
