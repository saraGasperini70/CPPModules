#include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N), _currentSize(0) {
	_vec = std::vector<int>(N);
}

Span::Span(const Span &other) : _maxSize(other._maxSize), _currentSize(other._currentSize) {
	_vec = other._vec;
}

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		_vec = other._vec;
		_maxSize = other._maxSize;
		_currentSize = other._currentSize;
		_vec = other._vec;
	}
	return *this;
}

Span::~Span() {
	std::cout << "Span Destructor called" << std::endl;
	_vec.clear();
}

const char* Span::SpanFullException::what() const throw() {
	return "Exception: Span is full";
}

const char* Span::FewElementsException::what() const throw() {
	return "Exception: Not enough elements to find a span";
}

const char* Span::OutOfRangeException::what() const throw() {
	return "Index out of range";
}

void Span::addNumber(int number) {
	if (_currentSize >= _maxSize) {
		throw SpanFullException();
	}
	_vec[_currentSize++] = number;
}

unsigned int Span::shortestSpan() {
	if (_currentSize < 2) {
		throw FewElementsException();
	}
	std::vector<int> tmp = this->_vec;
	std::sort(tmp.begin(), tmp.end());
	unsigned int minSpan = static_cast<unsigned int>(tmp[1] - tmp[0]);
	for (std::vector<int>::size_type i = 2; i < tmp.size(); i++) {
		unsigned int diff = static_cast<unsigned int>(tmp[i] - tmp[i - 1]);
		if (diff < minSpan)
			minSpan = diff;
	}
	return minSpan;
}

int Span::longestSpan() {
	if (_currentSize < 2) {
		throw FewElementsException();
	}
	int maxElement = *std::max_element(_vec.begin(), _vec.begin() + _currentSize);
	int minElement = *std::min_element(_vec.begin(), _vec.begin() + _currentSize);
	return maxElement - minElement;
}

unsigned int Span::getMaxSize() const {
	return _maxSize;
}

unsigned int Span::getCurrentSize() const {
	return _currentSize;
}

std::vector<int> const &Span::getVec() const {
	return _vec;
}

unsigned int Span::getNumber(int index) const {
	if (index < 0 || index >= static_cast<int>(_currentSize)) {
		throw OutOfRangeException();
	}
	return _vec[index];
}

void Span::addNumber(const std::vector<int> &numbers) {
	std::cout << "Adding multiple numbers; final size will be: " << _currentSize + numbers.size() << std::endl;
	if (_currentSize + numbers.size() > _maxSize) {
		throw SpanFullException();
	}
	_vec.insert(_vec.begin() + _currentSize, numbers.begin(), numbers.end());
	_currentSize += numbers.size();
}
