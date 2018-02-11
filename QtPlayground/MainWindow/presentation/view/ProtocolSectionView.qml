import QtQuick 2.0
import QtQuick.Layouts 1.1

ListView {
    height: childrenRect.height

    delegate: Rectangle {
        id: protocol_bar
        color: "#ffffff"
        anchors.topMargin: -1
        border.color: "#d0d0d0"
        border.width: 1
        anchors.left: parent.left
        anchors.right: parent.right
        height: 56

        ProtocolView {
            anchors.fill: parent
        }
    }
}
