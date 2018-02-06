import QtQuick 2.0
import Model 1.0

Item {
    height: 56

    ConditionBarVM {
        id: conditionBar
    }

    Rectangle {
        id: rectangle
        color: "#558abf"
        anchors.fill: parent
    }

}
