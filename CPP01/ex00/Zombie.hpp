#ifndef ZOMBIE_H
#define ZOMBIE_H
# include <string>
# include <iostream>

class Zombie
{
private:
	std::string name;
public:
	Zombie();
	Zombie(std::string _name);
	~Zombie();

	void	Announce(void);
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif