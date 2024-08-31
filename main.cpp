#include "Container.h"
#include <iostream>
int main(void) {
	Container<int> container;
	container.push(1);
	container.push(2);
	std::cout << "First element: " << container.first_element() << '\n';
	std::cout << "Last element: " << container.last_element() << '\n';
	std::cout << "Length: " << container.length() << '\n';
	std::cout << "Popped element: " << container.pop() << '\n';
	std::cout << "Length: " << container.length() << '\n';
	std::cout << "Popped element: " << container.pop() << '\n';
	std::cout << "Length: " << container.length() << '\n';
	return 0;
}