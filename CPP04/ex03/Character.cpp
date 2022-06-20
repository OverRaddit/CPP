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
	std::cout << "[DEBUG]copy constructor" << std::endl;
	*this = a;
}

Character& Character::operator=(const Character& a)
{
	if (this == &a)
		return *this;

	name = a.name;
	for(int i=0;i<4;i++)
	{
		// 기존 슬롯이 존재할 경우 삭제한다.
		if (slots[i])
			delete slots[i];
		slots[i] = NULL;
		// a의 AMateria를 복제하여 저장한다.
		if (a.slots[i])
		{
			std::cout << "copying.. " << a.slots[i]->getType() << std::endl;
			slots[i] = a.slots[i]->clone();
		}
	}
	// 굳이 복사할 필요 없을듯!
	// Garbage는 복사하지 않는다고 정
	// for(int i=0;i<100;i++)
	// {
	// 	if (garbage[i])
	// 		delete garbage[i];
	// 	garbage[i] = a.garbage[i];
	// }
	// g_idx = a.g_idx;
	return *this;
}
Character::~Character()
{
	std::cout << "Character Destructor" << std::endl;
	for(int i=0;i<4;i++)
	{
		if (slots[i])	// NULL이 아닐때
		{
			std::cout << "Erasing " << name << "'s item " << slots[i]->getType() << std::endl;
			delete slots[i];	// 왜 AMateria의 소멸자가 호출되지 않는지?
		}
	}
	for(int i=0;i<100;i++)
		if (garbage[i])
			delete garbage[i];
}
std::string const & Character::getName() const
{
	return name;
}

// 장착실패시 메모리릭 생각해볼것.
// 널포인터 들어올때 처리해줄것.
void Character::equip(AMateria* m)
{
	if (!m)
		return ;
	if (!m->getCollectable()){
		std::cout << "[ERROR]That Materia is already collected by other" << std::endl;
		return ;	// 주울 수 없는 상태라면 return
	}
	int nextIdx = getNextIdx();
	if (nextIdx == -1)
	{
		std::cout << "[ERROR]There's no more space in Inventory" << std::endl;
		delete m;	// [1]
		return ;
	}

	// 장착
	std::cout << "Equip Item " << m->getType() << " to " << name << std::endl;
	slots[nextIdx] = m;
	m->setCollectable(false);
	nextIdx = (nextIdx == 3) ? nextIdx : nextIdx + 1;

}
void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3){
		std::cout << "[ERROR]idx is out of boundary" << std::endl;
		return;		// idx 범위오류
	}
	if (slots[idx] == NULL) {
		std::cout << "[ERROR]that slot is empty dude" << std::endl;
		return;		// 빈슬롯을 equip -> do nothing
	}

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
	if (idx < 0 || idx > 3){
		std::cout << "[ERROR]idx is out of boundary" << std::endl;
		return;		// idx 범위오류
	}
	if (slots[idx] == NULL){
		std::cout << "[ERROR]that slot is empty dude" << std::endl;
		return;		// 빈슬롯을 사용
	}

	slots[idx]->use(target);
}

int Character::getNextIdx(void)
{
	for(int i=0;i<4;i++)
		if (!slots[i])	// NULL을 찾는다
			return i;
	return -1;
}