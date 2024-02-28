import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Item {
    width: 400
    height: 200

    anchors.centerIn: parent

    ColumnLayout {
        anchors.horizontalCenter: parent.horizontalCenter // Center the ColumnLayout horizontally
        anchors.verticalCenter: parent.verticalCenter
        spacing: 10 // Adjust spacing between buttons if needed

        Button {
            id: fahrenheitToCelsius
            text: "Fahrenheit to Celsius"
            font.pointSize: 12
            Layout.minimumWidth: 200 // Set the minimum width of the button
            Layout.minimumHeight: 50 // Set the minimum height of the button
            onClicked: {
                mainWindow.loadPage("qml/FtoC.qml"); // Load the FtoC page
            }
        }

        Button {
            id: celsiusToFahrenheit
            text: "Celsius to Fahrenheit"
            font.pointSize: 12
            Layout.minimumWidth: 200 // Set the minimum width of the button
            Layout.minimumHeight: 50 // Set the minimum height of the button
            onClicked: {
                mainWindow.loadPage("qml/CtoF.qml"); // Load the CtoF page
            }
        }
        Button {
            id: fahrenheitToKelvin
            text: "Fahrenheit to Kelvin"
            font.pointSize: 12
            Layout.minimumWidth: 200 // Set the minimum width of the button
            Layout.minimumHeight: 50 // Set the minimum height of the button
            onClicked: {
                mainWindow.loadPage("qml/FtoK.qml"); // Load the CtoF page
            }
        }
        Button {
            id: celsiusToKelvin
            text: "Celsius to Kelvin"
            font.pointSize: 12
            Layout.minimumWidth: 200 // Set the minimum width of the button
            Layout.minimumHeight: 50 // Set the minimum height of the button
            onClicked: {
                mainWindow.loadPage("qml/CtoK.qml"); // Load the CtoF page
            }
        }
        Button {
            id: kelvinToFahrenheit
            text: "Kelvin to Fahrenheit"
            font.pointSize: 12
            Layout.minimumWidth: 200 // Set the minimum width of the button
            Layout.minimumHeight: 50 // Set the minimum height of the button
            onClicked: {
                mainWindow.loadPage("qml/KtoF.qml"); // Load the CtoF page
            }
        }
        Button {
            id: kelvinToCelsius
            text: "Kelvin to Celsius"
            font.pointSize: 12
            Layout.minimumWidth: 200 // Set the minimum width of the button
            Layout.minimumHeight: 50 // Set the minimum height of the button
            onClicked: {
                mainWindow.loadPage("qml/KtoC.qml"); // Load the CtoF page
            }
        }
    }
}
