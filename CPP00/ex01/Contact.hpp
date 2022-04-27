#include <string>
#include <iostream>
class Contact
{
private:
	std::string fname;
	std::string lname;
	std::string nname;
	std::string pnum;
	std::string dsecret;

public:
	// Constructor
	Contact(void);

	// Getter & Setter
	std::string getFname();
	std::string getLname();
	std::string getNname();
	std::string getPnum();
	std::string getDsecret();

	void setFname(std::string _fname);
	void setLname(std::string _lname);
	void setNname(std::string _nname);
	void setPnum(std::string _pnum);
	void setDsecret(std::string _dsecret);

	// Method
	bool set_info();
	void set_animal(int _food, int _weight);
	void increase_food(int inc);
	void view_stat();
};


