import QtQuick 2.0
import QtQuick.Layouts 1.1
import QtGraphicalEffects 1.0

ListView {
    delegate: Rectangle {
        id: container
        anchors.left: parent.left
        anchors.right: parent.right
        height: childrenRect.height

        Rectangle {
            id: caption_bar
            color: "#c9f1fd"
            anchors.left: parent.left
            anchors.right: parent.right
            height: 56

            Text {
                text: caption
                horizontalAlignment: Text.AlignLeft
                font.family: "Verdana"
                font.pointSize: 16
                anchors.left: parent.left
                anchors.leftMargin: 15
                anchors.verticalCenter: parent.verticalCenter
                verticalAlignment: Text.AlignVCenter
            }
        }

        ProtocolSectionView {
            id: protocol_section_view
            anchors.top: caption_bar.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            model: protocols
        }

        Rectangle {
            id: easement
            anchors.top: protocol_section_view.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            height: 14
        }

        DropShadow {
            id: caption_bar_shadow
            anchors.fill: caption_bar
            verticalOffset: 3
            radius: 6.0
            samples: 16
            color: "#40000000"
            source: caption_bar
        }
    }
}
