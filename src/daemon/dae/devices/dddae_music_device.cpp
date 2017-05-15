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
{
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
}

ddVoid ddMusicDevice::onMessage(ddUInt32 msg, ddUInt32& wParam, ddUInt32& lParam)
{
}

ddVoid ddMusicDevice::onProtocol(ddCommand& cmd)
{
}

