#include "PmergeMe.hpp"
#include <list>

// Utility functions for lists
namespace listFunctions {
	std::list<int> strToList(std::string str) {
		std::list<int> output;
		size_t strLen = str.length();
		while (strLen > 0) {
			if (str[0] == ' ') {
				str = str.substr(1);
				strLen = str.length();
				continue ;
			}
			if (str[0] < '0' || str[0] > '9') {
				std::cerr << "Error: Invalid character in input string" << std::endl;
				exit(1);
			}
			std::string numStr = str.substr(0, str.find(' '));
			str = str.substr(numStr.length());
			std::istringstream iss(numStr);
			int num;
			if (!(iss >> num)) {
				std::cerr << "Error: Invalid number in input string" << std::endl;
				exit(1);
			}
			output.push_back(num);
			strLen = str.length();
		}
		return output;
	}

	int jacobsthalSequence(size_t n) {
		int seq = 0;
		for (size_t i = 0; i < n; i++) {
			if (i == 0)
				seq = 0;
			else if (i == 1)
				seq = 1;
			else
				seq = jacobsthalSequence(i - 1) + 2 * jacobsthalSequence(i - 2);
		}
		return seq;
	}

	void fordJohnson(std::list<int> &lst, std::list< std::list<int> > &pending) {
		static size_t order = 1;
		size_t unit_size = lst.size() / order;
		if (unit_size < 2)
			return ;
		bool isOdd = (unit_size % order != 0);
		std::list<int>::iterator start = lst.begin();
		std::list<int>::iterator end = lst.begin();
		int steps = (order * unit_size) - (isOdd * order);
		for (int i = 0; i < steps; ++i)
			++end;
		std::cout << "I — Merging" << "1. Split the list into smaller pairs. The size of each pair is " << order << std::endl;
		std::list< std::list<int> > pairs;
		for (std::list<int>::iterator it = start; it != end; ) {
			int it1 = 0; // *(it + (order -1))
			int it2 = 0; // *(it + ((order * 2) - 1))
			for (size_t i = 0; i < order - 1; i++) {
				it1 = *it;
				++it;
			}
			for (size_t i = 0; i < ((order * 2) - 1); i++) {
				it2 = *it;
				++it;
			}

			std::cout << "I — Merging" << "2. Sort each pair individually using insertion sort." << std::endl;
			if (it1 > it2) {
				for (size_t i = 0; i < order; i++) {
					std::list<int>::iterator it_temp1 = it; // *(it + i)
					std::list<int>::iterator it_temp2 = it; // *(it + order + i)
					for (size_t j = 0; j < i; j++)
						++it_temp1;
					for (size_t j = 0; j < order + i; j++)
						++it_temp2;
					std::swap(*it_temp1, *it_temp2);
				}
			}
			for (size_t i = 0; i < order * 2; i++) {
				it++;
			}
		}
		std::cout << "I — Merging" << "3. Repeat with increasing order multiplying by 2 each time." << std::endl;
		order *= 2;
		fordJohnson(lst, pending);
		order /= 2;
		std::cout << "II — Inserting" << "1. Generating pend and main." << std::endl;
		std::list<int> main;
		std::list<int> pend;
		std::list<int>::value_type odd = 0;
		std::list<int> left;
		std::list<int>::iterator itOr = start;
		for (size_t i = 0; i < order - 1; i++)
			++start;
		main.push_back(*start); // a1
		for (size_t i = 0; i < (order * 2 -1); i++) {
			itOr++;
		}
		main.push_back(*itOr); // b1
		// Push elements from pend to main and vice versa
		std::list<int>::iterator it = start;
		for (size_t i = 0; i < order; i++)
			++it;
		for (; it != end; ) {
			pend.push_back(*it);
			for (size_t i = 0; i < order; i++)
				++it;
			main.push_back(*it);
		}
		if (isOdd) {
			for (size_t i = 0; i < order - 1; i++)
				++end;
			odd = *end;
		}
		// Save leftover elements that cannot form pairs on their own
		for (std::list<int>::iterator it = end; it != lst.end(); ++it) {
			left.push_back(*it);
		}
		std::cout << "II — Inserting" << "2. Sort the pend pairs into the main set based on the last element of each pair. We use binary search, optimized with the Jacobsthal sequence, and repeat the process while dividing the order (pair size) by 2 each time." << std::endl;
		if (isOdd || !pend.empty()) {
			std::list<int>::iterator endMain;
			if (pend.size() == 1) {
				endMain = std::upper_bound(main.begin(), main.end(), *pend.begin());
				main.insert(endMain, *pend.begin());
			}
			else if (pend.size() > 1) {
				size_t jacSize = 3;
				size_t count = 0;
				size_t index = 0;
				size_t decAmount;
				while (!pend.empty()) {
					index = jacobsthalSequence(jacSize ) - jacobsthalSequence(jacSize - 1);
					if (index > pend.size())
						index = pend.size();
					decAmount = 0;
					while (index) {
						endMain = main.begin();
						if (jacobsthalSequence(jacSize + count) - decAmount <= main.size()) {
							for (size_t i = 0; i < jacobsthalSequence(jacSize + count) - decAmount; i++)
								++endMain;
						}
						else
							endMain = main.end();
						std::list<int>::iterator itPend = pend.begin();
						for (size_t i = 0; i < index - 1; i++)
							++itPend;
						endMain = std::upper_bound(main.begin(), endMain, *itPend);
						main.insert(endMain, *itPend);
						pend.erase(itPend);
						index--;
						decAmount++;
						count++;
					}
					jacSize++;
				}
			}
			std::list<int> yaslam; // temporary list to hold sorted elements
			if (isOdd) {
				endMain = std::upper_bound(main.begin(), main.end(), odd);
				main.insert(endMain, odd);
			}
			for (std::list<int>::iterator i = main.begin(); i != main.end(); i++) {
				std::list<int>::iterator it = std::find(lst.begin(), lst.end(), *i);
				for (size_t j = 0; j < order - 1; j++)
					++it;
				for (; it != lst.end(); ++it) {
					yaslam.push_back(*it);
			}
			yaslam.insert(yaslam.end(), left.begin(), left.end());
			lst = yaslam;
		}
		std::cout << "II — Inserting" << "3. Finally, insert any remaining elements from pend into main using binary search." << std::endl;
		}
	}
}
