#pragma once
#include <algorithm>

template<typename T>
class List {
	friend std::ostream& operator<<(std::ostream& os, const List<T> l) {
		return os;
	}

public:

private:
	struct Node {
		T data;
		Node* prev;
		Node* next;

		Node(const T& d = T{}, Node* p = nullptr,
			Node* n = nullptr) : data{ d }, prev{ p }, next{ n } {}

		Node(T&& d, Node* p = nullptr,
			Node* n = nullptr) : data{ std::move(d) }, prev{ p }, next{ n } {}
	};

	int theSize;
	Node* head;
	Node* tail;
};
