import QtQuick 2.9
import QtQuick.Window 2.3
import QtQuick.Controls 2.2
import QtQuick.Controls.impl 2.2
import QtQuick.Templates 2.2 as T
import styleplugin 1.0

T.ComboBox {
    id: control

    implicitWidth: StylePlugin.dimensions.actionableWideWidth
    implicitHeight: StylePlugin.dimensions.actionableHeight

    leftPadding: padding + (!control.mirrored || !indicator || !indicator.visible ? 0 : indicator.width + spacing)
    rightPadding: padding + (control.mirrored || !indicator || !indicator.visible ? 0 : indicator.width + spacing)


    delegate: MenuItem {
        width: parent.width
        height: StylePlugin.dimensions.actionableHeight - 1
        text: control.textRole ? (Array.isArray(control.model) ? modelData[control.textRole] : model[control.textRole]) : modelData
        highlighted: control.highlightedIndex === index
    }

    indicator: Item {
            height: parent.height
            width: parent.height
            anchors.right: parent.right
            y: control.pressed ? 2 : 0

            Behavior on y {
                NumberAnimation {
                    duration: 100
                    easing {
                        type: Easing.InOutSine
                    }
                }
            }

            LineArrowIndicator {
                id: arrowIndicator
                color: control.hovered || popup.opened ? StylePlugin.palette.greyWhite : StylePlugin.palette.greyBlack
                height: 6
                width: 10
                anchors.centerIn: parent
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

    contentItem: T.TextField {
        id: buttonText
        padding: 6
        leftPadding: control.editable ? 2 : control.mirrored ? 0 : 8
        rightPadding: control.editable ? 2 : control.mirrored ? 8 : 0

        text: control.editable ? control.editText : control.displayText

        enabled: control.editable
        autoScroll: control.editable
        readOnly: control.popup.visible
        inputMethodHints: control.inputMethodHints
        validator: control.validator

        font: control.font
        color: control.hovered || popup.visible ? StylePlugin.palette.greyWhite : StylePlugin.palette.greyBlack
        selectionColor: StylePlugin.palette.primaryNormal
        selectedTextColor: StylePlugin.palette.greyWhite
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter

        y: control.pressed ? 2 : 0

        Behavior on y {
            NumberAnimation {
                duration: 100
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

    background: Item {
        id: background
        width: control.width
        height: control.height

        ShadowItem {
            anchors.fill: parent
            hidden: control.pressed
            hovered: control.hovered
        }

        GenericInteractiveRounded {
            height: parent.height
            width: parent.width

        }


    }

    popup: T.Popup {
        id: popup
        width: control.width
        height: Math.min(contentItem.implicitHeight, control.Window.height - topMargin - bottomMargin) + topPadding + bottomPadding
        transformOrigin: Item.Top
        topPadding: 6
        bottomPadding: 6
        topMargin: 12
        bottomMargin: 12
        y: -topPadding

        enter: Transition {
            NumberAnimation {
                duration: 150
                easing {
                    type: Easing.InOutSine
                }

                target: background
                property: "height"
                to: popup.height
            }
            NumberAnimation {
                duration: 100
                easing {
                    type: Easing.InOutSine
                }

                targets: [background]
                property: "y"
                to: -popup.topPadding
            }
            NumberAnimation {
                targets: [arrowIndicator, buttonText]
                duration: 100
                easing {
                    type: Easing.InOutSine
                }
                property: "opacity"
                to: 0
            }
        }

        exit: Transition {
            NumberAnimation {
                duration: 150
                easing {
                    type: Easing.InOutSine
                }

                target: background
                property: "height"
                to: StylePlugin.dimensions.actionableHeight
            }
            NumberAnimation {
                targets: [arrowIndicator, buttonText]
                duration: 100
                easing {
                    type: Easing.InOutSine
                }
                property: "opacity"
                to: 1

            }

            NumberAnimation {
                duration: 100
                easing {
                    type: Easing.InOutSine
                }

                targets: [background]
                property: "y"
                to: 0
            }
        }

        contentItem: ListView {
            clip: true
            implicitHeight: contentHeight
            model: control.popup.visible ? control.delegateModel : null
            currentIndex: control.highlightedIndex
            highlightMoveDuration: 0

            T.ScrollIndicator.vertical: ScrollIndicator { }

            opacity: popup.opened ? 1 : 0

            Behavior on opacity {
                NumberAnimation {
                    duration: 150
                    easing {
                        type: Easing.InOutSine
                    }
                }
            }
        }

        background: Item {
        }
    }
}
