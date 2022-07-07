# The C++ Standard Template Library

- https://www.geeksforgeeks.org/the-c-standard-template-library-stl/

STL이란?
프로그래밍에서 사용되는 자료구조나 함수(리스트,스택,배열등)를 제공하는 C++ 템플릿 클래스 집합.

* STL의 4가지 구성요소
- 알고리즘
	알고리즘 헤더는 요소 범위에 사용되도록 설계된 함수 집합을 정의함.(배열의미?)
	- 정렬
	- 탐색
	- STL용 알고리즘
	- 유용한 배열 알고리즘
	- 분할 알고리즘(..?)

- 컨테이너
	데이터 혹은 객체를 저장한다.
	7개의 "1차 클래스" 컨테이너, 3개의 컨테이너 어댑터 클래스, 이것들에 접근을 허용하는 7개의 헤더파일이 존재한다.
	- Sequence Containers : 순차적으로 접근할 수 있는 데이터구조를 구현함.
		ex) vector, list, deque, array, forward_list(C++11)(.....??)
	- Container Adaptors : Sequential containers에 접근할 수 있는 서로다른 인터페이스류를 제공.
		ex) queue, priority_queue, stack
	- Associatice Containers : 빠르게 탐색([O(logN)])될 수 있는 데이터구조를 정렬하도록 구현한 것.
		ex) set, multiset, map, multimap
	- Unordered Associatice Containers : 빠르게 탐색([O(logN)])될 수 있는 비정렬 데이터구조를 구현.(C++11)
		ex) unordered_set, unordered_multiset, unordered_map, unordered_multimap

- 함수

- 이터레이터