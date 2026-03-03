#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <algorithm>
# include <iterator>
# include <iostream>
# include <sstream>
# include <vector>
# include <list>

template <typename T>
std::string to_string(T n) {
	std::ostringstream ss;
	ss << n;
	return ss.str();
}

template <typename T>
void	easyfind(T &cont, int n)
{
	typename T::iterator iter = std::find(cont.begin(), cont.end(), n);
	if (iter == cont.end())
	{
		throw std::runtime_error("Element " + to_string(n) + " not found in the container");
	}
	std::cout << n << " found at position: " << std::distance(cont.begin(), iter) << std::endl;
}

#endif
