#include <iostream>
#include <type_traits>
#include <utility>


//basic reflection in c++ using constexpr functions


struct ubiq {
	template<class Type>
		constexpr operator Type&() const;
};

template<size_t Index>
using ubiq_constructor = ubiq;


template<class T, size_t I0, size_t... I>
auto detect_fields_count(size_t& out, std::index_sequence<I0, I...>)
	-> decltype(T {ubiq_constructor<I0>{}, ubiq_constructor<I>{}...}, throw 1) { // agregate initialization
		out = sizeof...(I) + 1;
	}

template<class T, size_t... I>
auto detect_fields_count(size_t& out, std::index_sequence<I...>) {
	detect_fields_count<T>(out, std::make_index_sequence<sizeof...(I) - 1>{});
}


struct A {
	int a;
	double d;
	std::string c;
};

int main() {

	size_t x = 0;

	detect_fields_count<A>(x, std::make_index_sequence<100>());

	std::cout << x << std::endl;
}
