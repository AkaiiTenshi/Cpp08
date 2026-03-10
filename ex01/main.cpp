#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <vector>

void testBasic() {
	std::cout << "Test 1: Exemple du sujet" << std::endl;
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		
		std::cout << "  Nombres: ";
		for (std::vector<int>::const_iterator it = sp.begin(); it != sp.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
		
		std::cout << "  Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "  Longest span: " << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << "  Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void testExceptions() {
	std::cout << "Test 2: Span vide" << std::endl;
	try {
		Span sp(5);
		std::cout << "  Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "  ERREUR: devrait lancer une exception!" << std::endl;
	} catch (std::exception &e) {
		std::cout << "  Exception attrapee: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << "Test 3: Span avec 1 element" << std::endl;
	try {
		Span sp(5);
		sp.addNumber(42);
		std::cout << "  Longest span: " << sp.longestSpan() << std::endl;
		std::cout << "  ERREUR: devrait lancer une exception!" << std::endl;
	} catch (std::exception &e) {
		std::cout << "  Exception attrapee: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << "Test 4: Depassement de capacite avec addNumber()" << std::endl;
	try {
		Span sp(3);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		sp.addNumber(4);  // Devrait lancer une exception
		std::cout << "  ERREUR: devrait lancer une exception!" << std::endl;
	} catch (std::exception &e) {
		std::cout << "  Exception attrapee: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << "Test 5: Depassement de capacite avec addRange()" << std::endl;
	try {
		Span sp(3);
		std::vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		sp.addRange(v.begin(), v.end());  // Devrait lancer une exception
		std::cout << "  ERREUR: devrait lancer une exception!" << std::endl;
	} catch (std::exception &e) {
		std::cout << "  Exception attrapee: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void testLargeNumbers() {
	std::cout << "Test 6: 10,000 nombres aleatoires" << std::endl;
	try {
		Span sp(10000);
		std::vector<int> numbers;
		
		std::srand(static_cast<unsigned int>(std::time(0)));
		for (int i = 0; i < 10000; i++) {
			numbers.push_back(std::rand());
		}
		
		sp.addRange(numbers.begin(), numbers.end());
		
		std::cout << "  Nombre d'elements: " << std::distance(sp.begin(), sp.end()) << std::endl;
		std::cout << "  Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "  Longest span: " << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << "  Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << "Test 7: 100,000 nombres aleatoires" << std::endl;
	try {
		Span sp(100000);
		std::vector<int> numbers;
		
		for (int i = 0; i < 100000; i++) {
			numbers.push_back(std::rand());
		}
		
		sp.addRange(numbers.begin(), numbers.end());
		
		std::cout << "  Nombre d'elements: " << std::distance(sp.begin(), sp.end()) << std::endl;
		std::cout << "  Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "  Longest span: " << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << "  Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void testEdgeCases() {
	std::cout << "Test 8: Tous les nombres identiques" << std::endl;
	try {
		Span sp(5);
		sp.addNumber(42);
		sp.addNumber(42);
		sp.addNumber(42);
		sp.addNumber(42);
		
		std::cout << "  Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "  Longest span: " << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << "  Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << "Test 9: Nombres negatifs" << std::endl;
	try {
		Span sp(5);
		sp.addNumber(-10);
		sp.addNumber(-5);
		sp.addNumber(-1);
		sp.addNumber(0);
		sp.addNumber(5);
		
		std::cout << "  Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "  Longest span: " << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << "  Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << "Test 10: INT_MAX et INT_MIN" << std::endl;
	try {
		Span sp(5);
		sp.addNumber(INT_MIN);
		sp.addNumber(INT_MIN + 1);
		sp.addNumber(0);
		sp.addNumber(INT_MAX - 1);
		sp.addNumber(INT_MAX);
		
		std::cout << "  Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "  Longest span: " << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << "  Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << "Test 11: Exactement 2 elements" << std::endl;
	try {
		Span sp(2);
		sp.addNumber(10);
		sp.addNumber(20);
		
		std::cout << "  Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "  Longest span: " << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << "  Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

int main() {
	
	std::cout << " TESTS BASIQUES " << std::endl;
	testBasic();
	
	std::cout << " TESTS DES EXCEPTIONS " << std::endl;
	testExceptions();
	
	std::cout << " TESTS AVEC 10,000+ NOMBRES " << std::endl;
	testLargeNumbers();
	
	std::cout << " TESTS DES CAS LIMITES " << std::endl;
	testEdgeCases();
	return 0;
}
