#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n){}

template <typename T>
Array<T>::Array(const Array<T> &other) : _array(new T[other._size]), _size(other._size)
{
	for (unsigned int i = 0; i < other._size; i++)
		this->_array[i] = other._array[i];
}

template <typename T>
Array<T>::~Array()
{
	delete[] (this->_array);
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
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

template <typename T>
T& Array<T>::operator[](const int index)
{
	if (index >= static_cast<int>(this->_size) || index < 0)
		throw (Array::IndexOutOfBounds());
	return (this->_array[index]);
}

template <typename T>
unsigned int Array<T>::size()
{
	return (this->_size);
}
