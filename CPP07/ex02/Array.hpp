#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstdlib>

template <class T>
class Array
{
private:
	T *data;
	int capacity;	// 동적할당된 배열의 크기
	int data_size;	// 배열에 든 원소의 개수
public:
//=============================================================================
//	Inner Class
//=============================================================================
	class BoundaryException : public std::exception
	{
		public:
		virtual ~BoundaryException() throw(){};
		virtual const char* what() const throw(){ return "BoundaryException";};
	};
//=============================================================================
//	Orthodox Canonical Form
//=============================================================================
	Array()									// 기본생성자 : 빈 배열을 생성
	{
		#ifdef DEBUG
			std::cout << "[DEBUG] Default Constructor" << std::endl;
		#endif

		// empty array를 어떻게 해석해야 할지 모르겠다.
		data = new T[5];	// 기본사이즈는 5
		capacity = 5;
		data_size = 0;
		//memset(data, 0, sizeof(data));
	};
	Array(unsigned int maxvalue)			// size = maxvalue의 T 배열을 할당, 깊은복사가 필요함을 인지.
	{
		#ifdef DEBUG
			std::cout << "[DEBUG] maxvalue Constructor" << std::endl;
		#endif
		data = new T[maxvalue];
		capacity = maxvalue;
		data_size = 0;

		// 이게 왜 안될까?
		//memset(data, 0, sizeof(data));
	}
	Array(const Array& c)					// 복사생성자
		: data(NULL)
	{
		#ifdef DEBUG
			std::cout << "[DEBUG] Copy Constructor" << std::endl;
		#endif
		*this = c;
	}
	Array& operator=(const Array& a)		// 대입연산자
	{
		#ifdef DEBUG
			std::cout << "[DEBUG] Assignment operator" << std::endl;
		#endif
		// 대입의 대상이 자기자신이면 동작하지 않는다.
		if (this == &a)
			return *this;

		// 이미 가지고 있는 데이터가 존재한다면 버린다.
		if (data)
		{
			#ifdef DEBUG
			std::cout << "[DEBUG] there's Array data" << std::endl;
			#endif
			delete[] data;
		}
		else
		{
			#ifdef DEBUG
			std::cout << "[DEBUG] there's no Array data" << std::endl;
			#endif
		}

		// a의 데이터를 동적생성하여 복사.
		// 이 부분이 제대로 동작하는 지 모르겠다.
		data = new T[a.size()];
		capacity = a.capacity;
		data_size = a.data_size;
		return *this;
	}
	~Array()
	{
		#ifdef DEBUG
			std::cout << "[DEBUG] Destructor" << std::endl;
		#endif
		delete[] data;
	}					// 소멸자

//=============================================================================
//	Overloading
//=============================================================================
	T& operator[] (int idx)				// []연산자 오버로딩, bound검사 with try-catch
	{
		if (idx < 0 || idx >= capacity)
			throw BoundaryException();	// 예외 객체를 만들 필요가 있을까?
		return data[idx];
	}

//=============================================================================
//	Method
//=============================================================================
	int size() const { return data_size; };	// 배열 아이템개수 반환



};



#endif