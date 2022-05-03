#ifndef WEAPON_H
#define WEAPON_H
# include <string>

class Weapon
{
private:
	std::string type;
public:
	Weapon();
	Weapon(std::string type);
	~Weapon();

	const std::string&	getType(void);
	void				setType(std::string _type);
};

#endif