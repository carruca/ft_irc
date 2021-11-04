#ifndef PRIVMSGCOMMAND_HPP
# define PRIVMSGCOMMAND_HPP

# include "ACommand.hpp"
# include <string>

class PrivmsgCommand : public ACommand
{
public:
	PrivmsgCommand(Server &server, int accessLevel, int paramCount);

private:
	virtual bool	_recvUser(Message &message);
	virtual bool	_recvServer(Message &message);
	virtual bool	_sendUser(Message &message);
	virtual bool	_sendServer(Message &message);
};

#endif
