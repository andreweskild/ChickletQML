import QtQuick 2.10
import QtQuick.Templates 2.3 as T
import styleplugin 1.0

T.PageIndicator {
    id: control

    implicitWidth: Math.max(background ? background.implicitWidth : 0,
                            contentItem.implicitWidth + leftPadding + rightPadding)
    implicitHeight: 12

    padding: 6
    spacing: 8

    delegate: Item {
        anchors.verticalCenter: parent.verticalCenter
        height: control.height
        width: control.height

        Rectangle {
            height: index === currentIndex ? parent.height : parent.height * .66
            width: index === currentIndex ? parent.width : parent.width * .66
            anchors.centerIn: parent
            radius: width / 2
            color: index === currentIndex ? StylePlugin.palette.greyDark : StylePlugin.palette.greyMid

            Behavior on height {
                NumberAnimation {
                    duration: 150
                    easing {
                        type: Easing.InOutSine
                    }
                }
            }

            Behavior on width {
                NumberAnimation {
                    duration: 150
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

    contentItem: Row {
        spacing: control.spacing

        Repeater {
            model: control.count
            delegate: control.delegate
        }
    }
}
