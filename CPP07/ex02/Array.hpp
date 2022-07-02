#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstdlib>

template <class T>
class Array
{
private:
	T *data;
	unsigned int capacity;	// 동적할당된 배열의 크기
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
	: data(NULL), capacity(0)
	{
		#ifdef DEBUG
			std::cout << "[DEBUG] Default Constructor" << std::endl;
		#endif
	};

	Array(unsigned int maxvalue)			// size = maxvalue의 T 배열을 할당, 깊은복사가 필요함을 인지.
	: capacity(maxvalue)
	{
		#ifdef DEBUG
			std::cout << "[DEBUG] maxvalue Constructor" << std::endl;
		#endif
		data = new T[maxvalue];
		memset(data, 0, sizeof(T) * capacity);
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
		data = new T[a.size()];
		for (size_t i = 0; i < a.size(); i++)
			data[i] = a.data[i];
		capacity = a.capacity;
		return *this;
	}
	~Array()							// 소멸자
	{
		#ifdef DEBUG
			std::cout << "[DEBUG] Destructor" << std::endl;
		#endif
		delete[] data;
	}

//=============================================================================
//	Overloading
//=============================================================================
	const T& operator[] (size_t idx) const // const version
	{
		if (idx >= capacity)
			throw BoundaryException();	// 예외 객체를 만들 필요가 있을까?
		return data[idx];
	}
	T& operator[] (size_t idx) // non-const version
	{
		if (idx >= capacity)
			throw BoundaryException();	// 예외 객체를 만들 필요가 있을까?
		return data[idx];
	}

//=============================================================================
//	Method
//=============================================================================
	size_t size() const { return capacity; };	// 배열용량 반환

};



#endif