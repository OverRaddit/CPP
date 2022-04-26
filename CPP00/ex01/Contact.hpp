#include <string>

class Contact {
	private:
	std::string fname;
	std::string lname;
	std::string nname;
	std::string phonenum;
	std::string darkest_secret;

	//
	int food;
	int weight;

	public:
	void Contact();

	void set_animal(int _food, int _weight);
	void increase_food(int inc);
	void view_stat();
};