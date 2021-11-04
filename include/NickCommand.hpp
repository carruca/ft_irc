#ifndef NICKCOMMAND_HPP
# define NICKCOMMAND_HPP

# include "ACommand.hpp"
# include <string>

class NickCommand : public ACommand
{
public:
	NickCommand(Server &server, int accessLevel, int paramCount);

private:
	virtual bool	_recvUser(Message &message);
	virtual bool	_recvServer(Message &message);
	virtual bool	_sendUser(Message &message);
	virtual bool	_sendServer(Message &message);
};

#endif
