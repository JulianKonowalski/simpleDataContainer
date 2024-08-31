#ifndef CONTAINER_H
#define CONTAINER_H

#include "dataElement.h"
#include "iostream"

template<typename Type>
class Container
{
public:
	Container(void) {
		_head = nullptr;
		_size = 0;
	}

	~Container(void) {
		DataElement<Type>* ptr1, * ptr2;
		ptr1 = ptr2 = _head;
		while (ptr1) {
			ptr1 = ptr1->get_next();
			delete ptr2;
			ptr2 = ptr1;
		}
		delete ptr1;
	}

	void push(Type newElement) {
		if (!_head) {
			_head = new DataElement<Type>(newElement);
			++_size;
			return;
		}
		DataElement<Type>* ptr1 = _head, * ptr2 = new DataElement<Type>(newElement);
		while (ptr1->get_next()) {
			ptr1 = ptr1->get_next();
		}
		ptr1->set_next(ptr2);
		++_size;
	}

	Type pop(void) {
		if (!_head) {
			std::cout << "Container encountered an error. Trying to draw from an empty list!\n";
			exit(1);
		}
		DataElement<Type> tmp = *_head;
		_head = _head->get_next();
		--_size;
		return tmp.get_value();
	}

	Type first_element(void) {
		if (!_head) {
			std::cout << "Container encountered an error. Trying to draw from an empty list!\n";
			exit(1);
		}
		return _head->get_value();
	}

	Type last_element(void) {
		if (!_head) {
			std::cout << "Container encountered an error. Trying to draw from an empty list!\n";
			exit(1);
		}
		DataElement<Type>* ptr = _head;
		while (ptr->get_next()) {
			ptr = ptr->get_next();
		}
		return ptr->get_value();
	}

	int length(void) {
		return _size;
	}

private:
	DataElement<Type>* _head;
	unsigned int _size;
};

#endif

