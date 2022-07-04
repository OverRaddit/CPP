# CPP08

# 이터레이터 선언 이슈
typedef typename T::iterator iter;
typename T::iterator iter;

이거 선언하면서 너무 많은 시간을 썼다. 각 키워드가 뭘 의미하는 지 알아보자.

## typedef
```C++
typedef A B; // 타입 A의 별칭 B를 추가한다.
typedef int INT; // int를 INT
typedef typename T::iterator iter;
// T::iterator라는 타입을 iter라고도 부를 수 있게한다.
```

## typename
```C++
typename T::iterator iter;
// T::iterator는 멤버변수나 함수가 아닌 타입(클래스)이다.
// 다른 변수나 함수와 구분하기 위해 typename 키워드를 붙인다.
// T::iterator 클래스의 인스턴스 iter가 생성된다.
```

## 왜 typename 키워드가 필요한가?

T::iterator를 보자. T가 무슨 자료형이 들어올지 알 수 없다.
따라서 iterator가 멤버 변수인지 함수인지 모르기 때문에 타입임을 명시할 방법이 필요했다.

## 왜 typedef 키워드가 필요한가?

T::iterator가 타입임을 알리기 위해 함수안에서 매번 typename을 붙이면 가독성이 떨어지고 코드양이 늘어난다.
자료형의 이름을 내가 설정한 이름으로 바꿈으로써 코드양을 줄이고 가독성을 높일 수 있다.

[참고] typedef 이름 관례
typedef 로 새로운 이름을 만들 때 원래 그 멤버 이름과 똑같이 짓는 것이 관례 입니다