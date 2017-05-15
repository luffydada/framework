/******************************************************************************
*    Copyright (C), 2015 by HappyTown                                         *
*    FileName:    ddmediaplayer_app.h
*    Author:      WangYing	                                             *
*    Description:                                                             *
*    History:                                                                 *
*      <author>          <time>          <version>          <description>     *
*        Xzj        2017-05-15 16:05      V1.0.0                build         *
*                                                                             *
******************************************************************************/
#ifndef ddmediaplayer_app_h
#define ddmediaplayer_app_h

class ddMediaPlayerApp: public ddApp, public ddSrvManager::listener {
public:
	ddMediaPlayerApp();
	~ddMediaPlayerApp();
	virtual ddVoid onInitApp();
	virtual ddUInt16 myCommand();
	virtual ddVoid onProtocol(ddCommand& cmd);
};
#endif // ddmediaplayer_app_h

