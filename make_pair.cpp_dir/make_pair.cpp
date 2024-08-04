#include <iostream>
#include <utility>


namespace detail {

	template<typename T, typename U>
		std::pair<T, U> make_pair(T&& x, U&& y) { // universal reference
			return std::pair<T, U>(std::forward<T>(x), std::forward<U>(y));
		}
}



int main() {
	

	int x = 10;
	int y = 20;
	
	auto c = detail::make_pair(4, 5);

	std::cout << c.first << " " << c.second << std::endl;
	
	auto b = detail::make_pair(x, y);

	std::cout << b.first << " " << b.second << std::endl;


}
