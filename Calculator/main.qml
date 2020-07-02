import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.2

Window {
    Connections{
        target: appHandler;
        onSignalSendBack:{
            messageDialog.title="Result";
            messageDialog.informativeText=result;
            messageDialog.visible=true;
        }
    }
    id: mainWindow;
    visible: true
    width: 640
    height: 480
    title: qsTr("Calculator")
    Column{
        anchors.centerIn: parent;
        anchors.margins: 10;
        spacing: 10;

        Label{
            text:"Enter your numbers and operation here...";

        }
            TextArea{
                id: textArea1;
                focus: true;
                background: Rectangle {
                    border.color: "black"
                }

            }

        TextArea {
            id: textArea2
            focus: true
//            anchors.right: parent
            background: Rectangle {
                border.color: "black"
            }
        }
        TextArea {
            id: textArea3
            focus: true
//            anchors.right: textArea1.right
            background: Rectangle {
                border.color: "black"
            }
        }


        Button{
            text: "Calculate!";
            onClicked: {
                appHandler.slotOperateMessage(textArea1.text, textArea2.text, textArea3.text);
            }
        }
    }
    MessageDialog{
        id: messageDialog;
        visible: false;
        modality: Qt.WindowModal;
    }
}
