/******************************************************************************
*    Copyright (C), 2015 by HappyTown                                         *
*    FileName:    dddae_music_interface.cpp
*    Author:      WangYing	                                             *
*    Description:                                                             *
*    History:                                                                 *
*      <author>          <time>          <version>          <description>     *
*        Xzj        2017-05-15 17:35      V1.0.0                build         *
*                                                                             *
******************************************************************************/
#include "dddae_interface.h"
#include "../devices/dddae_music_device.h"

class ddMusicInstance: public ddSrvManager::notifier {
public:
	ddMusicInstance() {
	}

	~ddMusicInstance() {
		if ( s_instance ) {
			delete s_instance;
			s_instance = nil;
		}
	}

	static ddMusicInstance* instance() {
		if ( !s_instance ) {
			s_instance = new ddMusicInstance();
		}
		return s_instance;
	}

	virtual ddBool isMyCommand(ddUInt16 command) {
		return command > ddMusicDevice::DDENUM_IOCODE_MUSIC_A && command < ddMusicDevice::DDENUM_IOCODE_MUSIC_B;
	}

	virtual ddVoid onProtocol(ddCommand& cmd) {
		std::list<ddMusic::interface *>::iterator it = m_listNotifier.begin();
		while ( it != m_listNotifier.end() ) {
			switch ( cmd.command() ) {
				case ddMusicDevice::DDENUM_IOCODE_MUSIC_OK:
					(*it)->onMusic_testOk(cmd[0]);
					break;
				default: break;
			}
			it++;
		}
	}

	ddVoid add(ddMusic::interface * interface) {
		m_listNotifier.push_back(interface);
	}

	ddVoid remove(ddMusic::interface * interface) {
		std::list<ddMusic::interface *>::iterator it = m_listNotifier.begin();
		while ( it != m_listNotifier.end() ) {
			if ( *it == interface ) {
				m_listNotifier.erase(it);
				break;
			}
			it++;
		}
	}
private:
	std::list<ddMusic::interface *> m_listNotifier;
	static ddMusicInstance* s_instance;
};
ddMusicInstance* ddMusicInstance::s_instance = nil;

ddMusic::interface::interface()
{
	ddMusicInstance::instance()->add(this);
}

ddInt ddMusic::testIsOk(ddInt in)
{
	ddInt out = 0;
	ddService::ioctl(ddMusicDevice::DDENUM_IOCODE_MUSIC_OK, &in, sizeof(ddInt), &out, sizeof(ddInt));
	return out;
}

