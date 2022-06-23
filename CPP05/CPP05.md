# ㅁ알아보고 싶은 개념

- cerr, cout 차이, cerr란?
- 컴파일할때 전역변수 설정하여 출력로그를 다른 형식으로 띄우기
- const 값을 const_cast<T>를 이용하여 바꾸기
- 두 헤더가 서로를 include 할때 해결법
	https://psmkr0225.tistory.com/2

# 질문하고 싶은 점

ex00 서브젝트중..
Remember. Since grade 1 is the highest one and 150 the lowest, incrementing a grade 3 should give a grade 2 to the bureaucrat.

ex01
- 이미 사인되어있는 Form에 또 싸인을 하면 오류를 던지게 만들까?
	그 오류를 어떻게 만들지? 오류 객체를 만들까? 아니면 특정문자열..?

- 복사(대입연산자)에 대하여 const 멤버를 어떻게 처리하면 좋을까?

- ASCII 코드란?

- 50% 확률로 처리하는 코드는 random 류의 함수를 사용?

# Todo list

## ex01
- 대입연산자 어떻게 할지 결정

# 6/20(월) 19:44

ex00 서브젝트중..
Remember. Since grade 1 is the highest one and 150 the lowest, incrementing a grade 3 should give a grade 2 to the bureaucrat.

이게 무슨 말인지 모르겠다;;;


[1]
try 영역 밖에 throw를 하면 어떻게 되지?

예외가 처리될 때까지, 호출된 함수의 역순으로 예외데이터가 전달되는데
main에도 처리하지 않으면 terminate함수가 호출되면서 프로그램이 종료되어 ㅓ린다.

# 6/21(월) 19:48

[2]

const std::string Bureaucrat::getName(void) const {return name;}
const int Bureaucrat::getGrade(void) const {return grade;}
const를 붙이니까 컴파일러가 불평을한다.

error: 'const' type qualifier on return type has no effect [-Werror,-Wignored-qualifiers]

...?????

[3]

왜 객체를 생성할 수 없지? -> public처리안해서

[4] 왜 함수원형에 throw를 쓸수없지 ?
throw에 VSC에서 빨갛게 오류밑줄을 그어준다. 아마도 이는 C++98이 아닌 최신화된 버전을
기준으로 검사하는 것 같다. 왜냐면 요즘 C++ 은 다른 문법으로 이를 처리하기 때문...

# 6/22(수) 18:30

grade로 나타낼 수 있는 수의 범위는 1~150이다.
그러면 int를 쓰지말고 size_t나 unsigned int를 쓰는 건 어떨까?
애초에 음수가 저장되지 못하게 하는 것이다.

그리고 증감/감소 연산을 할때 증가/감소 시키는 grade 값에 음수를 넣지 못하게 하려는 의도가 있다.

# 6/22(수) 19:25

ex01 beSigned함수와 signForm함수의 목적을 잘 모르겠다;;

beSigned(Bureaucrat a)
	Bureaucrat을 인자로 갖는 Form의 멤버함수
	Bureaucrat의 등급이 충분히 높다면 form status를 바꾼다.

signForm함수
	Bureaucrat의 멤버함수로 추가할 것.
	이미 서명된 경우, 안된 경우 각각 다른 문자열을 출력한다.
	<bureaucrat> couldn’t sign <form> because <reason>.
	이 형태를 보니 이 함수에서 예외데이터를 catch 하도록 만들어야 겠다.

# 6/22(수) 22:52

signForm함수에 인자로 Form을 갖게 하였다.
이걸 서브젝트에 명시해놔야 하는데 이상하게 없더라;;

현재 ex01에 추가할 사항

[x] 대입연산자 어떻게 할지 결정
[O] <<로 출력하면 어떻게 출력되게 할지 결정(print_info삭제)

# 6/22(수) 15:50

ex02 해석.

- Form을 abstract class로 만들어라.

Sform : sign145, exec 137
- <target>_shrubbery 라는 파일을 생성하고 아스키 트리를 write하라....?

RForm: : 72, 45
- 50% 확률로 target이 로봇화되었음을 inform. 아니면 실패했다고 출력

PForm : 25, 5
-

execute(Bureaucrat const & executor) const
- base 클래스의 멤버함수. 자식클래스에서 implement해야 함.
- form이 sign되어있으면서, 공무원이 충분한 등급을 가지면 실행한다.
- 등급이 부족하면 exception 처리한다.

requirements를 모든 concrete class에서 하거나 base class에서 할 수 있다.
둘중 좋은방법을 찾자.

executeForm(Form const & form)
- [O]공직자의 멤버함수
- [O]form을 실행하기를 시도한다.
- [O]성공시, <bureaucrat> executed <form>
- [O]실패시, 에러메시지 출력

# 6/22(수) 16:05
concrete 클래스들의 hpp, cpp 생성후 Orthodox Canonical Form 함수 생성완료.

# 6/22(수) 16:21
- Form에 순수가상함수 선언하여 추상클래스로 만들기 완료
- Form의 concrete class들에 해당 함수 execute 선언완료. 내용물은 아직...

- 해당 함수는 form 사인여부, 공직자 등급 여부에 따라 성공/실패가 갈린다.
	- 이 확인 작업을 각 concrete에서 하지 말고 base클래스에 체크 함수를 만들면 효율적일 것 같다.
	- 이때 실패라면, exception은 어디서 throw하고 어디서 catch 해야하지?

# 6/22(수) 17:09

- beSigned, beExecuted함수에서 공직자를 참조자로 받는게 좋을 것 같다. => 처리완료 ex01에도 적용.

- 추가한 함수원형에 throw (?, ...)를 어떻게 붙일지 고민해보자.
- executeForm함수를 작성하자.

# 6/22(수) 17:30

- 에러 객체 2개를 더 추가하고 각 상황 발생시 해당 객체를 던지도록 만들었다.
- 해당 에러 객체를 함수원형 throw()부분에 넣어주자.
- 추가한 에러 객체를 Form뿐만아니라 공직자에도 똑같이 넣어줘야 하나?
- 근데 Form의 에러객체와 공직자의 에러객체가 겹치는데, 한번만 선언하도록 만들순 없나?

- 그 이외에는 각 concrete class의 기능을 구현해주면 될 것 같다.

# 6/22(수) 19:48

- dohykim님과 동료학습
	- const 멤버를 가진 객체를 어떻게 복사할 지에 관한 방법 정리완료.
	- const 멤버 이외의 멤버만 복사하기로 내가 결정.
	- 아스키트리는 그냥 복붙하면 된다.
- 저녁식사 완료

- 남은할일
	- concrete class
		- [O]execute 함수 구현.
		- [O]<< 오버로딩..... 이거 어떻게 해야하지?
	- [O]함수원형에 에러 클래스 넣어주기
	- 공직자 클래스에도 에러 클래스 넣기

# 6/22(수) 21:28

- Form의 name이 왜 존재하는지 잘 모르겠다;;
- Form의 concrete class의 멤버필드로 target을 두어야 하나?
	그런데 모든 concrete class에 target이 필요하므로 그냥 Form에 추가하는게 좋을듯?
