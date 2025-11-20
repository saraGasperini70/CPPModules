#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <sstream>
#include <iostream>
#include <iosfwd>
#include <sstream>

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
		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;
		iterator begin() { return cont.begin(); }
		const_iterator begin() const { return cont.begin(); }
		iterator end() { return cont.end(); }
		const_iterator end() const { return cont.end(); }
		PmergeMe &operator[](const int index) {
			typename Container::iterator it = cont.begin();
			for (int i = 0; i < index; i++)
				++it;
			return *it;
		}
};

#include "PmergeMe.tpp"

#endif
