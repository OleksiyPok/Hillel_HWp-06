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
                onTextChanged:  {
                    controller.cValChanged  (celsiusInput.text)
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
                onTextChanged: {
                    controller.fValChanged(fahrenheitInput.text)
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
                onTextChanged: {
                    controller.kValChanged(kelvinInput.text)
                }
            }
        }
    }
}
