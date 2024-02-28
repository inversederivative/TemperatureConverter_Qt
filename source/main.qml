import QtQuick 2.15
import QtQuick.Controls 2.15
import "ScaleFactor.js" as ScaleFactor

ApplicationWindow {
    id: mainWindow
    visible: true
    // Size of an average Smartphone
    width: 360
    height: 800

    function loadPage(pageUrl) {
        pageLoader.source = pageUrl;
    }

    Loader {
        id: pageLoader
        anchors.fill: parent
        source: "qml/HomePage.qml" // Initial page with buttons for navigation
    }
}
