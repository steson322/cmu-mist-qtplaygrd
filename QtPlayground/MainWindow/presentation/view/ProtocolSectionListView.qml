import QtQuick 2.0
import QtQuick.Layouts 1.1

ListView {
    Layout.fillHeight: true
    Layout.fillWidth: true

    delegate: Rectangle {
        width: 10
        height: 10
        color: "#ff0000"
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
