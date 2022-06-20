#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"
# include "Ice.hpp"
# include "Cure.hpp"

//class MateriaSource : virtual public IMateriaSource
class MateriaSource : public IMateriaSource
{
private:
	AMateria*	memory[4];
	int			nextIdx;
public:
	MateriaSource();									// 기본생성자
	MateriaSource(const MateriaSource& a);				// 복사생성자
	MateriaSource& operator=(const MateriaSource& a);	// 대입연산자

	virtual ~MateriaSource();
	virtual void learnMateria(AMateria* a);
	virtual AMateria* createMateria(std::string const & type);
};

#endif

/*

learnMateria(Amateria *)
ㅍㅏ라미터로 들어온 Materia를 복사하고 메모리에 저장한다.
나중에 cloned 될 수 있도록!
Character처럼, MateriaSource는 최대 4개의 Materias를 알고 있다.
이들은 반드시 unique하지 않다.

createMateria
새로운 Materia를 반환한다. 입력된 문자열은 이전에 MateriaSource에 의해 학습된 Materia의 복사본이다.
MateriaSource의 타입은 파라미터로 전달된 것과 동이라다.
type이 unknown일 경우, 0을 반환한다.

*/