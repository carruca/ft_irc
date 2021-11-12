#ifndef ACOMMAND_HPP
# define ACOMMAND_HPP

# include "Server.hpp"
# include "User.hpp"
# include "EventHandler.hpp"
//# include "Message.hpp"
# include <string>

# define LEVEL_UNREGISTERED	0x00
# define LEVEL_REGISTERED	0x01
# define LEVEL_IRCOPERATOR	0x02
# define LEVEL_ALL			0x03

class Server;
class Message;
class User;

template <class EvenT, class ValueT> 
class EventHandler;

class ACommand
{
public:
	ACommand(Server &server, int accessLevel, int minParam);
	virtual ~ACommand(void);
	virtual void loadEvents(EventHandler<int, Message> &eventHandler) = 0;

	void	recv(Message &msg);
	void	send(Message &msg);

private:
	virtual bool	_recvUser(Message &message) = 0;
	virtual bool	_recvServer(Message &message) = 0;
	virtual bool	_sendUser(Message &message) = 0;
	virtual bool	_sendServer(Message &message) = 0;

protected:
	Server		&server;
	int			accessLevel;
	size_t		minParam;
	Server		*serverSender;
	User		*userSender;
	Server		*serverReceiver;
	User		*userReceiver;
};

#endif
