#include <iostream>
#include "SeqStack.hpp"

int main() {
	SeqStack<int> ss;
	for (int i = 0; i < 10; ++i)
		ss.push(i);
	std::cout << "stack.size(): " << ss.size() << std::endl;
	while (!ss.empty()) {
		std::cout << ss.top() << std::endl;
		ss.pop();
	}
}