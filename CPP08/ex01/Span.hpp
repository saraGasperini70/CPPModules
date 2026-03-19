#ifndef SPAN_HPP
# define SPAN_HPP

#include <climits>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <algorithm>
#include <stdexcept>

class Span
{
	private:
		unsigned int		_maxSize;
		unsigned int		_currentSize;
		std::vector<int>	_vec;
	public:
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void addNumber(int number);
		void addNumber(const std::vector<int> &numbers);
		unsigned int shortestSpan();
		int longestSpan();
		unsigned int getMaxSize() const;
		unsigned int getCurrentSize() const;
		unsigned int getNumber(int index) const;
		const std::vector<int> &getVec() const;
		class SpanFullException : public std::exception
		{
			public:
				const char* what() const throw();
		}; 
		class FewElementsException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class OutOfRangeException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

#endif
