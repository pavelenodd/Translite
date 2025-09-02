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
            TextField {
                
                id: leftField
                placeholderText: "Поле ввода"
                width: 200  
                height: 40
                wrapMode: TextArea.Wrap
                onTextChanged: {
                    height = Math.max(5, text.length/2 );
                }
            }
            TextArea {
                id: rightField
                width: 500
                wrapMode: TextArea.Wrap
                readOnly: true
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