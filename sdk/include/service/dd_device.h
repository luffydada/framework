/******************************************************************************
*    Copyright (C), 2015 by HappyTown                                         *
*    FileName:    dd_device.h
*    Author:      WangYing	                                             *
*    Description:                                                             *
*    History:                                                                 *
*      <author>          <time>          <version>          <description>     *
*        Xzj        2016-12-08 11:08      V1.0.0                build         *
*                                                                             *
******************************************************************************/
#ifndef dd_device_h
#define dd_device_h

typedef enum {
	DDENUM_DEVICEID_START = 0,
	DDENUM_DEVICEID_RADIO,
	DDENUM_DEVICEID_BLUETOOTH,
	DDENUM_DEVICEID_MUSIC,
	DDENUM_DEVICEID_VIDEO,
	DDENUM_DEVICEID_IMAGE,
	DDENUM_DEVICEID_END
} emDeviceId;

#define DDDEF_IOCOMMAND_PROTOCOL		1
#define DDDEF_IOCOMMAND_RADIO			100
#define DDDEF_IOCOMMAND_BLUETOOTH		200
#define DDDEF_IOCOMMAND_MUSIC			300
#define DDDEF_IOCOMMAND_VIDEO			400
#define DDDEF_IOCOMMAND_IMAGE			500

#define DDDEF_IOCODE_RADIO_START		DDDEF_IOCOMMAND_RADIO
#define DDDEF_IOCODE_RADIO_END			(DDDEF_IOCODE_RADIO_START + 99)
#define DDDEF_IOCODE_BLUETOOTH_START	DDDEF_IOCOMMAND_BLUETOOTH
#define DDDEF_IOCODE_BLUETOOTH_END		(DDDEF_IOCOMMAND_BLUETOOTH + 99)
#define DDDEF_IOCODE_MUSIC_START		DDDEF_IOCOMMAND_MUSIC
#define DDDEF_IOCODE_MUSIC_END			(DDDEF_IOCOMMAND_MUSIC + 99)
#define DDDEF_IOCODE_VIDEO_START		DDDEF_IOCOMMAND_VIDEO
#define DDDEF_IOCODE_VIDEO_END			(DDDEF_IOCOMMAND_VIDEO + 99)
#define DDDEF_IOCODE_IMAGE_START		DDDEF_IOCOMMAND_IMAGE
#define DDDEF_IOCODE_IMAGE_END			(DDDEF_IOCOMMAND_IMAGE + 99)

class ddDevice : public ddCommand::interface {
public:
	ddDevice();
	~ddDevice();
	virtual emDeviceId deviceId();
	virtual ddBool isMyCommand(ddUInt16 iocmd);
	virtual ddBool isMyProtocol(ddUInt16 iocmd);
	virtual ddVoid onIoctl(ddUInt16 iocmd, ddCPointer pin, ddUInt16 uin, ddPointer pout, ddUInt16 uout);
	virtual ddVoid onMessage(ddUInt32 msg, ddUInt32& wParam, ddUInt32& lParam);
	virtual ddVoid onProtocol(ddCommand& cmd);

	/* 实现ddCommand::interface的接口 */
	ddVoid onCommit(ddpCByte data, ddUInt16 len);
	ddVoid onDownload(ddpCByte data, ddUInt16 len);

	/* 自定义函数 */
	ddVoid send(ddUInt32 msg, ddUInt32& wParam, ddUInt32& lParam, emDeviceId deviceId);
	ddVoid broadcast(ddUInt32 msg, ddUInt32 wParam, ddUInt32 lParam);
};
#endif // dd_device_h

