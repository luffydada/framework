/******************************************************************************
*    Copyright (C), 2015 by HappyTown                                         *
*    FileName:    ddmediaplayer_app.cpp
*    Author:      WangYing	                                             *
*    Description:                                                             *
*    History:                                                                 *
*      <author>          <time>          <version>          <description>     *
*        Xzj        2017-05-15 16:04      V1.0.0                build         *
*                                                                             *
******************************************************************************/
#include "stdafx.h"

ddMediaPlayerApp::ddMediaPlayerApp()
{
}

ddMediaPlayerApp::~ddMediaPlayerApp()
{
	ddGlobalInstance<ddMediaPlayerGstreamer>::release();
}

ddVoid ddMediaPlayerApp::onInitApp()
{
	ddGlobalInstance<ddMediaPlayerGstreamer>::instance();
}

ddUInt16 ddMediaPlayerApp::myCommand()
{
	return DDDEF_IOCOMMAND_MUSIC/* || DDDEF_IOCOMMAND_VIDEO || DDDEF_IOCOMMAND_IMAGE*/;
}

ddVoid ddMediaPlayerApp::onProtocol(ddCommand& cmd)
{
	dd_log_d("onProtocol,cmd:%d\n", cmd.command());
	DD_GLOBAL_INSTANCE_DO(ddMediaPlayerGstreamer, onProtocol(cmd));
}

