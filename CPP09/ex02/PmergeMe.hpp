#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <sstream>
#include <iostream>
// Can't use maps nor stacks
// Must use the Ford-Johnson algorithm (merge-insertion sort)

template<typename Container>
class PmergeMe {
	private:
		Container cont;
	public:
		PmergeMe(std::string av);
		PmergeMe(const PmergeMe *src);
		~PmergeMe();
		PmergeMe &operator=(const PmergeMe &src);
		void strToCont(std::string str);
		void fordJohnson(std::string str);
};

#include "PmergeMe.tpp"

#endif
