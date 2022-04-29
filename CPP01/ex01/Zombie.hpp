#include <string>
#include <iostream>

class Zombie
{
private:
	/* data */
	std::string name;
public:
	Zombie(/* args */);
	Zombie(std::string _name);
	~Zombie();

	void	setName(std::string _name);

	void	Announce(void);
};

Zombie*	zombieHorde( int N, std::string name );