#ifndef CONTACT_H
# define CONTACT_H

# include <string>

class	Contact {
	private:
		std::string	_firstname;
		std::string	_lastname;
		std::string	_nickname;
		std::string	_number;
		std::string	_secret;

		bool		_containsOnlyAlpha(std::string const input);
		bool		_containsOnlyDigits(std::string const input);
	
	public:
		Contact(void);
		~Contact(void);

		bool				isEmpty(void) const;
		std::string const	getFirstname(void) const;
		std::string const	getLastname(void) const;
		std::string const	getNickname(void) const;
		std::string const	getNumber(void) const;
		std::string const	getSecret(void) const;
		bool				setFirstname(std::string str);
		bool				setLastname(std::string str);
		bool				setNickname(std::string str);
		bool				setNumber(std::string const str);
		bool				setSecret(std::string const str);
		bool				displayContactInfo(void) const;
};

#endif