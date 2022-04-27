#include "Contact.hpp"
#include <iomanip> // setw
class PhoneBook {

private:
	Contact	contacts[8];
	int		nextIdx;
	int		count;
public:
	// Constructor
	PhoneBook(void);

	// Getter & Setter
	void addContact(void);			// 연락처를 추가한다.
	void printContact(int idx);
	void printContacts(void);		// 연락처목록을 출력한다.
	void searchContact(int idx);	// 인덱스에 해당하는 연락처를 출력한다.
};