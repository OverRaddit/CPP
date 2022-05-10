# vtables 1
(https://shaharmike.com/cpp/vtable-part1/)

```C++
#include <iostream>
using namespace std;

class NonVirtualClass {
 public:
  void foo() {}
};

class VirtualClass {
 public:
  virtual void foo() {}
};

int main() {
  cout << "Size of NonVirtualClass: " << sizeof(NonVirtualClass) << endl;
  cout << "Size of VirtualClass: " << sizeof(VirtualClass) << endl;
}
```
Virtual 클래스의 크기가 훨씬 크다. 왜일까?
가상함수는 vtable에대한 포인터를 가지고 있다.

vtable은 각 virtual 클래스에 대해 생성된 정적 변환 테이블이다.
VirtualClass 객체 A,B 가 존재할때
A와 B가 가지고 있는 vtable 포인터를 역참조하면 같은 테이블을 가리키고 있다.
VirtualClass를 상속한 어떤 객체는 vtable 포인터를 상속받지만
가리키는 대상은 자식클래스의 vtable이다.

# https://thrillfighter.tistory.com/79

## 가상함수란? + 사용법

가상함수란 클래스 타입의 포인터로 멤버함수를 호출할 경우 동작하는 함수를 말한다.
함수 선언앞에 virtual 키워드를 붙이면 가상함수가 된다.
선언(hpp)에만 붙이고 구현(cpp)할때는 생략한다.

## 동적 바인딩(virtual), 정적 바인딩

정적바인딩 : 클래스타입의 포인터에 따른 결합
정적바인딩 : 클래스타입의 포인터가 가르키는 대상체에 따른 결함

....?

## virtual

클래스 멤버함수를 동적바인딩 시켜주기 위한 키워드

```C++
parent->func();	// 하나의 표현이지만 어떤 자식객체인지, 부모객체인지에 따라 호출되는 함수가 다르다.
```
만약 parent가 가리키는 클래스내에 가상함수가 있다면,
vptr를 생성하여 vtable의 시작번지값을 저장해준다.

시작번지값을 어떻게 결정하지?

## vtable

가상함수테이블.
각 클래스별로 가상함수만 빼내어 그 주소를 가르키는 함수포인터를 저장해놓은 테이블이다.
일종의 함수포인터배열이라고 할 수 있다.