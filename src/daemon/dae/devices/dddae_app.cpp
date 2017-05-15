/******************************************************************************
*    Copyright (C), 2015 by HappyTown                                         *
*    FileName:    dddae_app.cpp
*    Author:      WangYing	                                             *
*    Description:                                                             *
*    History:                                                                 *
*      <author>          <time>          <version>          <description>     *
*        Xzj        2017-05-15 15:54      V1.0.0                build         *
*                                                                             *
******************************************************************************/
#include "stdafx.h"

ddDaeApp::ddDaeApp()
{
}

ddDaeApp::~ddDaeApp()
{
	ddGlobalInstance<ddDevManager>::release();
	ddGlobalInstance<ddMusicDevice>::release();
}

ddVoid ddDaeApp::onInitApp()
{
	dd_log_d("onInitApp\n");
	ddGlobalInstance<ddDevManager>::instance();
	DD_GLOBAL_INSTANCE_DO(ddDevManager, add(ddGlobalInstance<ddMusicDevice>::instance()));
}

