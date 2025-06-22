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
                width: 100
                onTextChanged:  {
                    controller.setCVal  (celsiusInput.text)
                    // if (focus) {
                    //     let c = parseFloat(text)
                    //     if (!isNaN(c)) {
                    //         fahrenheitInput.text = (c * 9/5 + 32).toFixed(2)
                    //         kelvinInput.text = (c + 273.15).toFixed(2)
                    //     }
                    // }
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
                width: 100
                onTextChanged: {
                    controller.setKVal(fahrenheitInput.text)
                    // if (focus) {
                    //     let f = parseFloat(text)
                    //     if (!isNaN(f)) {
                    //         celsiusInput.text = ((f - 32) * 5/9).toFixed(2)
                    //         kelvinInput.text = (((f - 32) * 5/9) + 273.15).toFixed(2)
                    //     }
                    // }
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
                width: 100
                onTextChanged: {
                    controller.setFVal(kelvinInput.text)
                    // if (focus) {
                    //     let k = parseFloat(text)
                    //     if (!isNaN(k)) {
                    //         celsiusInput.text = (k - 273.15).toFixed(2)
                    //         fahrenheitInput.text = ((k - 273.15) * 9/5 + 32).toFixed(2)
                    //     }
                    // }
                }
            }
        }
    }
}
