/******************************************************************************
*    Copyright (C), 2015 by HappyTown                                         *
*    FileName:    ddlauncher_main.cpp
*    Author:      WangYing	                                             *
*    Description:                                                             *
*    History:                                                                 *
*      <author>          <time>          <version>          <description>     *
*        Xzj        2017-05-15 15:44      V1.0.0                build         *
*                                                                             *
******************************************************************************/
#include "stdafx.h"

ddInt main(ddInt argc, ddChar* argv[])
{
	ddLauncherApp::startup("dd_launcher");
	ddLauncherApp app;
	return app.run();
}
