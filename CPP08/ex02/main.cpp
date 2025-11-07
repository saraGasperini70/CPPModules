#include "MutantStack.hpp"
#include <iostream>
#include <vector>

int main(void)
{
	MutantStack<int>	mstack;
	std::vector<int>		vect;

	mstack.push(5);
	mstack.push(17);
	vect.push_back(5);
	vect.push_back(17);

	std::cout << "MutantStack top element: " << mstack.top() << std::endl; // Should print 17
	std::cout << "Vector last element: " << vect.back() << std::endl; // Should print 17
	mstack.pop();
	vect.pop_back();
	std::cout << "Stack size after pop: " << mstack.size() << std::endl; // Should print 1
	std::cout << "Vector size after pop: " << vect.size() << std::endl; // Should print 1
	std::cout << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	vect.push_back(3);
	vect.push_back(5);
	vect.push_back(737);
	vect.push_back(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	std::vector<int>::iterator vit = vect.begin();
	std::vector<int>::iterator vite = vect.end();

	++it;
	--it;

	++vit;
	--vit;

	while (it != ite) {
		std::cout << "MutantStack: " << *it << std::endl;
		++it;
	}

	while (vit != vite) {
		std::cout << "Vector: " << *vit << std::endl;
		++vit;
	}
	return 0;
}
