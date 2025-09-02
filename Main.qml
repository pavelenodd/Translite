import QtQuick
import QtQuick.Controls

Window {
    id: window
    width: 800
    height: 400

    visible: true
    title: "Translate"

    Column {
        anchors.fill: parent
        spacing: 10

        Row {
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 10
            height: parent.height - 100  // Динамическая высота, оставляя место для кнопки и combo
            ScrollView {
                spacing: 10
                width: window.width * 0.25  // Динамическая ширина, ~25% от ширины окна
                height: parent.height
                TextArea {
                    id: leftField
                    placeholderText: "Поле ввода"
                    wrapMode: TextArea.Wrap
                }
            }
            ScrollView {
                spacing: 10
                width: window.width * 0.625  // Динамическая ширина, ~62.5% от ширины окна
                height: parent.height
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