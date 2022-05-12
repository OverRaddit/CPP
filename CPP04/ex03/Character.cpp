#include "Character.hpp"

Character::Character() : name("Annonymous"), g_idx(0)
{
	for(int i=0;i<4;i++)
		slots[i] = NULL;
	for(int i=0;i<100;i++)
		garbage[i] = NULL;
	std::cout << "Character Constructor" << std::endl;
}

Character::Character(std::string _name) : name(_name), g_idx(0)
{
	for(int i=0;i<4;i++)
		slots[i] = NULL;
	for(int i=0;i<100;i++)
		garbage[i] = NULL;
	std::cout << "Character Constructor by name" << std::endl;
}

Character::Character(const Character& a)
{
	*this = a;
}
Character& Character::operator=(const Character& a)
{
	name = a.name;
	for(int i=0;i<4;i++)
	{
		// 기존 슬롯이 존재할 경우 삭제한다.
		if (slots[i])
			delete slots[i];
		slots[i] = NULL;

		// a의 AMateria를 복제하여 저장한다.
		// new Ice()를 clone() 함수로 바꿔야 하나?
		if (a.slots[i] == NULL)
			slots[i] = NULL;
		else if (a.slots[i]->getType() == "ice")
			slots[i] = new Ice();
		else if (a.slots[i]->getType() == "cure")
			slots[i] = new Cure();
		else	// 이 경우가 존재 가능...?
		{
			std::cout << "ERROR" << std::endl;
			slots[i] = NULL;
		}
	}
	for(int i=0;i<100;i++)
	{
		if (garbage[i])
			delete garbage[i];
		garbage[i] = a.garbage[i];
	}
	g_idx = a.g_idx;
	return *this;
}
Character::~Character()
{
	for(int i=0;i<4;i++)
	{
		if (slots[i])	// NULL이 아닐때
		{
			std::cout << "DELETE" << std::endl;
			delete slots[i];	// 왜 AMateria의 소멸자가 호출되지 않는지?
		}

	}
	for(int i=0;i<100;i++)
		if (garbage[i])
			delete garbage[i];
	std::cout << "Character Destructor" << std::endl;
}
std::string const & Character::getName() const
{
	return name;
}
void Character::equip(AMateria* m)
{
	if (!m->getCollectable()) return ;	// 주울 수 없는 상태라면 return
	int nextIdx = getNextIdx();
	if (nextIdx == -1)
	{
		std::cout << "There's no more space in Inventory" << std::endl;
		return ;
	}

	// 장착
	slots[nextIdx] = m;
	m->setCollectable(false);
	nextIdx = (nextIdx == 3) ? nextIdx : nextIdx + 1;
}
void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3) return;		// idx 범위오류
	if (slots[idx] == NULL) return;		// 빈슬롯을 equip -> do nothing

	// 휴지통 저장
	if (garbage[g_idx] != NULL)
		delete garbage[g_idx];
	garbage[g_idx] = slots[idx];
	g_idx = (g_idx + 1) % 100;

	// unequip
	slots[idx] = NULL;
}
void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3) return;		// idx 범위오류
	if (slots[idx] == NULL) return;		// 빈슬롯을 사용

	slots[idx]->use(target);
}

int Character::getNextIdx(void)
{
	for(int i=0;i<4;i++)
		if (!slots[i])	// NULL을 찾는다
			return i;
	return -1;
}