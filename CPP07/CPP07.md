# 7/1(금) 18:31

- jseo's doodle
함수템플릿이던 클래스템플릿이던 선언과 정의를 분리할 수 없다...? 왜지.

https://hwan-shell.tistory.com/253


템플릿으로 찍어낸 함수는 컴파일러가 컴파일타임에 만들어낸 것이다.
즉 메인에서 int를 T에 대입하는 함수를 만들어야 하는데
찍어낼 템플릿이 조각나 있어서 사용할 수 없게 되는것?

서브젝트 4p문구.
Any function implementation put in a header file (except for function templates) means 0 to the exercise.

애초에 함수 템플릿은 제외되어 있구만!

# 7/1(금) 21:35

중요한 사실.

동적필드가 있는 클래스를 복사생성할때,

나는 종종 Orthodox Canonical폼중
복사생성자에서 대입연산자를 구현하곤 하는데,

이때 복사생성자에서 동적필드의 값을 이니셜라이저로 NULL로 해주는게 좋다.
아니면 동적필드 값에 쓰레기값이 들어가있는 상태로 대입연산을 하게되는데
이때 대입연산자 함수에서 쓰레기값이 들어간것을 어떤 곳을 가리킨다고 착각한다.

다른 과제에서 이 부분이 처리되었는 지 잘 모르겠다.

# 7/1(금) 22:02

delete대신 delete[] 로 바꿈.

<<<<<<< HEAD
# 7/2(토) 16:47

size()가 반환하는건 배열의 크기? 들어가있는 원소의 크기?
서브젝트에선 둘을 구분하고있나?

Jseo님의 코드에서 배울만한 점.
- operator[]
 - 반환형이 const, non-const 2 개의 버전을 작성함 왜??
	=> const 객체가 인덱싱을 하고싶은데 const 멤버함수만 호출할 수 있으니까 해당버전을 따로 만들어야함.
 - 인덱싱시 idx를 size_t로 받아 음수처리를 신경쓰지 않게.
	- 왜 size_t가 아니라 std::size_t라고 했지?
=======
# 7/2(토) 14:16

이 문구의 의도를 모르겠다.
Tip: Try to compile int * a = new int(); then display *a.
그냥 int *a => int * a 이렇게 쓰라는 건가? 왜지...?
>>>>>>> 47980df112251b4f7afae1aababce0cae2241dbe
