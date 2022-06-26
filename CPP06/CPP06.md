## ex00

가장 흔하게 사용되는 C++ 리터럴의 string 표현을 인자로하는 프로그램을 작성하시오.

문자
If a conversion to char is not displayable, prints an informative message.
Displayable의 조건을 찾아야 겠다.

프로그램 실행인자를
chat, int, float, double로 형 변환하여 각줄에 출력한다.

# 6/26(일) 18:18

- ex00을 푸는데 필요한 개념공부중..

- std::stringstream
- std::atof

- stoi, stof, stod 함수는 C++11의 함수이므로 사용을 지양하자.

https://stackoverflow.com/questions/29485194/how-to-convert-user-input-char-to-double-c
좋은 글 발견. jseo's doodle과도 내용이 일부 겹치는 것 같다.

# 6/26(일) 20:04

- atof, strtod 함수의 차이점은??
atof()
strtod(nptr, NULL)

# 6/26(일) 22:00

- 오늘 공부한 것.

C++의 캐스팅에 대하여.
구형 스타일과 신형 스타일에 대해.

const char* => double로 형변환 하는 방법

서브젝트에서 제시한 형태로 출력하기 위해 필요한 함수들...
=> 이 부분이 쓸데 없이 시간을 많이 먹는다.