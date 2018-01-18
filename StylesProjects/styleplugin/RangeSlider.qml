/****************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the Qt Quick Controls 2 module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL3$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPLv3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or later as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file. Please review the following information to
** ensure the GNU General Public License version 2.0 requirements will be
** met: http://www.gnu.org/licenses/gpl-2.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick 2.10
import QtQuick.Templates 2.3 as T
import styleplugin 1.0

T.RangeSlider {
    id: control

    implicitWidth: StylePlugin.dimensions.actionableWideWidth
    implicitHeight: StylePlugin.dimensions.actionableHeight

    first.handle: Item {
        id: firstHandle
        x: control.first.visualPosition * (control.availableWidth - width)
        height: control.height
        width: control.height

        transform: Translate {
            y: control.first.pressed ? 2 : 0


            Behavior on y {
                NumberAnimation {
                    duration: 100
                    easing {
                        type: Easing.InOutSine
                    }
                }
            }
        }

        ShadowItem {
            anchors.fill: parent
            hidden: control.first.pressed
            hovered: control.first.hovered
        }

        GenericInteractiveRounded {
            anchors.fill: parent
            pressed: control.first.pressed
            hovered: control.first.hovered
        }


    }

    second.handle: Item {
        id: secondHandle
        x: control.second.visualPosition * (control.availableWidth - width)
        height: control.height
        width: control.height

        transform: Translate {
            y: control.second.pressed ? 2 : 0


            Behavior on y {
                NumberAnimation {
                    duration: 100
                    easing {
                        type: Easing.InOutSine
                    }
                }
            }
        }

        ShadowItem {
            anchors.fill: parent
            hidden: control.second.pressed
            hovered: control.second.hovered
        }

        GenericInteractiveRounded {
            anchors.fill: parent
            pressed: control.second.pressed
            hovered: control.second.hovered
        }


    }

    background: Rectangle {
        y: 2
        width: parent.width
        height: parent.height
        color: StylePlugin.palette.greyMid
        radius: 4

        Rectangle {
            x: firstHandle.x
            width: secondHandle.x + secondHandle.width - firstHandle.x
            height: parent.height
            radius: 4
            color: StylePlugin.palette.greyDark
        }
    }
}
