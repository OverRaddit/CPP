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



# ex04 ㅌㅔ스트항목

- 생성자, 소멸자 호출순서
- equip
	장착하려는 객체가 생성이 되는지.
	공간이 다찼을때 처리가 되었는지.
	이미 누가 먹은 아이템을 장착하려고 할때 처리를 하였는지
- unequip
	빈슬롯을 unequip할때 처리

# 6/17(금) 16: 22

16:30 ~ 18:00 => 1.5시간
CPP04 개념 복습 + 수정 + 테스트 추가

19:30 ~ 22:40 => 3시간
평가 받기 2회
평가 하기 1회


# 6/17(금) 16:32

왜 Cat 생성자에서 Animal 생성자를 호출하지 않지?

# 6/17(금) 16:59
=> 인스턴스를 대입연산을 통해 초기화 하면 대입연산자가 아닌 복사생성자가 호출된다.

- 포인터는 본인의 타입에 맞는 함수를 호출시키지, 가르키는 객체의 함수를 호출시키는 것이 아니다.
그렇다면 본인 타입이 아닌 가르키는 객체의 함수를 호출시키려면 어떻게 해야하지?

virtual 함수를 사용 -> virtual 함수가 실제로 구현된 함수를 찾아서 호출된다.
#### virtual 함수를 사용하면 포인터의 자료형이 아닌 가리키는 객체의 자료형의 함수가 호출된다.
포인터가 가르키는 실질적인 객체이면서 가상함수를 오버라이딩한 함수가 호출된다.

유도클래스의 오버라이딩 함수에 virtual을 안 붙여도 자동적으로 붙게 된다.

순수 가상함수가 존재하면 클래스내에 vptr가 생긴다.
vptr는 vtable을 가리키고 그 테이블에는 가상함수를 오버라이딩한 함수가 존재한다.
vtable에는 부모에서 상속받은 함수또한 같이 존재한다.
https://sexycoder.tistory.com/10

# 6/17(금) 21:52

ex01, ex02 -> Cat 복사생성자에서 Brain을 어떻게 깊은 복사해야할지...?

CPP04 ex03 : While assigning a Materia to another, copying the type doesn’t make sense.
이 부분이 이해가 가지 않는다.
Materia는 동적 객체를 가지고 있지 않아 깊은복사/얕은복사의 구분이 의미가 없다.
따라서 복사할때는 type을 그대로 복사할 수 밖에 없는데 왜 그러지 말라는 건지 모르겠다.
=> 캐릭터 클래스는 AMateria 포인터 배열을 가진다.
포인터 배열은 동적 객체이므로 캐릭터간 복사시에 깊은 복사를 해달라는 뜻인듯.

# 6/19(일) 16:20

ex03
Amateria의 clone 함수를 수행시 Seg fault가 발생한다.
1. Ice의 복사생성자에서 문제가 발생?


[1]
MateriaSource에서 create한 아이템은 바로 equip 시키는 것을 원칙으로 한다.
그렇지 않고 특정 포인터에 저장해버린다면
아이템 생성시마다 포인터가 필요하게 된다.

한 포인터만 돌려쓰면 캐릭터가 아이템을 줍지못할 경우 예외처리가 필요해진다.


[2]
원래 인자로 받은 a를 클론해서 가지려고 했으나
서브젝트의 메인문에서 a라는 인자를 포인터에 저장하고 포인터를 인자로 넘기는게 아닌
new로 생성한 동적객체 자체임을 알 수 있다.
따라서 new로 생성한 동적객체를 복사하는게 아닌 그대로 가져가는게 현명하다고 할 수 있다.
못가져가는 경우에는 delete를 시켜줘야 할 것 같다.


ㅍㅕㅇ가이후 느느낀낀점점

- ex03 Character 깊은복사 안되는거같은데...?
- ex03 virtual 상속이 왜있지?