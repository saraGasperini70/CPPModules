#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <algorithm>
# include <iterator>
# include <exception>
# include <iostream>

template <typename T>
void	easyfind(T &cont, int n)
{
	typename T::iterator iter = std::find(cont.begin(), cont.end(), n);
	if (iter == cont.end())
	{
		std::cerr << n << " not found." << std::endl;
		throw std::runtime_error("Element not found in the container");
	}
	std::cout << n << " found at position: " << std::distance(cont.begin(), iter) << std::endl;
}

#endif
