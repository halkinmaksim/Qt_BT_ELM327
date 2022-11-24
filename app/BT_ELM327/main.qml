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
        x: 85
        y: 121
        text: "Search"
        onClicked: {
            ELM327Device.startScanDevice();
        }
    }

    Button {
        id: buttonSearchService
        x: 224
        y: 121
        text: qsTr("Serch Service")
        onClicked: {
            ELM327Device.startScanDeviceService();
        }
    }
}
