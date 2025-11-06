#ifndef ARRAY_HPP
# define ARRAY_HPP

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
				T* tmp = new T(other._size);
				for (unsigned int i = 0; i < other._size; i++)
					tmp[i] = other._array[i];
				delete[] (this->_array);
				this->_size = other._size;
				this->_array = tmp;
			}
			return (*this);
		}
		T &operator[](unsigned int index)
		{
			if (index >= this->_size)
				throw (Array::IndexOutOfBounds());
			return (this->_array[index]);
		}
		T &operator[](unsigned int index) const
		{
			if (index >= _size)
				throw (Array::IndexOutOfBounds());
			return (_array[index]);
		}
		unsigned int size(void) const
		{
			return (_size);
		}
};
#endif
