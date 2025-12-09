#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <sstream>
#include <iostream>
#include <iosfwd>
#include <sstream>
#include <vector>
#include <list>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <cstddef>
#include <iterator>

// List functions
namespace listFunctions {
	std::list<int> strToList(std::string str);
	void makePairs(std::list<int> &lst, size_t order, std::list< std::list<int> > &pending);
	void lstCmp(size_t order, std::list< std::list<int> > &pending);
	void fordJohnson(std::list<int> &lst, std::list< std::list<int> > &pending);
}
// Vector functions

#endif
