#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <string>

// Test 1: Basic Stack Operations
void testBasicStackOperations() {
	std::cout << " Test 1: Basic Stack Operations " << std::endl;
	
	MutantStack<int> mstack;
	
	std::cout << "Empty stack: " << (mstack.empty() ? "true" : "false") << std::endl;
	std::cout << "Size: " << mstack.size() << std::endl;
	
	mstack.push(5);
	mstack.push(17);
	
	std::cout << "After pushing 5 and 17:" << std::endl;
	std::cout << "  Top: " << mstack.top() << std::endl;
	std::cout << "  Size: " << mstack.size() << std::endl;
	
	mstack.pop();
	
	std::cout << "After pop:" << std::endl;
	std::cout << "  Size: " << mstack.size() << std::endl;
	std::cout << "  Top: " << mstack.top() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	
	std::cout << "After pushing 3, 5, 737, 0:" << std::endl;
	std::cout << "  Size: " << mstack.size() << std::endl;
	std::cout << "  Top: " << mstack.top() << std::endl;
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	++it;
	--it;
	
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	
	std::stack<int> s(mstack);

	std::cout << std::endl;
}

// Test 2: Forward Iterator
void testForwardIterator() {
	std::cout << " Test 2: Forward Iterator " << std::endl;
	
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	
	std::cout << "Stack contents (bottom to top): ";
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	while (it != ite) {
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	
	std::cout << "Iteration with for loop: ";
	for (MutantStack<int>::iterator i = mstack.begin(); i != mstack.end(); ++i) {
		std::cout << *i << " ";
	}
	std::cout << std::endl;
	
	std::cout << std::endl;
}

// Test 3: Reverse Iterator
void testReverseIterator() {
	std::cout << " Test 3: Reverse Iterator " << std::endl;
	
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	
	std::cout << "Stack contents (top to bottom): ";
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	
	while (rit != rite) {
		std::cout << *rit << " ";
		++rit;
	}
	std::cout << std::endl;
	
	std::cout << std::endl;
}

// Test 4: Const Iterator
void testConstIterator() {
	std::cout << " Test 4: Const Iterator " << std::endl;
	
	MutantStack<int> mstack;
	mstack.push(42);
	mstack.push(21);
	mstack.push(84);
	
	const MutantStack<int> const_stack(mstack);
	
	std::cout << "Const stack contents: ";
	for (MutantStack<int>::const_iterator it = const_stack.begin(); it != const_stack.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	
	std::cout << "Const reverse iteration: ";
	for (MutantStack<int>::const_reverse_iterator rit = const_stack.rbegin(); rit != const_stack.rend(); ++rit) {
		std::cout << *rit << " ";
	}
	std::cout << std::endl;
	
	std::cout << std::endl;
}

// Test 5: Comparison with std::list
void testComparisonWithList() {
	std::cout << " Test 5: Comparison with std::list " << std::endl;
	
	MutantStack<int> mstack;
	std::list<int> mlist;
	
	mstack.push(5);
	mstack.push(17);
	
	mlist.push_back(5);
	mlist.push_back(17);
	
	std::cout << "MutantStack top: " << mstack.top() << std::endl;
	std::cout << "List back: " << mlist.back() << std::endl;
	
	mstack.pop();
	mlist.pop_back();
	
	std::cout << "After pop - MutantStack size: " << mstack.size() << std::endl;
	std::cout << "After pop - List size: " << mlist.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	
	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	mlist.push_back(0);
	
	std::cout << "MutantStack iteration: ";
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	
	std::cout << "List iteration:        ";
	for (std::list<int>::iterator it = mlist.begin(); it != mlist.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	
	std::cout << std::endl;
}

// Test 6: Edge Cases
void testEdgeCases() {
	std::cout << " Test 6: Edge Cases " << std::endl;
	
	// Empty stack
	MutantStack<int> empty;
	std::cout << "Empty stack iteration: ";
	for (MutantStack<int>::iterator it = empty.begin(); it != empty.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << "(nothing printed)" << std::endl;
	
	// Single element
	MutantStack<int> single;
	single.push(42);
	std::cout << "Single element stack: ";
	for (MutantStack<int>::iterator it = single.begin(); it != single.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	
	// Large number of elements
	MutantStack<int> large;
	std::cout << "Pushing 1000 elements... ";
	for (int i = 0; i < 1000; ++i) {
		large.push(i);
	}
	std::cout << "Done. Size: " << large.size() << std::endl;
	std::cout << "First element: " << *large.begin() << std::endl;
	std::cout << "Last element (top): " << large.top() << std::endl;
	
	std::cout << std::endl;
}

// Test 7: Different Types
void testDifferentTypes() {
	std::cout << " Test 7: Different Types " << std::endl;
	
	// String stack
	MutantStack<std::string> strStack;
	strStack.push("Hello");
	strStack.push("World");
	strStack.push("MutantStack");
	
	std::cout << "String stack: ";
	for (MutantStack<std::string>::iterator it = strStack.begin(); it != strStack.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	
	// Double stack
	MutantStack<double> dblStack;
	dblStack.push(3.14);
	dblStack.push(2.71);
	dblStack.push(1.41);
	
	std::cout << "Double stack: ";
	for (MutantStack<double>::iterator it = dblStack.begin(); it != dblStack.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	
	std::cout << std::endl;
}

int main() {
	testBasicStackOperations();
	testForwardIterator();
	testReverseIterator();
	testConstIterator();
	testComparisonWithList();
	testEdgeCases();
	testDifferentTypes();
	
	return 0;
}
