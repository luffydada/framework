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
	dd_log_d("ddMediaPlayerGstreamer init\n");
}

ddMediaPlayerGstreamer::~ddMediaPlayerGstreamer()
{
	dd_log_d("ddMediaPlayerGstreamer deinit\n");
}

ddVoid ddMediaPlayerGstreamer::onProtocol(ddCommand& cmd)
{
	dd_log_d("onProtocol,command:%d,length:%d\n", cmd.command(), cmd.length());
	switch(cmd[0]) {
		case 0: {
			ddInt in = 0;
			memcpy(&in, cmd.data() + 1, sizeof(in));
			dd_log_d("onProtocol,test data:%d\n", in);
			handleTestData();
		} break;
		default: break;
	}
}

ddVoid ddMediaPlayerGstreamer::handleTestData()
{
	ddCommand dataCmd(this, DDDEF_IOCOMMAND_MUSIC, DDENUM_COMMAND_SERVICE, 1);
	dataCmd[0] = 0;
	ddInt testData = 8888;
	memcpy(dataCmd.data() + 1, &testData, sizeof(ddInt));
	dataCmd.length() += sizeof(ddInt);
	dataCmd.download();
}

