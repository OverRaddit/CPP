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

	void	setName(std::string _name);
	void	Announce(void);
};

Zombie*	zombieHorde( int N, std::string name );

#endif