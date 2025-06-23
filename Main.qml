import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15


ApplicationWindow {
    visible: true
    width: 300
    height: 200
    title: "Temperature Converter"
    color: "lightgrey"


    Column {
        anchors.centerIn: parent
        spacing: 15

        Row {
            spacing: 20
            Label {
                text: "Celsius"
                width: 100
                horizontalAlignment: Text.AlignRight
            }
            TextField {
                id: celsiusInput
                placeholderText:'celsius'
                width: 100
                text: model.cVal
                onTextEdited:{
                    controller.cValChanged  (celsiusInput.text)
                }
                background: Rectangle {
                    id: celsiusInputBackground
                    implicitHeight: celsiusInput.height
                    implicitWidth: celsiusInput.width

                    border.color: "transparent"
                    border.width: 2
                }
            }
        }

        Row {
            spacing: 20
            Label {
                text: "Fahrenheit"
                width: 100
                horizontalAlignment: Text.AlignRight
            }
            TextField {
                id: fahrenheitInput
                placeholderText:'fahrenheit'
                width: 100
                text: model.fVal
                onTextEdited: {
                    controller.fValChanged(fahrenheitInput.text)
                }
                background: Rectangle {
                    id: fahrenheitInputBackground
                    implicitHeight: fahrenheitInput.height
                    implicitWidth: fahrenheitInput.width

                    border.color: "transparent"
                    border.width: 2
                }

            }
        }

        Row {
            spacing: 20
            Label {
                text: "Kelvin"
                width: 100
                horizontalAlignment: Text.AlignRight
            }
            TextField {
                id: kelvinInput
                placeholderText:'kelvin'
                width: 100
                 text: model.kVal
                onTextEdited: {
                    controller.kValChanged(kelvinInput.text)
                }
                background: Rectangle {
                    id: kelvinInputBackground
                    implicitHeight: kelvinInput.height
                    implicitWidth: kelvinInput.width

                    border.color: "transparent"
                    border.width: 2
                }

            }
        }
    }

    Connections {
        target: model
        function onCValidChanged(cValid){
            celsiusInputBackground.border.color = cValid ? "transparent" : "red"
        }

        function onfValidChanged(fValid){
            fahrenheitInputBackground.border.color = fValid ? "transparent" : "red"
        }

        function onKValidChanged(kValid){
            kelvinInputBackground.border.color = kValid ? "transparent" : "red"
        }
    }
}
