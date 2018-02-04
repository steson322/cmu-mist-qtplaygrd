import QtQuick 2.0

//The module Model is dynamically created from Main. This is how the backend c++ code is exposed to the UI
import Model 1.0

import "qrc:///presentation/view"

/// Main page Item
Item {
    id: litdeco
    width: 1920
    height: 1080
    z: 0

    /// Property An array initialized with dummy values, that can be used to pass parameters among pages
    /// when loading pages with navigateTo()
    property var pageParams: { "target": "some text" }

    function navigateTo(target) {
        pageParams.currentPage = target;
        page_loader.source = target;
    }

    /// Loads the intiial "page"
    Component.onCompleted:
    {
        navigateTo("qrc:///mainwindow.qml");
    }

}// end item Litdeco
