#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

template <typename T_array>
void	print_elem(T_array &elem)
{
	std::cout << elem << std::endl;
}

template <typename T_array, typename T_func>
void iter(T_array *array, const int length, T_func (*f)(T_array &))
{
	for (int i = 0; i < length; i++)
		f(array[i]);
}

#endif

