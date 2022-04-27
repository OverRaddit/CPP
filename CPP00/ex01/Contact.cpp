
#include "Contact.hpp"

// Constructor
Contact::Contact(void)
{

}

// Getter & Setter
std::string Contact::getFname()
{
	return (fname);
}
std::string Contact::getLname()
{
	return (lname);
}
std::string Contact::getNname()
{
	return (nname);
}
std::string Contact::getPnum()
{
	return (pnum);
}
std::string Contact::getDsecret()
{
	return (dsecret);
}

void Contact::setFname(std::string _fname)
{
	fname = _fname;
}
void Contact::setLname(std::string _lname)
{
	lname = _lname;
}
void Contact::setNname(std::string _nname)
{
	nname = _nname;
}
void Contact::setPnum(std::string _pnum)
{
	pnum = _pnum;
}
void Contact::setDsecret(std::string _dsecret)
{
	dsecret = _dsecret;
}

bool getline_field(std::string fieldname, std::string &str)
{
	while(1){
		std::cout << fieldname << "> ";
		std::getline(std::cin, str);
		if (std::cin.eof())
			return (false);
		if (str.length() == 0)
			continue ;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(1024, '\n');
		}
		return (true);
	}
}

bool Contact::set_info(void)
{
	Contact contact;
	std::string _fname;
	std::string _lname;
	std::string _nname;
	std::string _pnum;
	std::string _dsecret;

	if (!getline_field("First name", _fname) ||
		!getline_field("Last name", _lname) ||
		!getline_field("Nickname", _nname) ||
		!getline_field("PhoneNumber", _pnum) ||
		!getline_field("Darkest Secret", _dsecret))
		return (false);

	setFname(_fname);
	setLname(_lname);
	setNname(_nname);
	setPnum(_pnum);
	setDsecret(_dsecret);


	return (true);
}