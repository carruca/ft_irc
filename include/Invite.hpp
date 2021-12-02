#ifndef INVITE_HPP
# define INVITE_HPP

# include <vector>
# include <cstddef>

class User;
class Channel;

class Invite
{
	public:
		typedef std::pair<User *, Channel *>		userChannelPair_type;
		typedef std::vector<userChannelPair_type>	inviteVector_type;
		typedef inviteVector_type::iterator			inviteVector_iterator;

		Invite(void);
		~Invite(void);

		bool					insert(User *user, Channel *channel);
		inviteVector_iterator	find(User *user, Channel *channel);
		bool					erase(User *user, Channel *channel);
		void					eraseChannel(Channel *channel);
		void					eraseUser(User *user);

		inline inviteVector_iterator	begin(void)
		{
			return this->_inviteVector.begin();
		}

		inline inviteVector_iterator	end(void)
		{
			return this->_inviteVector.end();
		}

	private:
		inviteVector_type					_inviteVector;

};

#endif
