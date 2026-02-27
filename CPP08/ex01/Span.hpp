#ifndef SPAN_HPP
# define SPAN_HPP

#include <climits>
#include <vector>

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
		void addMultipleNumbers(const std::vector<int> &numbers);
		int shortestSpan() const;
		int longestSpan() const;
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
