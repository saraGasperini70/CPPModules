#include <algorithm>
#include <iterator>
bool ft_isDigit(const std::string &ch) {
	for (long unsigned int i = 0; i < ch.length(); i++)
		if (ch[i] < '0' || ch[i] > '9')
			return false;
	return true;
}

int ft_atoi(const std::string num) {
	std::istringstream ss(num);
	int ret = 0;
	if (!ss >> ret)
		return -1;
	return ret;
}

template<typename Container>
PmergeMe<Container>::PmergeMe(std::string av) {
	this->fordJohnson(av);
}

template<typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe *src) {
}

template<typename Container>
PmergeMe<Container>::~PmergeMe() {
	while (!cont.empty())
		cont.pop_back();
}

template<typename Container>
PmergeMe<Container> &PmergeMe<Container>::operator=(const PmergeMe<Container> &src) {
	if (this != &src) {
		cont = src.cont;
	}
	return *this;
}

template<typename Container>
void PmergeMe<Container>::strToCont(std::string str) {
	for (unsigned long int i = 0; i < str.length(); i++) {
		if (str[i] == ' ')
			continue ;
		std::string num = str.substr(i, str.find(" "));
		if (ft_isDigit(num)) {
			if (ft_atoi(num) == -1)
				std::cout << "Error" << std::endl;
			this->cont.push_back(ft_atoi(num));
		}
	}
}

template <typename Container>
void PmergeMe<Container>::fordJohnson(std::string str) {
	// str is a string of numbers separated by spaces
	// order should be the size of the sublists
	// At each iteration, we create sublists of size order and compare the last element to the last of the previous sublist; if it's smaller, we swap them
	// Then we double the order and repeat until the whole list is sorted
	// We can use a Container of Containers to store the sublists
	// We stop when no swaps are made in an iteration
	// cont is the main container
	// matrix is a container of containers; it's the temporary storage for the sublists
	size_t	order = 1;
	bool isOrdered = false;
	PmergeMe<Container> temp(str);
	while (!isOrdered) {
		for (size_t i = 0; i < str.length(); i++) {
			if (str[i] == ' ')
				continue ;
			std::string num = str.substr(i, str.find(" "));
			if (ft_isDigit(num)) {
				if (ft_atoi(num) == -1)
					std::cout << "Error" << std::endl;
			}
		}
		if (temp.cont.size() == 1) {
			typename PmergeMe<Container>::iterator end = std::upper_bound(this->cont.begin(), this->cont.end(), temp.cont[0]);
			this->cont.insert(end, temp.cont[0]);
			isOrdered = true;
		}
		else if (temp.cont.size() > 1) {
			size_t unit_size = temp.cont.size() / order;
			if (unit_size < 2)
				return;
			bool isOdd = unit_size % 2 == 1;
			PmergeMe<Container>::iterator startIter = temp.cont.begin();
			PmergeMe<Container>::iterator endIter = temp.cont.begin() + ((order * unit_size) - (isOdd * order));
			for (PmergeMe<Container>::iterator it = startIter; it < endIter; it += (order * 2)) {
				if (*(it + (order - 1)) > *(it + (order * 2) - 1))
					for (size_t j = 0; j < order; j++) {
						std::swap(*(it + j), *(it + j + order));
					}
			}
			order *= 2;
		}
		if (order >= temp.cont.size())
			isOrdered = true;
	}
	this->cont = temp.cont;
	std::cout << "Sorted container: ";
	for (typename Container::iterator it = this->cont.begin(); it != this->cont.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
