/******************************************************************************
*    Copyright (C), 2015 by HappyTown                                         *
*    FileName:    dddae_music_interface.h
*    Author:      WangYing	                                             *
*    Description:                                                             *
*    History:                                                                 *
*      <author>          <time>          <version>          <description>     *
*        Xzj        2017-05-15 17:34      V1.0.0                build         *
*                                                                             *
******************************************************************************/
#ifndef dddae_music_interface_h
#define dddae_music_interface_h

class ddMusic {
public:
	class interface {
	public:
		interface();
		virtual ~interface();
		virtual ddVoid onMusic_testOk();
	};
	static ddVoid testIsOk();
};
#endif // dddae_music_interface_h

