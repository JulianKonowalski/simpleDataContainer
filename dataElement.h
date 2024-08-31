#ifndef DATAELEMENT_H
#define DATAELEMENT_H

template <typename Type>
class DataElement {

public:

	DataElement<Type>(Type value) {
		_value = value;
		_next = nullptr;
	}

	Type get_value(void) {
		return _value;
	}

	void set_value(Type value) {
		_value = value;
	}

	DataElement<Type>* get_next(void) {
		return _next;
	}

	void set_next(DataElement<Type>* next) {
		_next = next;
	}

private:
	Type _value;
	DataElement* _next;
};

#endif // !DATAELEMENT_H

