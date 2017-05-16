/******************************************************************************
*    Copyright (C), 2015 by HappyTown                                         *
*    FileName:    dddae_music_device.h
*    Author:      WangYing	                                             *
*    Description:                                                             *
*    History:                                                                 *
*      <author>          <time>          <version>          <description>     *
*        Xzj        2017-05-15 17:38      V1.0.0                build         *
*                                                                             *
******************************************************************************/
#ifndef dddae_music_device_h
#define dddae_music_device_h

class ddMusicDevice: public ddDevice, public ddTimer::interface {
public:
	enum {
		DDENUM_IOCODE_MUSIC_A = DDDEF_IOCODE_MUSIC_START,
		DDENUM_IOCODE_MUSIC_OK,
		DDENUM_IOCODE_MUSIC_B = DDDEF_IOCODE_MUSIC_END
	};
	ddMusicDevice();
	~ddMusicDevice();
	virtual emDeviceId deviceId();
	virtual ddBool isMyCommand(ddUInt16 iocmd);
	virtual ddBool isMyProtocol(ddUInt16 iocmd);
	virtual ddVoid onIoctl(ddUInt16 iocmd, ddCPointer pin, ddUInt16 uin, ddPointer pout, ddUInt16 uout);
	virtual ddVoid onMessage(ddUInt32 msg, ddUInt32& wParam, ddUInt32& lParam);
	virtual ddVoid onProtocol(ddCommand& cmd);
	virtual ddVoid onTimer(ddTimer* pTimer);
	
	ddVoid handleIocmd_testIsOk();

private:
	ddTimer m_testTimer;
};
#endif // dddae_music_device_h

