#ifndef BTDEVICE_H
#define BTDEVICE_H

#include <QObject>
#include <QBluetoothServiceDiscoveryAgent>
#include <QBluetoothDeviceDiscoveryAgent>
#include <qbluetoothlocaldevice.h>

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

signals:


public slots:
	void deviceDiscovered(const QBluetoothDeviceInfo &device);
	void deviceDiscError(QBluetoothDeviceDiscoveryAgent::Error error);
	void deviceScanFinished();
	void deviceUpdated(const QBluetoothDeviceInfo &info, QBluetoothDeviceInfo::Fields updatedFields);

protected:
	QBluetoothDeviceDiscoveryAgent *m_deviceDiscoveryAgent;
	QBluetoothServiceDiscoveryAgent *m_serviceDiscoveryAgent;
	QBluetoothLocalDevice *localDevice;
	//DeviceInfo currentDevice;

};

#endif // BTDEVICE_H
