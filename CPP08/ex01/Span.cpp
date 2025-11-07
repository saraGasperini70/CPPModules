#include "Span.hpp"
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <iostream>

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

void Span::addNumber(int number) {
	if (_currentSize >= _maxSize) {
		throw std::length_error("Span is full");
	}
	_vec[_currentSize++] = number;
}

int Span::shortestSpan() const {
	if (_currentSize < 2) {
		throw std::logic_error("Not enough elements to find a span");
	}
	int minSpan = INT_MAX;
	for (unsigned int i = 0; i < _currentSize - 1; ++i) {
		for (unsigned int j = i + 1; j < _currentSize; ++j) {
			int span = abs(_vec[i] - _vec[j]);
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
		throw std::out_of_range("Index out of range");
	}
	return _vec[index];
}

void Span::addMultipleNumbers(const std::vector<int> &numbers) {
	std::cout << "Adding multiple numbers; final size will be: " << _currentSize + numbers.size() << std::endl;
	if (_currentSize + numbers.size() > _maxSize) {
		throw std::length_error("Not enough space to add all numbers");
	}
	_vec.insert(_vec.begin() + _currentSize, numbers.begin(), numbers.end());
	_currentSize += numbers.size();
}
