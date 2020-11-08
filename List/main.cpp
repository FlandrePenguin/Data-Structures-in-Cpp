#include <iostream>
#include "List.hpp"

int main() {
	List<int> lst;
	for (int i = 0; i < 5; ++i)
		lst.push_back(i);
	std::cout << lst << std::endl;
}