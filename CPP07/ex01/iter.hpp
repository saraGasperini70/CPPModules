#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T_array>
void	print_elem(T_array &elem)
{
	std::cout << elem << std::endl;
}

template <typename T_array, typename T_func>
void iter(T_array *array, size_t length, T_func f)
{
	for (size_t i = 0; i < length; i++)
		f(array[i]);
}

#endif

