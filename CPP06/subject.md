# CPP06 subject

## ex02

Base 클래스 구현
	virtual destructor 만존재.

A,B,C 클래스 구현
	Base를 상속받아야 함

이 4개 클래스는 orthodox canonical form일 필요가 없다!!

다음 함수를 구현하라.

```C++
Base * generate(void);
// 랜덤으로 A,B,C 중 하나를 Base *에 동적할당해 반환한다.
// 랜덤을 어떻게 구현할지는 자유!

void identify(Base* p);
// p의 실제 타입을 출력한다
// ex) p : "A", p:  "B", p: "C"

void identify(Base& p);
// 위와 같은 기능의 함수
// 이 함수내에서 포인터를 사용하는 것은 금지된다.
// ??????
```
typeinfo 헤더는 금지!

궁금한 점
- 가리키는 실제 타입을 어떻게 구분?
	- 타입 캐스트의 성공 여부로 구분하는게 아닐까
	- dynamic_cast 로 A,B,C 각각으로 캐스팅을 할때 성공하는 자료형이
		실제 가르키는 자료형일 것이다.