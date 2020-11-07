#pragma once
#include <algorithm>

template <typename T>
class Vector {
	friend std::ostream& operator<< (std::ostream& os, const Vector<T> v) {
		std::copy(v.begin(), v.end(), std::ostream_iterator<T>(os, " "));
		return os;
	}

public:
	explicit Vector(int initSize) : theSize{ initSize },
		theCapacity{ initSize + SPARE_CAPACITY } {
		objects = new T[theCapacity];
	}

	~Vector() {
		delete[] objects;
	}

	Vector(const Vector& rhs) : theSize{ rhs.theSize },
		theCapacity{ rhs.theCapacity }, objects{ nullptr } {
		objects = new T[theCapacity];
		for (int k = 0; k < theSize; ++k)
			objects[k] = rhs.objects[k];
	}

	Vector& operator=(const Vector& rhs) {
		Vector copy = rhs;
		std::swap(*this, copy);
		return *this;
	}

	Vector(Vector&& rhs) : theSize{ rhs.theSize },
		theCapacity(rhs.theCapacity), objects{ rhs.objects } {
		rhs.objects = nullptr;
		rhs.theSize = 0;
		rhs.theCapacity = 0;
	}

	Vector& operator=(Vector&& rhs) {
		std::swap(theSize, rhs.theSize);
		std::swap(theCapacity, rhs.theCapacity);
		std::swap(objects, rhs.objects);
		return *this;
	}

	void resize(int newSize) {
		if (newSize > theCapacity)
			reserve(newSize * 2);
		theSize = newSize;
	}

	void reserve(int newCapacity) {
		if (newCapacity < theSize)
			return;

		T* newArray = new T[newCapacity];
		for (int k = 0; k < theSize; ++k)
			T[k] = std::move(objects[k]);

		theCapacity = newCapacity;
		std::swap(objects, newArray);
		delete[] newArray;
	}

	T& operator[](int index) {
		return objects[index];
	}

	const T& operator[](int index) const {
		return objects[index];
	}

	bool empty() const {
		return size() == 0;
	}

	int size() const {
		return theSize;
	}

	int capacity() const {
		return theCapacity;
	}

	void push_back(const T& x) {
		if (theSize == theCapacity)
			reserve(2 * theCapacity + 1);
		objects[theSize++] = x;
	}

	void push_back(T&& x) {
		if (theSize == theCapacity)
			reserve(2 * theCapacity + 1);
		objects[theSize++] = std::move(x);
	}

	void pop_back() {
		--theSize;
	}

	const T& back() const {
		return objects[theSize - 1];
	}

	using iterator = T*;
	using const_iterator = const T*;

	iterator begin() {
		return &objects[0];
	}

	const_iterator begin() const {
		return &objects[0];
	}

	iterator end() {
		return &objects[size()];
	}

	const_iterator end() const {
		return &objects[size()];
	}

	static const int SPARE_CAPACITY = 16;

private:
	int theSize;
	int theCapacity;
	T* objects;
};