#include <iostream>
#include <type_traits>
#include <string>

// is_same

template<typename P1, typename P2>
struct is_same : std::false_type {};


template<typename T>
struct is_same<T, T> : std::true_type {};



// Concepts

template<typename T>
concept Comparable = requires(T a, T b) {
	a > b;
};

template<typename T>
concept Addable = requires(T a, T b) {
	a + b;
};

template<typename T>
struct is_integral : std::bool_constant<
					 requires (T t, T* p, void (*f)(T))
					 {
							reinterpet_cast<T>(t);
							f(0);
							p + t;
					 }> {};					



int main() {


	//std::cout << is_integral<std::string>::value << std::endl;

	std::cout << is_same<std::string, int>::value << std::endl;
	

}
