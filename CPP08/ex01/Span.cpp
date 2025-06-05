#include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N), _currentSize(0) {
	_array = new int[_maxSize];
}

Span::Span(const Span &other) : _maxSize(other._maxSize), _currentSize(other._currentSize) {
	_array = new int[_maxSize];
	std::copy(other._array, other._array + _currentSize, _array);
}

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		delete[] _array;
		_maxSize = other._maxSize;
		_currentSize = other._currentSize;
		_array = new int[_maxSize];
		std::copy(other._array, other._array + _currentSize, _array);
	}
	return *this;
}

Span::~Span() {
	delete[] _array;
}

void Span::addNumber(int number) {
	if (_currentSize >= _maxSize) {
		throw std::length_error("Span is full");
	}
	_array[_currentSize++] = number;
}

int Span::shortestSpan() const {
	if (_currentSize < 2) {
		throw std::logic_error("Not enough elements to find a span");
	}
	int minSpan = INT_MAX;
	for (unsigned int i = 0; i < _currentSize - 1; ++i) {
		for (unsigned int j = i + 1; j < _currentSize; ++j) {
			int span = abs(_array[i] - _array[j]);
			if (span < minSpan) {
				minSpan = span;
			}
		}
	}
	return minSpan;
}

int Span::longestSpan() const {
	if (_currentSize < 2) {
		throw std::logic_error("Not enough elements to find a span");
	}
	int maxElement = *std::max_element(_array, _array + _currentSize);
	int minElement = *std::min_element(_array, _array + _currentSize);
	return maxElement - minElement;
}

unsigned int Span::getMaxSize() const {
	return _maxSize;
}

unsigned int Span::getCurrentSize() const {
	return _currentSize;
}

int *Span::getArray() const {
	return _array;
}

unsigned int Span::getNumber(int index) const {
	if (index < 0 || index >= static_cast<int>(_currentSize)) {
		throw std::out_of_range("Index out of range");
	}
	return _array[index];
}
