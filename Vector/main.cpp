#include <iostream>
#include "Vector.h"

int main() {
	Vector<int> v(5);
	for (int k = 0; k < v.size(); ++k)
		v[k] = k + 2;
	std::cout << v << std::endl;
}