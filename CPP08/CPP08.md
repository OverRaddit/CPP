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

## ex02

