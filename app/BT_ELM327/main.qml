import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Button{
        id: buttSearch
        x: 60
        y: 42
        text: "Search"
        onClicked: {
            ELM327Device.startScanDevice();
        }
    }

    Button {
        id: buttonSearchService
        x: 194
        y: 42
        text: qsTr("Serch Service")
        onClicked: {
            ELM327Device.startScanDeviceService();
        }
    }

    Button {
        id: buttonATZ
        x: 60
        y: 108
        width: 50
        height: 25
        text: qsTr("ATZ")
    }

    Button {
        id: buttonATAL
        x: 60
        width: 50
        height: 25
        text: qsTr("ATAL")
        anchors.top: buttonATZ.bottom
        anchors.topMargin: 2
    }

    Button {
        id: buttonATCAF
        x: 60
        width: 50
        height: 25
        text: qsTr("ATCAF")
        anchors.top: buttonATAL.bottom
        anchors.topMargin: 2
    }

    TextInput {
        id: textInput
        y: 167
        width: 60
        height: 20
        text: qsTr("0")
        anchors.verticalCenter: buttonATCAF.verticalCenter
        anchors.left: buttonATCAF.right
        font.pixelSize: 12
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        selectedTextColor: "#c3c3c3"
        anchors.leftMargin: 20
    }

    Button {
        id: buttonATV
        x: 60
        y: 218
        width: 50
        height: 25
        text: qsTr("ATV")
        anchors.top: buttonATCAF.bottom
        anchors.topMargin: 2
    }

    Button {
        id: buttonATBI
        x: 60
        y: 234
        width: 50
        height: 25
        text: qsTr("ATBI")
        anchors.top: buttonATV.bottom
        anchors.topMargin: 2
    }

    Button {
        id: buttonATSP
        x: 60
        y: 228
        width: 50
        height: 25
        text: qsTr("ATSP")
        anchors.top: buttonATBI.bottom
        anchors.topMargin: 2
    }

    TextInput {
        id: textInput1
        x: 130
        y: 194
        width: 60
        height: 20
        text: qsTr("0")
        anchors.verticalCenter: buttonATCAF.verticalCenter
        anchors.left: buttonATCAF.right
        font.pixelSize: 12
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        selectedTextColor: "#c3c3c3"
        anchors.leftMargin: 20
    }
}
