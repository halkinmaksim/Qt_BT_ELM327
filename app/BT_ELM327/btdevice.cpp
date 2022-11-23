#include "btdevice.h"

#define __CLASS__               "BTDevice"

BTDevice::BTDevice(QObject *parent) : QObject(parent)
{
	qDebug("%s::%s(): Entered", __CLASS__, __FUNCTION__);

	m_deviceDiscoveryAgent = new QBluetoothDeviceDiscoveryAgent(this);
	m_deviceDiscoveryAgent->setLowEnergyDiscoveryTimeout(5000);

	localDevice = new QBluetoothLocalDevice();
	// Поиск устройств
	connect(m_deviceDiscoveryAgent, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),
				this, SLOT(deviceDiscovered(QBluetoothDeviceInfo)));
	// Ошибки во время обнаружения
	connect(m_deviceDiscoveryAgent, SIGNAL(error(QBluetoothDeviceDiscoveryAgent::Error)),
				this, SLOT(deviceDiscError(QBluetoothDeviceDiscoveryAgent::Error)));

	// Закончили поиск
	connect(m_deviceDiscoveryAgent, SIGNAL(finished()),
				this, SLOT(deviceScanFinished()));
	// Обновление ус-ва
/*	connect(m_deviceDiscoveryAgent, SIGNAL(deviceUpdated(QBluetoothDeviceInfo, QBluetoothDeviceInfo::Fields)),
				this, SLOT(deviceUpdated(QBluetoothDeviceInfo, QBluetoothDeviceInfo::Fields)));

	connect(localDevice, SIGNAL(hostModeStateChanged(QBluetoothLocalDevice::HostMode)),
			this, SLOT(hostModeStateChanged(QBluetoothLocalDevice::HostMode)));
			*/
}

BTDevice::~BTDevice()
{
	qDebug("%s::%s(): Entered", __CLASS__, __FUNCTION__);
	delete m_deviceDiscoveryAgent;
}

void BTDevice::StartDiscover()
{
	qDebug("%s::%s(): Entered", __CLASS__, __FUNCTION__);
	m_deviceDiscoveryAgent->start(QBluetoothDeviceDiscoveryAgent::ClassicMethod);
}

void BTDevice::deviceDiscovered(const QBluetoothDeviceInfo &device)
{
	qDebug("%s::%s(): Entered", __CLASS__, __FUNCTION__);
	qDebug() << "Found new device:" << device.name() << '(' << device.address().toString() << ')';

	qDebug() << "coreConfigurations:" << device.coreConfigurations();
	qDebug() << "deviceUuid:" << device.deviceUuid();

	//emit setLogoutText("Found new device:" + device.name() + '(' + device.address().toString() + ')');



	QBluetoothLocalDevice::Pairing pairingStatus = localDevice->pairingStatus(device.address());
	qDebug()  << pairingStatus;

/*
	if (items.empty()) {
		QListWidgetItem *item = new QListWidgetItem(label);
		QBluetoothLocalDevice::Pairing pairingStatus = localDevice->pairingStatus(info.address());
		if (pairingStatus == QBluetoothLocalDevice::Paired || pairingStatus == QBluetoothLocalDevice::AuthorizedPaired )
			item->setForeground(QColor(Qt::green));
		else
			item->setForeground(QColor(Qt::black));

		ui->list->addItem(item);
	}*/


			/*
	if (device.coreConfigurations() & QBluetoothDeviceInfo::LowEnergyCoreConfiguration) {
		auto d = new DeviceInfo(device);
		devices.append(d);
	}
			*/

}

void BTDevice::deviceDiscError(QBluetoothDeviceDiscoveryAgent::Error error)
{
	qDebug("%s::%s(): Entered", __CLASS__, __FUNCTION__);
	qDebug() << error;
}

void BTDevice::deviceScanFinished()
{
	qDebug("%s::%s(): Entered", __CLASS__, __FUNCTION__);
	//qDebug() << "---------------deviceScanFinished--------------";
	//emit setLogoutText("---------------deviceScanFinished--------------");
	//emit devicesUpdated();
	//if(findRingo2)
	//{
//		emit finishedSearchDevice(true);
//	}
//	else
//	{
//		emit finishedSearchDevice(false);
	//	}
}

void BTDevice::deviceUpdated(const QBluetoothDeviceInfo &info, QBluetoothDeviceInfo::Fields updatedFields)
{
	qDebug("%s::%s(): Entered", __CLASS__, __FUNCTION__);
	qDebug() << "Device " << info.name() << "update fields" << updatedFields;
}
