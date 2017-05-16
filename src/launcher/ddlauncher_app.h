/******************************************************************************
*    Copyright (C), 2015 by HappyTown                                         *
*    FileName:    ddlauncher_app.h
*    Author:      WangYing	                                             *
*    Description:                                                             *
*    History:                                                                 *
*      <author>          <time>          <version>          <description>     *
*        Xzj        2017-05-15 15:43      V1.0.0                build         *
*                                                                             *
******************************************************************************/
#ifndef ddlauncher_app_h
#define ddlauncher_app_h

class ddLauncherApp: public ddApp, public ddMusic::interface, public ddTimer::interface {
public:
	ddLauncherApp();
	~ddLauncherApp();
	virtual ddVoid onInitApp();

	virtual ddVoid onTimer(ddTimer* pTimer);

	virtual ddVoid onMusic_testOk(ddBool isOk);
private:
	ddTimer m_testTimer;
};
#endif // ddlauncher_app_h

