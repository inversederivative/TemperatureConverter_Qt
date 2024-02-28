import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    width: 400
    height: 200

    Text {
        id: inputTextName
        text: "      Temperature in °C:"
        font.pointSize: 18
        anchors.top: parent.top
        color: "#FFFFFF"
        topPadding: 300
        bottomPadding: 10
    }

    TextField {
        id: inputField
        font.pointSize: 14
        width: parent.width - 20
        height: 50 // Adjust height as needed
        color: "#FFFFFF"
        placeholderTextColor : "#FFFFFF"
        anchors.top: inputTextName.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        placeholderText: "Enter temperature in °C"
        validator: DoubleValidator {}
        wrapMode: TextArea.NoWrap // Disable wrapping
    }

    Button {
        id: convertButton
        text: "Convert"
        font.pointSize: 12
        width: parent.width - 20
        height: 50
        anchors.top: inputField.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        onClicked: {
            // Emit signal to notify C++ side to convert temperature
            temperatureConverter.convertTemperatureFromCelsiusToKelvin(inputField.text)
        }
    }

    Text {
        id: resultText
        text: ""
        anchors.top: convertButton.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        color: "#FFFFFF"
        font.pointSize: 18
        bottomPadding: 10
    }

    Button {
        id: homepageButton
        text: "Back to Homepage"
        font.pointSize: 12
        height: 50
        onClicked: {
            mainWindow.loadPage("qml/HomePage.qml"); // Load the HomePage.qml page
        }
        anchors {
            top: resultText.bottom
            horizontalCenter: parent.horizontalCenter
        }
    }

    Connections {
        target: temperatureConverter
        function onTemperatureConvertedFromCelsiusToKelvin(kelvinTemperature) {
            // Update the displayed Fahrenheit temperature
            resultText.text = "Result: " + kelvinTemperature.toFixed(2) + "°K"
        }
    }
}
