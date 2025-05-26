#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>
#include <cstdlib>

template <typename T>
class Array
{
	private:
		T* _array;
		unsigned int _size;
	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array& other);
		~Array();
		class IndexOutOfBounds : public std::exception {
			public:
				virtual const char* what() const throw()
				{
					return "Index out of bounds";
				}
		};
		Array& operator=(const Array& other);
		T &operator[](const int index);
		unsigned int size(void);
};
#endif
