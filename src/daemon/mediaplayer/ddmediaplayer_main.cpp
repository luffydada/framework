/******************************************************************************
*    Copyright (C), 2015 by HappyTown                                         *
*    FileName:    dddae_main.cpp
*    Author:      WangYing	                                             *
*    Description:                                                             *
*    History:                                                                 *
*      <author>          <time>          <version>          <description>     *
*        Xzj        2017-05-15 15:53      V1.0.0                build         *
*                                                                             *
******************************************************************************/
#include "stdafx.h"

ddInt main(ddInt argc, ddChar* argv[])
{
	ddMediaPlayerApp::startup("dd_mediaplayer");
	ddMediaPlayerApp app;
	return app.run();
}
