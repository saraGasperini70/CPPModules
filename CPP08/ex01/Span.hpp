#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <climits>

class Span
{
	private:
		unsigned int		_maxSize;
		unsigned int		_currentSize;
		int					*_array;
	public:
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void addNumber(int number);
		int shortestSpan() const;
		int longestSpan() const;
		unsigned int getMaxSize() const;
		unsigned int getCurrentSize() const;
		unsigned int getNumber(int index) const;
		int *getArray() const;
};

#endif
