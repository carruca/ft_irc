#include "KeyChanMode.hpp"
#include "ChanModeConfig.hpp"

KeyChanMode::KeyChanMode(Server &server)
	: AChanMode(server)
{
	this->_chanModeConfig.type = ChanModeConfig::bothParam;
	this->_chanModeConfig.mode = 'k';
	this->_chanModeConfig.events = CHANMODE_JOIN;
}

KeyChanMode::~KeyChanMode(void)
{}

void	KeyChanMode::onChanEvent(Access &access, Message &message)
{
	(void)access;
	(void)message;
}

void	KeyChanMode::onEnableChanModeEvent(Access &access, std::string &value)
{
	(void)access;
	(void)value;
}

void	KeyChanMode::onDisableChanModeEvent(Access &access, std::string &value)
{
	(void)access;
	(void)value;
}

void	KeyChanMode::onShowChanModeEvent(void)
{
}