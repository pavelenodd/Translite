import QtQuick
import QtQuick.Controls

Window {
    width: 400
    height: 300

    visible: true
    title: "Translate"

    Column {
        anchors.centerIn: parent
        spacing: 10

        Row {
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 10
            TextField {
                
                id: leftField
                placeholderText: "Поле ввода"
                width: 150
            }
            TextArea {
                id: rightField
                width: 150
                readOnly: true
            }
        }

        Button {
            text: "Translate"
            anchors.horizontalCenter: parent.horizontalCenter

        }

        ComboBox {
            id: comboBox
            model: ["Both Directions", "To Russian", "To English"]
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}