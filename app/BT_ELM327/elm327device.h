#ifndef ELM327DEVICE_H
#define ELM327DEVICE_H

#include <QObject>

#include "btdevice.h"

class ELM327Device : public QObject
{
	Q_OBJECT
public:
	explicit ELM327Device(QObject *parent = nullptr);
	~ELM327Device();


public slots:
	void startScanDevice();
	void startScanDeviceService();
signals:

protected:
	BTDevice* m_bt_device;

};

#endif // ELM327DEVICE_H
