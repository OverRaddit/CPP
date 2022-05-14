#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for(int i=0;i<4;i++)
		memory[i] = NULL;
	nextIdx = 0;
	std::cout << "MateriaSource Constructor" << std::endl;
}
MateriaSource::MateriaSource(const MateriaSource& a)
{
	*this = a;
}
MateriaSource& MateriaSource::operator=(const MateriaSource& a)
{
	// 기존 memory 할당해제 안해줌.
	for(int i=0;i<4;i++)
		memory[i] = a.memory[i]->clone();
	nextIdx = a.nextIdx;
	return *this;
}
MateriaSource::~MateriaSource()
{
	for(int i=0;i<4;i++)
		if (memory[i] != NULL)
			delete memory[i];
	std::cout << "MateriaSource Destructor" << std::endl;
}

// 기본 생성자를 통해 생성해도 괜찮은가?
void MateriaSource::learnMateria(AMateria* a)
{
	if (nextIdx > 3)
	{
		std::cout << "No more space left!" << std::endl;
		return ;
	}

	AMateria *tmp;
	if (a->getType() == "ice")
		tmp = new Ice();
	else if (a->getType() == "cure")
		tmp = new Cure();
	else
		return ;
	memory[nextIdx] = tmp;
	nextIdx = (nextIdx + 1) % 4;	//의미없는 코드
}

// memory에서 type에 해당하는 객체가 존재하는지 찾아 반환한다.
// 못찾으면 return 0;
AMateria* MateriaSource::createMateria(std::string const & type)
{
	AMateria *ret;

	ret = NULL;
	for(int i=0;i<4;i++)
	{
		if (memory[i] != NULL) continue;
		if (type == "ice")
			ret = new Ice();
		else if (type == "cure")
			ret = new Cure();
		else
			continue ;
		break ;

	}
	return (ret);
}