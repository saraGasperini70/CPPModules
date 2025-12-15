#include "PmergeMe.hpp"
#include <ctime>

int main(int ac, char **av) {
	std::list<int> lst;
	std::vector<int> vec;
	if (ac < 2) {
		std::cout << "Error" << std::endl;
		return 1;
	}
	else if (ac == 2) {
		lst = listFunctions::strToList(av[1]);
		vec = vectorFunctions::strTovector(av[1]);
	}
	else if (ac > 2) {
		std::string str;
		for (int i = 1; i < ac; i++) {
			str += av[i];
			if (i != ac - 1)
				str += " ";
		}
		lst = listFunctions::strToList(str);
		vec = vectorFunctions::strTovector(str);
	}
	// List ordering
	try {
		print(lst, "before", 0, "list");
		print(vec, "before", 0, "vector");
		time_t start = clock();
		listFunctions::fordJohnson(lst);
		time_t end = clock();
		time_t start_vec = clock();
		vectorFunctions::fordJohnson(vec);
		time_t end_vec = clock();
		double time_taken_vec = double(end_vec - start_vec) / CLOCKS_PER_SEC * 1000000;
		double time_taken_lst = double(end - start) / CLOCKS_PER_SEC * 1000000;
		print(lst, "after", time_taken_lst, "list");
		print(vec, "after", time_taken_vec, "vector");
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	// Placeholder for vector
	return 0;
}
