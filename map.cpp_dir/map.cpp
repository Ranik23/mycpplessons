#include <iostream>
#include <map>
#include <initializer_list>
#include <vector>
#include <utility>
#include <type_traits>



// Механизм Инстанцирования Типов 


namespace detail {

	template<typename T, typename U>
	struct is_same : std::false_type {};


	template<typename T>
	struct is_same<T, T> : std::true_type {};



	template<int N>
		struct Factorial {
			static const int value = Factorial<N - 1>::value * N;
		};

	template<>
		struct Factorial<0> {
			static const int value = 1;
		};


	template<bool, class T = void> struct EnableIf;
 
	template<class T> struct EnableIf<false, T> {};

	template<class T> struct EnableIf<true, T> {
		using type = T;
	};


	template<class T, class = decltype(std::declval<T>().Serialize())>
	std::true_type HasSerializeTest(const T&);

	std::false_type HasSerializeTest(...);

	template<class T> using HasSerialize = 
		decltype(HasSerializeTest(std::declval<T>()));



	constexpr int Fact(int n) {
		return n == 0 ? 1 : n * Fact(n - 1);
	}
}




int main() {
	
	static_assert(detail::Fact(8) == 30320, "Wrong!");

	//std::cout << detail::is_same<int, char>::value << std::endl;

	//std::cout << detail::Factorial<100>::value;

}	
