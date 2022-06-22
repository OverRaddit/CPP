# ㅁ알아보고 싶은 개념

- cerr, cout 차이, cerr란?
- 컴파일할때 전역변수 설정하여 출력로그를 다른 형식으로 띄우기
- const 값을 const_cast<T>를 이용하여 바꾸기

# 질문하고 싶은 점

ex00 서브젝트중..
Remember. Since grade 1 is the highest one and 150 the lowest, incrementing a grade 3 should give a grade 2 to the bureaucrat.

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
