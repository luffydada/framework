/******************************************************************************
*    Copyright (C), 2015 by HappyTown                                         *
*    FileName:    dddae_app.h
*    Author:      WangYing	                                             *
*    Description:                                                             *
*    History:                                                                 *
*      <author>          <time>          <version>          <description>     *
*        Xzj        2017-05-15 15:54      V1.0.0                build         *
*                                                                             *
******************************************************************************/
#ifndef dddae_app_h
#define dddae_app_h

class ddDaeApp: public ddApp {
public:
	ddDaeApp();
	~ddDaeApp();
	virtual ddVoid onInitApp();
};
#endif // dddae_app_h

