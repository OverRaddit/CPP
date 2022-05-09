# ex01 ㅁㅔ인함수작성해야함

# [1]
class 멤버변수에 값을 직접 대입하면
그 값은 언제 대입되는 걸까?

이전에 fixed 객체에서 static const 변수가 존재했다.
그 값을 클래스헤더파일에서 8로 지정할 수 있었다.

이번에는 static const가 아닌 const 변수인데
이전처럼 값을지정할 수 있을까?

그게 가능하다면 그 값은 언제 지정되는 걸까?

예상)
	아마 static const가 아닌 const는 클래스파일에서 지정이 불가능 할 것이다.
	객체가 생성되기 이전에 멤버변수값을 대입할 수 없기 때문이다.
	그렇지만 static 변수는 객체 생성여부에 상관없이 생성되므로 초기화가 가능하다.



# 고민

한 claptrap이 다른 claptrap을 공격할때
이 공격이라는 행위가 하나의 함수에서 정의되지 않고

공격을 한쪽의 객체에서 실행되는 함수와
맞은쪽의 객체에서 실행되는 함수를
각각 실행시켜준다.
처음에 이 두 객체의 함수를 따로 분리한 이유가 납득이 잘 되지 않았는데

한 객체에서 다른 객체를 변화시키지 말고
자기 자신만 변화시킨다고 생각하니 납득이 가는 것 같다.

# 고민2

공격/수리를 하려면 ep나 hp가 0이어서는 안된다.
이 검증을 attack()함수 안에서 해서는 안된다.
```C++
	// a attack b
	A.attack(B.getName());			// a가 b를 공격
	B.takeDamage(A.getDamage());	// b가 a에게 맞음
```
왜냐면 위 코드에서 attack함수내부에 a의 hp,ep검증결과와 상관없이
B.takeDamage는 항상 수행되기 때문이다.

# [2]

```C++
ClapTrap& ClapTrap::operator=(const ClapTrap& claptrap)
{
	// 이게 된다고....? claptrap.name 이렇게 접근 못할 것 같은데...
	name = claptrap.name;
	hp = claptrap.hp;
	ep = claptrap.ep;
	damage = claptrap.damage;

	return *this;
}
```
이 코드에서 53~56행을 보면 claptrap.멤버변수 꼴로 접근하고 있는데
왜 에러가 나지 않는지 궁금하다.

해결완료
	class의 접근지정자의 경계는 클래스 내부와 외부이다.
	저 함수는 ClapTrap클래스 내부에 선언되어 있으므로
	매개변수 claptrap의 멤버변수에도 접근할 수 있다.
	왜냐하면 호출한 영역이 ClapTrap클래스이기 때문이다.

# [3] 자식클래스 생성자에서 부모클래스 생성자 호출시.
```C++
ScavTrap::ScavTrap() // // 이니셜라이저를 사용할 수 없다. 이 멤버들은 부모클래스의 멤버이기 때문.
{
	// 왜 부모클래스의 생성자 호출이 안되지?
	ClapTrap::ClapTrap();
	// 왜 접근할 수 없지?
	hp = 100;
	ep = 5;
	damage = 20;
}
```
이때 부모클래스 생성자는 자식의 이니셜라이저에서 호출해야 한다.
부모클래스 생성자를 호출하지 않으면 자식의 생성자에서 부모의 멤버변수에 접근할 수 없다.
이는 부모클래스 생성자가 호출되지 않아 아직 부모클래스 멤버변수들의 메모리 할당조차 되지 않았기 때문이다.

그럼 자식클래스의 첫번째줄에 부모클래스 생성자를 적고나서 해당 멤버변수들에 접근하면 되는 것 아닌가...?

https://stackoverflow.com/questions/120876/what-are-the-rules-for-calling-the-base-class-constructor
위 참고할것

=> 자바와 달리, C++은 다중 상속을 지원하여 부모클래스는 super()가 아닌 이름으로 호출해야 한다.

# [4] 자식클래스 대입연산자에서 부모 클래스 대입연산자 호출
```C++
Child& operator=(const Child& ref)
 {
  cout << "Second& operator=()" << endl;

  // 호출해서 멤버대 멤버 복사를 하기 위함
  Parent::operator=(ref);
  num3 = ref.num3;
  num4 = ref.num4;

  return *this;
 }
};
```
https://bestcowogok.blogspot.com/2013/10/c-6.html

# 다중상속...?

https://hyeonski.tistory.com/7


# ㅍㅕㅇ가피드백

- scav인가 frag인가 함수 오버로딩 안해서 부모 로그로 찍힘

- guard 함수인가 그거 static 변수가 모든 객체가 공유함;;

평가표에 protected 인지 확인하는 항목있었는데 나 그렇게 안함;;