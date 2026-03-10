#pragma once

#include <exception>
#include <algorithm>
#include <vector>
#include <numeric>

class Span {
	private:
		std::vector<int> _span;
		unsigned int _maxsize;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span &other);
		Span& operator=(const Span &other);
		~Span();

	void addNumber(int n);
	long shortestSpan(void);
	long longestSpan(void);

	// Template pour ajouter un range d'itérateurs
	template <typename InputIterator>
	void addRange(InputIterator first, InputIterator last) {
		size_t count = std::distance(first, last);
		if (_span.size() + count > _maxsize)
			throw NoMoreSpaceException();
		_span.insert(_span.end(), first, last);
	}

	const std::vector<int>::const_iterator begin() const;
	const std::vector<int>::const_iterator end() const;

		class NoMoreSpaceException : public std::exception {
			virtual const char* what() const throw() {
				return "No space available in Span";
			}
		};

	class NoSpanFoundException : public std::exception {
		virtual const char* what() const throw() {
			return "Couldn't find a valid span";
		}
	};
};
