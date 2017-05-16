/******************************************************************************
*    Copyright (C), 2015 by HappyTown                                         *
*    FileName:    ddlauncher_app.cpp
*    Author:      WangYing	                                             *
*    Description:                                                             *
*    History:                                                                 *
*      <author>          <time>          <version>          <description>     *
*        Xzj        2017-05-15 15:43      V1.0.0                build         *
*                                                                             *
******************************************************************************/
#include "stdafx.h"

ddLauncherApp::ddLauncherApp()
: m_testTimer(this)
{
}

ddLauncherApp::~ddLauncherApp()
{
}

ddVoid ddLauncherApp::onInitApp()
{
	dd_log_d("onInitApp\n");
	m_testTimer.setTimer(100);
}

ddVoid ddLauncherApp::onTimer(ddTimer* pTimer)
{
	if ( &m_testTimer == pTimer ) {
		ddChar path[DD_MAXPATH] = {0};
		if ( ddProcess::getModulePath(path, DD_MAXPATH) ) {
			strcat(path, "dd_mediaplayer");
			ddBool ret = ddProcess::createProcess(path, nil);
			dd_log_d("onInitApp,startup mediaplayer,name:%s,ret:%d\n", path, ret);
		}
		dd_log_d("onTimer,test is Ok,ret:%d\n", ddMusic::testIsOk(2000));
	}
}

ddVoid ddLauncherApp::onMusic_testOk(ddBool isOk)
{
	dd_log_d("onMusic_testOk,isOk:%d\n", isOk);
}

