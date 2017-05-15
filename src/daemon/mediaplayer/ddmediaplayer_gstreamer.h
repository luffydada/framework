/******************************************************************************
*    Copyright (C), 2015 by HappyTown                                         *
*    FileName:    ddmediaplayer_gstreamer.h
*    Author:      WangYing	                                             *
*    Description:                                                             *
*    History:                                                                 *
*      <author>          <time>          <version>          <description>     *
*        Xzj        2017-05-15 16:53      V1.0.0                build         *
*                                                                             *
******************************************************************************/
#ifndef ddmediaplayer_gstreamer_h
#define ddmediaplayer_gstreamer_h

class ddMediaPlayerGstreamer: public ddMediaPlayerApp::interface {
public:
	ddMediaPlayerGstreamer();
	~ddMediaPlayerGstreamer();
	ddVoid onProtocol(ddCommand& cmd);
};
#endif // ddmediaplayer_gstreamer_h

