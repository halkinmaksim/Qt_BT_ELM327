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
/*
 * \connect(m_deviceDiscoveryAgent, SIGNAL(deviceUpdated(QBluetoothDeviceInfo, QBluetoothDeviceInfo::Fields)),
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

void BTDevice::ConnectDevice()
{

	//m_discoveryAgent = new QBluetoothServiceDiscoveryAgent(localAdapter);
	//m_serviceDiscoveryAgent = new QBluetoothServiceDiscoveryAgent();
	m_serviceDiscoveryAgent = new QBluetoothServiceDiscoveryAgent(QBluetoothAddress());


	connect(m_serviceDiscoveryAgent, SIGNAL(serviceDiscovered(QBluetoothServiceInfo)),
			this, SLOT(serviceDiscovered(QBluetoothServiceInfo)));
	connect(m_serviceDiscoveryAgent, SIGNAL(finished()), this, SLOT(serviceDiscoveryFinished()));
	connect(m_serviceDiscoveryAgent, SIGNAL(canceled()), this, SLOT(serviceDiscoveryFinished()));
	m_serviceDiscoveryAgent->start(QBluetoothServiceDiscoveryAgent::FullDiscovery);
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

void BTDevice::serviceDiscovered(const QBluetoothServiceInfo &serviceInfo)
{
	qDebug("%s::%s(): Entered", __CLASS__, __FUNCTION__);

	qDebug() << "Discovered service on"
			 << serviceInfo.device().name() << serviceInfo.device().address().toString();
	qDebug() << "\tService name:" << serviceInfo.serviceName();
	qDebug() << "\tDescription:"
			 << serviceInfo.attribute(QBluetoothServiceInfo::ServiceDescription).toString();
	qDebug() << "\tProvider:"
			 << serviceInfo.attribute(QBluetoothServiceInfo::ServiceProvider).toString();
	qDebug() << "\tL2CAP protocol service multiplexer:"
			 << serviceInfo.protocolServiceMultiplexer();
	qDebug() << "\tRFCOMM server channel:" << serviceInfo.serverChannel();

	const QBluetoothAddress address = serviceInfo.device().address();
	/*for (const QBluetoothServiceInfo &info : qAsConst(m_discoveredServices)) {
		qDebug() << "\tinfo.device().address():" << info.device().address();
		//if (info.device().address() == address)
			//return;
	}*/

	QString remoteName;
	if (serviceInfo.device().name().isEmpty())
	{
		remoteName = address.toString();
	}
	else
	{
		remoteName = serviceInfo.device().name();
	}



	qDebug() << "\tremoteName:" << remoteName;

	if(remoteName.contains("OBD"))
	{
		// connect
		m_odb_DeviceName = remoteName;
	}

/*
	QListWidgetItem *item =
		new QListWidgetItem(QString::fromLatin1("%1 %2").arg(remoteName,
															 serviceInfo.serviceName()));

	m_discoveredServices.insert(item, serviceInfo);
	ui->remoteDevices->addItem(item);
	*/
}

void BTDevice::serviceDiscoveryFinished()
{
	qDebug("%s::%s(): Entered", __CLASS__, __FUNCTION__);

	qDebug("m_odb_DeviceName : %s", qPrintable(m_odb_DeviceName));
	//ui->status->setText(tr("Select the chat service to connect to."));
}

void BTDevice::readSocket()
{
	qDebug("%s::%s(): Entered", __CLASS__, __FUNCTION__);
	if (!socket)
		return;

	while (socket->canReadLine()) {
		QByteArray line = socket->readLine();
		qDebug() << line;
		//emit messageReceived(socket->peerName(), QString::fromUtf8(line.constData(), line.length()));
	}
}

void BTDevice::connected()
{
	qDebug("%s::%s(): Entered", __CLASS__, __FUNCTION__);
	qDebug() << "socket->peerName(): " << socket->peerName();
	//emit connected(socket->peerName());
}

void BTDevice::onSocketErrorOccurred(QBluetoothSocket::SocketError error)
{
	qDebug("%s::%s(): Entered", __CLASS__, __FUNCTION__);
	if (error == QBluetoothSocket::NoSocketError)
		return;

	//QMetaEnum metaEnum = QMetaEnum::fromType<QBluetoothSocket::SocketError>();
	//QString errorString = socket->peerName() + QLatin1Char(' ')
		//	+ metaEnum.valueToKey(error) + QLatin1String(" occurred");

	//emit socketErrorOccurred(errorString);
}
