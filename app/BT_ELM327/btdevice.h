#ifndef BTDEVICE_H
#define BTDEVICE_H

#include <QObject>
#include <QBluetoothServiceDiscoveryAgent>
#include <QBluetoothDeviceDiscoveryAgent>
#include <qbluetoothlocaldevice.h>
#include <QtBluetooth/qbluetoothserviceinfo.h>
#include <QtBluetooth/qbluetoothsocket.h>

/*
 * Discovered service on "OBD II" "AA:BB:CC:11:22:33"
	Service name: "Port"
	Description: ""
	Provider: ""
	L2CAP protocol service multiplexer: 0
	RFCOMM server channel: 1
got click "OBD II Port"
Connecting to service 2 "Port" on "OBD II"
*/

class BTDevice : public QObject
{
	Q_OBJECT
public:
	explicit BTDevice(QObject *parent = nullptr);
	~BTDevice();

	void StartDiscover();
	void ConnectDevice();

signals:
	void messageReceived(const QString &sender, const QString &message);
	void connected(const QString &name);
	void disconnected();
	void socketErrorOccurred(const QString &errorString);

public slots:
	void deviceDiscovered(const QBluetoothDeviceInfo &device);
	void deviceDiscError(QBluetoothDeviceDiscoveryAgent::Error error);
	void deviceScanFinished();
	void deviceUpdated(const QBluetoothDeviceInfo &info, QBluetoothDeviceInfo::Fields updatedFields);
//	service slots
	void serviceDiscovered(const QBluetoothServiceInfo &info);
	void serviceDiscoveryFinished();

//	socket slots
	void readSocket();
	void connected();
	void disconnectedSocket();
	void onSocketErrorOccurred(QBluetoothSocket::SocketError);

protected:
	QBluetoothDeviceDiscoveryAgent *m_deviceDiscoveryAgent;
	QBluetoothServiceDiscoveryAgent *m_serviceDiscoveryAgent;
	//QMap<QListWidgetItem*, QBluetoothServiceInfo> m_discoveredServices;
	QList<QBluetoothServiceInfo> m_discoveredServices;
	QBluetoothLocalDevice *localDevice;

	QString m_odb_DeviceName;
	QBluetoothSocket *socket = nullptr;
	//DeviceInfo currentDevice;

};

#endif // BTDEVICE_H
