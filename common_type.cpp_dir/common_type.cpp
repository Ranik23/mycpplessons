#include <iostream>
#include <type_traits>


template<typename T, typename U, typename... Types>
struct common_type: common_type<common_type<T, U>, Types...> {};


template<typename T, typename U> 
struct common_type<T, U> : std::type_identity<decltype(false ? declval<T>() : declval<U>())> {};



int main() {

	std::cout << typeid(std::common_type<char, char>::type).name() << "\n";

	return 0;
}
