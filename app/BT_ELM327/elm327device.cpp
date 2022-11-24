#include "elm327device.h"

#define __CLASS__               "ELM327Device"

ELM327Device::ELM327Device(QObject *parent) : QObject(parent)
{
	qDebug("%s::%s(): Entered", __CLASS__, __FUNCTION__);

	m_bt_device = new BTDevice(this);
}

ELM327Device::~ELM327Device()
{
	qDebug("%s::%s(): Entered", __CLASS__, __FUNCTION__);
	delete m_bt_device;
}

void ELM327Device::startScanDevice()
{
	qDebug("%s::%s(): Entered", __CLASS__, __FUNCTION__);
	m_bt_device->StartDiscover();
}

void ELM327Device::startScanDeviceService()
{
	m_bt_device->ConnectDevice();
}
