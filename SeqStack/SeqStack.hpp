#pragma once
#include <algorithm>

template<typename T>
class SeqStack {
public:
	SeqStack(int size = 0) :
		topOfStack{ -1 }, theCapacity{ size + SPARE_CAPACITY } {
		objects = new T[size + SPARE_CAPACITY];
	}

	~SeqStack() {
		delete[] objects;
	}

	SeqStack(const SeqStack& rhs) :
		topOfStack{ rhs.topOfStack }, theCapacity{ rhs.theCapacity } {
		objects = new T[theCapacity];
		for (auto k = 0; k < size(); ++k)
			objects[k] = rhs.objects[k];
	}

	SeqStack& operator=(const SeqStack& rhs) {
		SeqStack copy = rhs;
		std::swap(*this, copy);
		return *this;
	}

	SeqStack(SeqStack&& rhs) :
		topOfStack{ rhs.topOfStack }, theCapacity{ rhs.theCapacity }, objects{ rhs.objects } {
		rhs.objects = nullptr;
		rhs.topOfStack = -1;
		rhs.theCapacity = 0;
	}

	SeqStack& operator=(SeqStack&& rhs) {
		std::swap(topOfStack, rhs.topOfStack);
		std::swap(theCapacity, rhs.theCapacity);
		std::swap(objects, rhs.objects);
		return *this;
	}


	int size() const {
		return { topOfStack + 1 };
	}

	bool empty() {
		return { size() == 0 };
	}

	T& top() {
		return objects[topOfStack];
	}

	const T& top() const {
		return objects[topOfStack];
	}

	void push(const T& x) {
		if (++topOfStack > theCapacity)
			reserve(2 * theCapacity + 1);
		objects[topOfStack] = x;
	}

	void push(T&& x) {
		if (++topOfStack > theCapacity)
			reserve(2 * theCapacity + 1);
		objects[topOfStack] = std::move(x);
	}

	void pop() {
		if (topOfStack >= 0)
			--topOfStack;
	}

	static const int SPARE_CAPACITY = 16;

private:
	int topOfStack;
	int theCapacity;
	T* objects;

	void reserve(int newCapacity) {
		if (newCapacity < size())
			return;

		T* newStack = new T[newCapacity];
		for (int k = 0; k < size(); ++k)
			newStack[k] = std::move(objects[k]);

		theCapacity = newCapacity;
		std::swap(newStack, objects);
		delete[] newStack;
	}
};
