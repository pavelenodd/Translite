import QtQuick
import QtQuick.Controls

Window {
    width: 800
    height: 400

    visible: true
    title: "Translate"

    Column {
        anchors.centerIn: parent
        spacing: 10

        Row {
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 10
            ScrollView {
                width: 200
                height: 200
                TextArea {
                    id: leftField
                    placeholderText: "Поле ввода"
                    wrapMode: TextArea.Wrap
                }
            }
            ScrollView {
                width: 500
                height: 200
                TextArea {
                    id: rightField
                    wrapMode: TextArea.Wrap
                    readOnly: true
                }
            }
        }

        Button {
            text: "Translate"
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: {
                translator.SetQueryText(leftField.text);
                translator.Transliterate(comboBox.currentIndex);
                rightField.text = translator.GetResultText();
            }
        }

        ComboBox {
            id: comboBox
            model: ["Both Directions", "To Russian", "To English"]
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}