#include "PmergeMe.hpp"
#include <vector>
#include <list>

int main(int ac, char **av) {
	if (ac < 2) {
		std::cout << "Error" << std::endl;
		return 1;
	}
	else if (ac == 2) {
		PmergeMe < std::vector<int> > mergeme(av[1]);
		PmergeMe < std::list<int> > mergeme_list(av[1]);
	}
	else if (ac > 2) {
		std::string str;
		for (int i = 1; i < ac; i++) {
			str += av[i];
			if (i != ac - 1)
				str += " ";
		}
		PmergeMe < std::vector<int> > mergeme(str);
		PmergeMe < std::list<int> > mergeme_list(str);
	}
	return 0;
}
