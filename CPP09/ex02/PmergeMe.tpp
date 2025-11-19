#include <iosfwd>
#include <sstream>

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

template<typename Container>
void PmergeMe<Container>::fordJohnson(std::string str) {
	this->strToCont(str);
}
