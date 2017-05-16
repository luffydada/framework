/******************************************************************************
*    Copyright (C), 2015 by HappyTown                                         *
*    FileName:    dddae_music_device.cpp
*    Author:      WangYing	                                             *
*    Description:                                                             *
*    History:                                                                 *
*      <author>          <time>          <version>          <description>     *
*        Xzj        2017-05-15 17:48      V1.0.0                build         *
*                                                                             *
******************************************************************************/
#include "stdafx.h"

ddMusicDevice::ddMusicDevice()
: m_testTimer(this)
{
	m_testTimer.setTimer(1000);
}

ddMusicDevice::~ddMusicDevice()
{
}

emDeviceId ddMusicDevice::deviceId()
{
   	return DDENUM_DEVICEID_MUSIC;
}

ddBool ddMusicDevice::isMyCommand(ddUInt16 iocmd)
{
	return iocmd >= DDENUM_IOCODE_MUSIC_A && iocmd <= DDENUM_IOCODE_MUSIC_B;
}

ddBool ddMusicDevice::isMyProtocol(ddUInt16 iocmd)
{
	return iocmd == DDDEF_IOCOMMAND_MUSIC; 
}

ddVoid ddMusicDevice::onIoctl(ddUInt16 iocmd, ddCPointer pin, ddUInt16 uin, ddPointer pout, ddUInt16 uout)
{
	switch ( iocmd ) {
		case DDENUM_IOCODE_MUSIC_OK:
			if ( uin == sizeof(ddInt) ) {
				dd_log_d("onIoctl,test is ok,in:%d\n", *(ddInt *)pin);
				if ( uout == sizeof(ddInt) ) {
					*(ddInt *)pout = 2017;
				}
				handleIocmd_testIsOk();
			} break;
		default: break;
	}
}

ddVoid ddMusicDevice::onMessage(ddUInt32 msg, ddUInt32& wParam, ddUInt32& lParam)
{
}

ddVoid ddMusicDevice::onProtocol(ddCommand& cmd)
{
	switch ( cmd[0] ) {
		case 0: {
			ddInt in = 0;
			memcpy(&in, cmd.data() + 1, sizeof(in));
			dd_log_d("onProtocol,test data:%d\n", in);
		} break;
		default: break;
	}
}

ddVoid ddMusicDevice::onTimer(ddTimer* pTimer)
{
	if ( pTimer == &m_testTimer ) {
		ddCommand dataCmd(this, DDDEF_IOCOMMAND_MUSIC, DDENUM_COMMAND_SERVICE, 1);
		dataCmd[0] = 0;
		ddInt testData = 7777;
		memcpy(dataCmd.data() + 1, &testData, sizeof(ddInt));
		dataCmd.length() += sizeof(ddInt);
		dataCmd.download();
	}
}

ddVoid ddMusicDevice::handleIocmd_testIsOk()
{
	ddCommand uiCmd(this, DDENUM_IOCODE_MUSIC_OK, DDENUM_COMMAND_APP, 1);
	uiCmd[0] = yes;
	uiCmd.commit();
}

