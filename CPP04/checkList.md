CPP04


- ex00
[O] 생성자와 소멸자는 특정 메시지를 출력해야 한다.
[O] 이때, 모든 클래스가 같은 메시지를 출력하면 안된다.

[O] Animal 클래스는 std::string type을 protected로 가져야 함.
[O] Dog, Cat은 Animal 클래스를 상속받음
[O] 두 클래스는 자신의 클래스명으로 type 값을 가지도록 설정해야 함.
[O] Animal 클래스의 type값은 empty 혹은 내가 원하는 값으로 설정해도 됨.
[0] Animal 포인터로 호출한 makesound()가 자식 클래스의 함수를 호출해야 함.

- ex01
[O] Brain 클래스 구현하기
[O] std::string ideas[100]
[O] Dog, Cat은 Brain* 속성을 가짐.
[O] Dog, Cat은 생성/소멸시 Brain을 동적 할당/해제함.
[O] Dog, Cat은 깊은 복사를 수행함.

- ex02
[] Animal 클래스 추상클래스로 만들기