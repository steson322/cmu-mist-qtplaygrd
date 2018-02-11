import QtQuick 2.0
import QtQuick.Layouts 1.1

ListView {
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

            Text {
                text: caption
            }

            ProtocolSectionView {
                model: protocols
            }
        }
    }
}
