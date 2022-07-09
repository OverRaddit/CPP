# CPP08


## ex00

### 이터레이터 선언 이슈
typedef typename T::iterator iter;
typename T::iterator iter;

이거 선언하면서 너무 많은 시간을 썼다. 각 키워드가 뭘 의미하는 지 알아보자.

### typedef
```C++
typedef A B; // 타입 A의 별칭 B를 추가한다.
typedef int INT; // int를 INT
typedef typename T::iterator iter;
// T::iterator라는 타입을 iter라고도 부를 수 있게한다.
```

### typename
```C++
typename T::iterator iter;
// T::iterator는 멤버변수나 함수가 아닌 타입(클래스)이다.
// 다른 변수나 함수와 구분하기 위해 typename 키워드를 붙인다.
// T::iterator 클래스의 인스턴스 iter가 생성된다.
```

### 왜 typename 키워드가 필요한가?

T::iterator를 보자. T가 무슨 자료형이 들어올지 알 수 없다.
따라서 iterator가 멤버 변수인지 함수인지 모르기 때문에 타입임을 명시할 방법이 필요했다.
이렇게 T에 의존하는 경우를 "의존타입" 이라고 한다.

### 왜 typedef 키워드가 필요한가?

T::iterator가 타입임을 알리기 위해 함수안에서 매번 typename을 붙이면 가독성이 떨어지고 코드양이 늘어난다.
자료형의 이름을 내가 설정한 이름으로 바꿈으로써 코드양을 줄이고 가독성을 높일 수 있다.

[참고] typedef 이름 관례
typedef 로 새로운 이름을 만들 때 원래 그 멤버 이름과 똑같이 짓는 것이 관례 입니다

## ex01

처음 초기화 시키는 값 N은 배열의 크기를 의미...?
애초에 vector를 쓰면 동적으로 할당을 받으니 의미가 없어지는데...

원소들간 최대 차이, 최소 차이값을 구하는 방법....

1. 원소들을 정렬시킨다.

2. 가장 작은값과 큰 값의 차이를 통해 longestSpan을 구한다.

3. 가장 작은값과 그 다음 작은값의 차이를 통해 shortestSpan을 구하다.

정렬을 최대한 적게 하려면?
일단 addNumber이후 혹은 longestSpan, shortestSpan함수 호출 이후에 sort를 하려고하는데
너무 비효율 적인 것 같다.

addNumber를 할때마다 isSort bool값을 false로 만들고
span값을 구하기 전에 isSort값이 false라면 sort후 값을 계산하고
true라면 sort하지 않는다.(이미 sort된 상태이기 때문이다.)

[1] climits 헤더를 추가하지 않았는데 왜 INT_MAX를 사용할 수 있는 걸까?

[2] for문 변수 i를 size_t로 한 이유는 v.size()의 반환값이 size_t이기 때문이다.

[3] orthodox canonical form때문에 기본생성자를 구현해야 하지만, 내가 원하는 생성자만으로
	인스턴스가 생성되었으면 좋겠다. 기본생성자를 호출할 수 없게 private에 선언한다.

[4] ret가 가지는 범위는??
	0 ~ (INT_MAX - INT_MIN)

	2,147,483,647 + 2,147,483,648 = 4 294 967 295

	unsigned <-> signed를 형변환 하면 귀찮고 비용이 많이 드니까 그냥 롱롱으로 선언하자.

### Range-Based...
- 원소 하나를 넣지않고 원소 집합의 범위를 넣는다는 뜻인 것 같다.
이때 범위를 어떻게 표현하는 지가 관건인데,
포인터가 될 수도 있고 컨테이너의 특정 위치를 가르키는 이터레이터가 될 수도 있다.
해당 자료형을 <T>로 잡고 구현해야 할 것 같다.

### 아쉬운 점...
- 적절한 std의 함수들, STL을 어떻게 찾아내는지 모르겠다.
- 테스트함수에 vector말고 다른 걸 시도해보지 않았음.

## ex02

[1] 왜 rbegin, rend가 필요한가?
- iterator는 양방향과 순방향 이터레이터가 있다.
- 만약 end에서부터 begin순, 즉 역순으로 참조하고 싶으면 iterator가 감소연산을 할수있어야 한다.
- 대신 rbegin, rend를 두면 순방향 iterator만으로 역순참조가 가능하다.
- 의문인점은... 감소연산이 가능한 양방향 이터레이터를 쓰지 않고 순방향 이터레이터만으로 쓰기 위해
	rbegin, rend를 쓰는게 효율이 좋은가...? 그걸 증명하는 방법은?

[2] orthodox canonical form에서 어떻게 해야할지 모르겠따.
- 애초에 기반클래스의 orthodox가 차례로 호출되기 때문에 굳이 다른 구현을 할 필요가 없을 것 같다.

iterable하지 않은 std::stack을 이용해 구현해야 한다.

std::stack에 원래 존재하지 않는 이터레이터를 추가로 구현한 클래스를 구현하라는 것 같다.

std::stack의 멤버 변수 원형을 정리하자.

MutantStack을 구현할때, std::stack을 상속하면 stack의 기능을 그대로 사용할 수 있다.
처음에는 MutantStack의 멤버변수로 std::stack을 두어야 겠다고 생각했는데 잘못 생각한듯.

jseo님의 문서에는 이렇게 적혀있다.

> 기반으로 생성된다는 것이 곧 상속을 의미하는 것이 아니다. 선택된 Sequential Container를 적절히 캡슐화하여 내부 로직을 가공해서 Adaptor Container로 제공된다.

# 7/9(토) 19:42

- 기반 클래스를 상속받아서 구현해야 되는 점은 알겠다.

- orthodox canonical form에서 어떻게 해야할지 모르겠따.
	- 애초에 기반클래스의 orthodox가 차례로 호출되기 때문에 굳이 다른 구현을 할 필요가 없을 것 같다.
- MutantStack<int>::iterator 를 어떻게 구현해야 할 지 모르겠다.
	- BidirectionalIterator(양방향)		: 앞뒤 이동 가능. 감소 연산자를 정의한다.
	- 스택의 꼭대기에서 아이템이 추가되거나 삭제됨에 따라 top을 다르게 가리켜야 한다.
	- 따라서 양방향 이터레이터가 필요하다고 생각된다.


# 7/9(토) 20:05 진유와의 동료학습 정리

- std::stack<T> 를 상속하면 stack의 모든 멤버변수와 멤버함수를 사용할 수 있다.

- main함수의 MutantStack<T>::iterator it 는 int i 처럼 (타입) 인스턴스명; 이다.
- 즉 MutantStack<T>::iterator는 타입임을 알릴 필요가 있다.
- typedef typename std::stack<T>::container_type::iterator iterator; 를 선언하자.
	- container_type은 컨테이너 타입을 나타내는 자료형이름이다. stack lib 까보면 확인가능하다.
	- 위 선언을 public에다가 하지 않고 private으로 해두면 밖에서 해당 타입을 선언할 수 없다.
	- typedef는 private/public 블록 안에서만 유효하다!!

- 왜 rbegin, rend가 필요한가?
	- iterator는 양방향과 순방향 이터레이터가 있다.
	- 만약 end에서부터 begin순, 즉 역순으로 참조하고 싶으면 iterator가 감소연산을 할수있어야 한다.
	- 대신 rbegin, rend를 두면 순방향 iterator만으로 역순참조가 가능하다.
	- 의문인점은... 감소연산이 가능한 양방향 이터레이터를 쓰지 않고 순방향 이터레이터만으로 쓰기 위해
		rbegin, rend를 쓰는게 효율이 좋은가...? 그걸 증명하는 방법은?
	- FI, BI의 비용이 그정도로 차이가 날까?

- FI, BI의 비용은 얼마나 차이가 나는가?
	- 단방향 연결리스트와 양방향 연결리스트의 차이정도?