# 다형성

https://www.geeksforgeeks.org/polymorphism-in-c/?ref=gcse

# [1]
main.cpp:33:3: error: delete called on non-final 'Animal' that has virtual functions but non-virtual destructor [-Werror,-Wdelete-non-abstract-non-virtual-dtor]
                delete arr[i];
                ^
main.cpp:36:2: error: delete called on non-final 'Animal' that has virtual functions but non-virtual destructor [-Werror,-Wdelete-non-abstract-non-virtual-dtor]
        delete j;       //should not create a leak
        ^
main.cpp:37:2: error: delete called on non-final 'Animal' that has virtual functions but non-virtual destructor [-Werror,-Wdelete-non-abstract-non-virtual-dtor]
        delete i;

# 소멸자에 virtual을 붙여야 하는 이유.

```C++
Animal *ptr = new Dog();
delete ptr;	// Animal::~Animal()이 호출되고 Dog이 가진 영역은 해제되지 않음.
```
delete하는 대상의 자료형은 Animal이지만 실제로 할당해제되는 자료형은 Dog이다.

https://stackoverflow.com/questions/10024796/c-virtual-functions-but-no-virtual-destructors
에 자세한 설명이 나와있다.

# 추상 클래스

순수 가상함수가 존재한다면 추상클래스라고 한다.

순수가상함수 원형
virtual void foo() = 0;
정의가 이루어지지 않고 함수만 선언한 형태이다.

추상클래스는 객체로 만들지 못하고 상속으로써만 사용된다.

추상클래스를 상속받은 자식클래스는
무조건 해당 순수 가상 함수를 Override 시켜줘야 합니다.

## 추상 클래스를 통한 이점

순수 가상함수를 지정해줌으로써
자식 클래스가 생성되는 최소의 조건을 만들어주는 셈이다.

순수가상함수로만 이뤄진 추상클래스를 [인터페이스]라고 한다.

# ex03
## WrongCat, WrongAnimal
아예 안쓰는거 같아서 00 이후로 안건드렸다.
이상이 없을지..?

## private <-> protected
오용한거 없나?


# ex04

- 캐릭터가 버린 물질을 마음대로 다루되, unequip전에 주소를 저장해두어라.
	메모리누수를 피해야함을 인지.
- 인벤토리는 어떤 타입의 AMateria도 지원할 수 있다.
	-> 인벤토리 배열의 자료형을 AMateria포인터형으로 하면 해결될 듯!


- MateriaSource간 대입시 delete?
- Character간 대입시 delete?

p.11
While assigning a Materia to another, copying the type doesn't make sense.
=>??????????


[2] 가상순수함수 형식의 소멸자



# 같은 AMateria를 여러번 equip할 수 있을까?
