# Const 멤버를 복사할 때의 방법론

## const를 타입캐스트하여 변경할 수 있도록 바꾼다.

```C++
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& a)
{
	grade = a.grade;
	(*(const_cast<std::string *>(&name))) = a.getName();
	return *this;
}
int main()
{
	Bureaucrat A("gshim", 50);
	Bureaucrat B("schoe", 90);

	A = B; // A는 지역변수이므로 delete할 수 없다.
}
```

## const 멤버는 복사하지 않고 나머지만 바꾼다.

```C++
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& a)
{
	grade = a.grade;
	//name = a.name;	// const라서 바꿀 수 없다.
	return *this;
}
int main()
{
	Bureaucrat A("gshim", 50);
	Bureaucrat B("schoe", 90);

	A = B; // A는 지역변수이므로 delete할 수 없다.
}
```

## const 멤버가 있는 객체는 복사할 수 없도록 한다.

```C++
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& a)
{
	// do nothing
	return *b;
}
int main()
{
	Bureaucrat A("gshim", 50);
	Bureaucrat B("schoe", 90);

	A = B; // A는 지역변수이므로 delete할 수 없다.
}
```

## 원본객체를 삭제하고 복사하려는 객체로 새로 생성한다.

```C++
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& a)
{
	delete this;
	Bureaucrat* b = new Bureaucrat(a);
	return *b;
}
int main()
{
	Bureaucrat A("gshim", 50);
	Bureaucrat B("schoe", 90);

	A = B; // A는 지역변수이므로 delete할 수 없다.
}
```

참신한 방법이지만, 지역변수에 대하여 대입을 할 수 없다.

# 정리

아직 캐스팅의 개념을 배우지 않았기 때문에 const 상수는 값을 변경하지 않기로 한다.

const 멤버를 가지는 클래스에 대해서는
const 멤버를 제외한 멤버만 복사하는 것으로 정의한다.