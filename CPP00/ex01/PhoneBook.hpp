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
	int	getCount(void);

	// Function
	void addContact(void);			// 연락처를 추가한다.
	void printHead(void);
	void printHeadAll(void);
	void printContact(int idx);
	void printContactAll(int i);
	void printContacts(void);		// 연락처목록을 출력한다.
	void searchContact(void);		// 인덱스에 해당하는 연락처를 출력한다.
};