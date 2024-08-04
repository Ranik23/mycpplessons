#include <iostream>



int my_sum(int a, int b) {
	return a + b;
}


int main() {

	int a, b, c;

	a = 2;

	b = 2;

	c = my_sum(a, b);

	std::cout << "sum - " << c << std::endl;

	return 0;
}
