#ifndef INVITECHANMODE_HPP
# define INVITECHANMODE_HPP
 
#include "AChanMode.hpp"

#include <string>

class Message;

class InviteChanMode : public AChanMode
{
public:
	InviteChanMode(Server &server);
	~InviteChanMode(void);

	void onChanEvent(Access &access, Message &message);
	void onEnableChanModeEvent(Access &access, User &user, Channel &channel, std::string &value);
	void onDisableChanModeEvent(Access &access, User &user, Channel &channel, std::string &value);
	void onShowChanModeEvent(void);
};

#endif
