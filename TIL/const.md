# const..

## 함수원형에서 const를 사용하는 경우

- 파라미터에 const => 해당 인자 const 객체가 되어 그 함수에서 변경할 수 없다.
	=> 해당 인자는 const멤버함수만 호출할 수 있다.
- 함수원형 뒤에 const => 이 함수는 클래스의 멤버변수를 변경할 수 없다.
=> 참고로 이 방법은 멤버함수만 가능하고 일반 전역함수는 이렇게 const를 붙일 수 없다.
=> const객체가 아니어도 const멤버함수는 호출할 수 있다.
- 반환형 앞에 const => 이 함수가 반환하는 값의 원본을 변경할 수 없다.
https://www.youtube.com/watch?v=MSgzBYKbGTI

## const가 붙은 객체

const가 붙은 객체는 해당 클래스의 멤버함수중 const멤버함수만 사용가능하다.
const멤버함수는 멤버를 바꾸지 않는 것을 표시하는 하여 해당 const객체가 바뀌지 않음을
보장할 수 있다.

const 멤버함수란 클래스에서 함수원형 뒤에 const가 붙은 함수를 말한다.
https://ansohxxn.github.io/cpp/chapter8-9/

## 정리하자면..

const는 값을 바꾸지 않겠다는 키워드이다.
객체나 함수를 대상으로 사용할 수 있다.

const 객체는 현재 멤버값을 변경할 수 없다. 따라서 const멤버함수만 호출할 수 있다.
const 멤버함수는 자신의 멤버변수값을 변경할 수 없다.

클래스를 구현할때 앞으로 모든함수가 멤버변수값을 바꾸는지 여부에 따라 const멤버함수
인지 아닌지를 표시해주어야 한다.