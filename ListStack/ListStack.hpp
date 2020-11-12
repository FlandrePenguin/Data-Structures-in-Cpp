#pragma once
#include <algorithm>

template<typename T>
class ListStack {

private:
	struct Node {
		T data;
		Node* next;

		Node(const T& d, Node* n = nullptr) : data{ d }, next{ n } {}
		Node(T&& d, Node* n = nullptr) : data{ std::move(d) }, next{ n } {}
	};

	int theSize;
	Node* head;
};