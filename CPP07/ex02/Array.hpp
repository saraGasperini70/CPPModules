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
		Array(void) : _array(NULL), _size(0) {}
		Array(unsigned int n) : _array(new T[n]), _size(n) {}
		Array(const Array& other) : _array(new T[other._size]), _size(other._size)
		{
			for (unsigned int i = 0; i < other._size; i++)
				this->_array[i] = other._array[i];
		}
		~Array()
		{
			delete[] (this->_array);
			this->_array = NULL;
			this->_size = 0;
		}
		class IndexOutOfBounds : public std::exception {
			public:
				virtual const char* what() const throw()
				{
					return "Index out of bounds";
				}
		};
		Array& operator=(const Array& other)
		{
			if (this != &other)
			{
				delete[] (this->_array);
				this->_size = other._size;
				this->_array = new T[this->_size];
				for (unsigned int i = 0; i < other._size; i++)
					this->_array[i] = other._array[i];
			}
			return (*this);
		}
		T &operator[](const int index)
		{
			if (index >= static_cast<int>(this->_size) || index < 0)
				throw (Array::IndexOutOfBounds());
			return (this->_array[index]);
		}
		unsigned int size(void)
		{
			return (this->_size);
		}
};
#endif
