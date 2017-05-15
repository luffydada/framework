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

ddMediaPlayerGstreamer::ddMediaPlayerGstreamer()
{
}

ddMediaPlayerGstreamer::~ddMediaPlayerGstreamer()
{
}

ddVoid ddMediaPlayerGstreamer::onProtocol(ddCommand& cmd)
{
	dd_log_d("onProtocol,command:%d,length:%d\n", cmd.command(), cmd.length());
}

