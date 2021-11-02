#include <map>
#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/socket.h>
#include "User.hpp"
#include "Server.hpp"
#include "Console.hpp"

User::User(int fd, Server &server) :
	server(server), 
	registered(false), 
	signTime(time(NULL)), 
	nextTimeout(signTime + REGTIMEOUT), 
	fd(fd), 
	type(TYPE_USER)
{}

User::~User(void)
{
	if (this->isRegistered())
		Console::log(LOG_INFO, "User <" + this->name + "> disconnected");
	else
		Console::log(LOG_INFO, "User <anonymous> disconnected");
	close(this->fd);
	this->channelMap.clear();
	//this->setRegistered(false);
	this->fd = 0;
}

void	User::setHost(std::string value)
{
	this->host = value;
}

std::string const	&User::getHost(void) const
{
	return (this->host);
}

void	User::setIdent(std::string value)
{
	this->ident = value;
}

std::string const &User::getIdent(void) const
{
	return (this->ident);
}

void	User::setReal(std::string value)
{
	this->real = value;
}

std::string const &User::getReal(void) const
{
	return (this->real);
}

std::string &User::getBuffer(void)
{
	return (this->buffer);
}

void	User::setSignTime(time_t value)
{
	this->signTime = value;
}

time_t const	&User::getSignTime(void) const
{
	return (this->signTime);
}

void	User::setName(std::string value)
{
	this->name = value;
}

std::string const	&User::getName(void) const
{
	return this->name;
}

void	User::setPass(std::string value)
{
	this->pass = value;
}

std::string			User::getMask(void)
{
	return (this->name + "!" + this->ident + "@" + this->host);
}

std::string const	&User::getPass(void) const
{
	return this->pass;
}

bool	User::isUser(void)
{
	return (this->type == TYPE_USER);
}

bool	User::isServer(void)
{
	return (this->type == TYPE_SERVER);
}

bool	User::isOper(void)
{
	//TODO hay que extraer el modo de usuario +O
	return false;
}

int		User::getType(void)
{
	return this->type;
}

void	User::setPollIndex(int value)
{
	this->pollIndex = value;
}

int	const	&User::getPollIndex(void) const
{
	return this->pollIndex;
}

void	User::setAwayMsg(std::string value)
{
	this->awayMsg = value;
}

std::string const	&User::getAwayMsg(void) const
{
	return this->awayMsg;
}

void	User::setIdleTime(time_t value)
{
	this->idleTime = value;
}

time_t const	&User::getIdleTime(void) const
{
	return this->idleTime;
}

void	User::setNextTimeout(time_t value)
{
	this->nextTimeout = value;
}

time_t const	&User::getNextTimeout(void) const
{
//	std::cout << "User::getNextTimeout = " << this->nextTimeout << " - " << time(NULL) << " used" << std::endl;
	return this->nextTimeout;
}

void	User::setFd(int value)
{
	this->fd = value;
}

int const &User::getFd(void) const
{
	return this->fd;
}

void	User::clearPingChallenge(void)
{
	this->pingChallenge.clear();
}

void	User::setPingChallenge(std::string value)
{
	this->pingChallenge = value;
}

std::string const	&User::getPingChallenge(void) const
{
	return this->pingChallenge;
}

void	User::setRegistered(bool value)
{
//	std::cout << "User::setRegisterd used" << std::endl;
	this->registered = value;
}

bool const	&User::isRegistered(void) const
{
	return(this->registered);
}

std::map<std::string, Channel *> &User::getChannelMap(void)
{
	return (this->channelMap);
}

Server const	&User::getServer(void) const
{
	return (this->server);
}

bool	User::isAway(void)
{
	return (!this->awayMsg.empty());
}

ssize_t	User::send(std::string msg)
{
	msg.append("\r\n");
	return (::send(this->fd, msg.c_str(), msg.size(), 0));
}
