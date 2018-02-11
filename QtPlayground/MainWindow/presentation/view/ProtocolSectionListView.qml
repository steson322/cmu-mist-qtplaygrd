import QtQuick 2.0
import QtQuick.Layouts 1.1

ListView {
    Layout.fillHeight: true
    Layout.fillWidth: true

    delegate: Rectangle {
        id: container
        anchors.topMargin: -1
        anchors.left: parent.left
        anchors.right: parent.right
        height: 56

        Rectangle {
            id: rectangle
            color: "#ffffff"
            anchors.topMargin: -1
            border.color: "#d0d0d0"
            border.width: 1
            anchors.fill: parent
        }
    }

//    delegate: ListView {
//        Layout.fillHeight: true
//        Layout.fillWidth: true

//        model: model

//        height: 50
//        width: 50

//        delegate: Rectangle {
//            width: 10
//            height: 10
//            color: "#ff0000"
//        }
//    }

//    delegate: Rectangle {
//        width: 10
//        height: 10
//        color: "#ff0000"
//    }
}
