#include "Contact.hpp"

class PhoneBook {
	private:
	Contact contacts[8];

	public:
	void addContact(Contact contact);	// 연락처를 추가한다.
	void printContacts(void);			// 연락처목록을 출력한다.
	void searchContact(int idx);		// 인덱스에 해당하는 연락처를 출력한다.
};