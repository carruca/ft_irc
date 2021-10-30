#ifndef USER_HPP
# define USER_HPP

# include <string>
# include <map>
# include "Server.hpp"
# include "ISender.hpp"

class ISender;

class User : public ISender
{
public:
	User(int fd, Server &server);
	~User(void);

	void				setHost(std::string value);
	std::string const	&getHost(void) const;

	void				setIdent(std::string value);
	std::string const	&getIdent(void) const;

	void				setReal(std::string value);
	std::string const	&getReal(void) const;

	void			setSignTime(time_t volue);
	time_t const	&getSignTime(void) const;
		
	void				setName(std::string value);
	std::string const	&getName(void) const;

	std::string &getBuffer(void);
	bool		isUser(void);
	bool		isServer(void);

	void				setAwayMsg(std::string value);
	std::string const	&getAwayMsg(void) const;

	std::map<std::string, Channel *> &getChannelMap(void);
	Server const	&getServer(void) const;

	void 			setAwayTime(time_t value);
	time_t const	&getAwayTime(void) const;

	void 			setNextPing(time_t value);
	time_t const	&getNextPing(void) const;

	void			setIdleTime(time_t value);
	time_t const	&getIdleTime(void) const;

	void		setRegistered(bool value);
	bool const	&isRegistered(void) const;

	void		setPollIndex(int value);
	int const	&getPollIndex(void) const;

	void		setFd(int value);
	int	const	&getFd(void) const;

	bool	isAway(void);
//	bool	isOper(void);

	ssize_t		send(std::string msg);

private:
	User(void);

	std::string							name;
	std::string							host;
	std::string							ident;
	std::string							real;
	std::string							buffer;
	std::string 						awayMsg;
	Server								&server;
	std::map<std::string, Channel *>	channelMap;
	time_t								signTime;
	bool								registered;
	time_t								awayTime;
	time_t								nextPing;
	time_t								idleTime;
	int									pollIndex;
	int									fd;
	int									type;
};

#endif
