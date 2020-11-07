#pragma once
#include <algorithm>

template<typename T>
class List {
	friend std::ostream& operator<<(std::ostream& os, const List<T> l) {
		return os;
	}

public:
	class const_iterator {
		friend class List<T>;

	public:
		const_iterator() : current{ nullptr } {}

		const T& operator*() const {
			return retrieve();
		}

		const_iterator& operator++() {
			current = current->next;
			return *this;
		}

		const_iterator& operator++(int) {
			const_iterator old = *this;
			++(*this);
			return old;
		}

		bool operator==(const const_iterator& rhs) const {
			return current == rhs.current;
		}

		bool operator!=(const const_iterator& rhs) const {
			return !(current == rhs.current);
		}
	protected:
		Node* current;

		T& retrieve() const {
			return current->data;
		}

		const_iterator(Node* p) : current{ p } {}
	};

	class iterator : const_iterator {
		friend class List<T>;

	public:
		iterator() {}

		T& operator*() {
			return const_iterator::retrieve();
		}

		const T& operator*() const {
			return const_iterator::operator*();
		}

		iterator& operator++() {
			current = current->next;
			return *this;
		}

		iterator& operator++(int) {
			iterator old = *this;
			++(*this);
			return old;
		}

	protected:
		iterator(Node* p) : const_iterator(p) {}
	};

	List() { init(); }

	List(const List& rhs) {
		init();
		for (auto& x : rhs) {
			push_back(x);
		}
	}


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

	void init() {
		theSize = 0;
		head = new Node;
		tail = new Node;
		head->next = tail;
		tail->pre = head;
	}
};
