#pragma once

#include <exception>
class Span {
	private:
		std::vector<int> _span;
		unisgned int _maxsize
	public:
		Span();
		Span(unsigned int n);
		Span(const Span &other);
		Span& operator=(const Span &other);

		void addNumber(int n);
		int shortestSpan(void);
		int longestSpan(void);

		class NoMoreSpaceException : public std::exception {
			virtual const char* what() const throw() {
				return "No space available in Span";
			}
		};

		class NoSpanFoundException : public std::exception {
			virtual const char* what() const throw() {
				return "Coulnd't find a valid span";
			}
		};
};
