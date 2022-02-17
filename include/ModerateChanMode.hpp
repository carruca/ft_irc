#ifndef MODERATECHANMODE_HPP
# define MODERATECHANMODE_HPP
 
#include "AChanMode.hpp"

#include <string>

class Message;

class ModerateChanMode : public AChanMode
{
public:
	ModerateChanMode(Server &server);
	~ModerateChanMode(void);

	void onChanEvent(Access &access, Message &message);
	void onEnableChanModeEvent(Access &access, User &user, Channel &channel, Message &message);
	void onDisableChanModeEvent(Access &access, User &user, Channel &channel, Message &message);
	void onShowChanModeEvent(void);
};

#endif
