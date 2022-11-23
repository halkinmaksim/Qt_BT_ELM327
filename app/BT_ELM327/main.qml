import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Button{
        id: buttSearch
        x: 221
        y: 162
        text: "Search"
        onClicked: {
            ELM327Device.startScanDevice();
        }
    }
}
