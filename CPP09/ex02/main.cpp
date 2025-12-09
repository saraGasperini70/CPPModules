#include "PmergeMe.hpp"
#include <vector>
#include <list>

int main(int ac, char **av) {
	std::list<int> lst;
	if (ac < 2) {
		std::cout << "Error" << std::endl;
		return 1;
	}
	else if (ac == 2) {
		lst = listFunctions::strToList(av[1]);
	}
	else if (ac > 2) {
		std::string str;
		for (int i = 1; i < ac; i++) {
			str += av[i];
			if (i != ac - 1)
				str += " ";
		}
		lst = listFunctions::strToList(str);
	}
	// List ordering
	try {
		std::cout << "Before: ";
		for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		time_t start = clock();
		std::list< std::list<int> > pending;
		listFunctions::fordJohnson(lst, pending);
		time_t end = clock();
		std::cout << "After: ";
		for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		double time_taken = double(end - start) / CLOCKS_PER_SEC * 1000000;
		std::cout << "Time to process a range of " << lst.size() << " elements with std::list : " << time_taken << " us" << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	// Placeholder for vector
	return 0;
}
