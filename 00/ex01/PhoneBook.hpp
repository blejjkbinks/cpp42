#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <string>
# include "Contact.hpp"

class	PhoneBook {
	private:
		int		_index;
		bool	_abort;
		Contact	_contactList[8];

		std::string	_getInput(std::string const prompt);
		void		_incrementIndex(void);
		bool		_displayContactByIndex(std::string const input) const;
		void		_displayContactTable(void) const;
		void		_printContactInfoToTable(int const index) const;
		void		_printTableString(std::string str) const;

	public:
		PhoneBook(void);
		~PhoneBook(void);

		std::string	trimBlank(std::string str);
		bool		addContact(void);
		void		displayContact(int index) const;
		bool		searchContact(void);
};

#endif