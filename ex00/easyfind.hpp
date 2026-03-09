#pragma once

#include <exception>
#include <iostream>
#include <algorithm>
#include <cstdlib>

class NotThere : public std::exception
{
	public:
		virtual const char * what () const throw ()
		{
			return "The Int you're searching for isn't in the given container";
		}
};

template <typename T>
typename T::iterator easyfind( T &cont, int nb)
{
	typename T::iterator iterator = std::find(cont.begin(), cont.end(), nb);
	if (iterator == cont.end())
		throw NotThere();
	return iterator;
}
