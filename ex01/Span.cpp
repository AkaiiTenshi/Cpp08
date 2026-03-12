#include "Span.hpp"

Span::Span() : _span(0), _maxsize(0) {
}

Span::Span(unsigned int i) : _span(0), _maxsize(i) {
}

Span::Span(const Span &other) : _span(other._span), _maxsize(other._maxsize) {
}

Span &Span::operator=(const Span &other) {
	if(this != &other)
	{
		_maxsize = other._maxsize;
		_span = other._span;
	}
    return *this;
}

Span::~Span() {
}

const std::vector<int>::const_iterator Span::begin() const {
	return _span.begin();
}

const std::vector<int>::const_iterator Span::end() const {
	return _span.end();
}

void Span::addNumber(int n)
{
	if (_span.size() >= _maxsize)
		throw NoMoreSpaceException();
	_span.push_back(n);
}

long Span::longestSpan(void)
{
	if (_span.size() < 2)
		throw NoSpanFoundException();
	
	int min = *std::min_element(_span.begin(), _span.end());
	int max = *std::max_element(_span.begin(), _span.end());
	
	return static_cast<long>(max) - static_cast<long>(min);
}

long Span::shortestSpan(void)
{
	if (_span.size() < 2)
		throw NoSpanFoundException();
	
	std::vector<int> sorted = _span;
	std::sort(sorted.begin(), sorted.end());
	
	std::vector<long> differences(sorted.size());
	std::adjacent_difference(sorted.begin(), sorted.end(), differences.begin());
	
	return *std::min_element(differences.begin() + 1, differences.end());
}
