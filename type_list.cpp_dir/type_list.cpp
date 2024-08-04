#include <iostream>




template<typename... Types>
struct TypeList {};



template<typename... Ts, typename... Us>
constexpr bool operator==(TypeList<Ts...>, TypeList<Us...>) {
	return false;
}


template<typename... Ts>
constexpr bool operator==(TypeList<Ts...>, TypeList<Ts...>) {
	return true;
}

template<typename... Ts>
constexpr bool operator!=(TypeList<Ts...>, TypeList<Ts...>) {
	return false;
}

template<typename... Ts, typename... Us>
constexpr bool operator!=(TypeList<Ts...>, TypeList<Us...>) {
	return true;
}


template<typename... Ts>
constexpr size_t size(TypeList<Ts...>) {
	return sizeof...(Ts);	
}

template<typename Head, typename... Tail>
constexpr auto pop_front(TypeList<Head, Tail...>) {
	return TypeList<Tail...>();
}

template<typename T, typename... Types>
constexpr auto push_front(TypeList<Types...>) {
	return TypeList<T, Types...>();
}


template<typename T, typename... Types>
constexpr size_t find(TypeList<Types...>) {
	bool b[] = {std::is_same_v<T, Types>...};
	return std::find(b, b + sizeof...(Types), true) - b;
}


int main() {

	
	auto c = find<std::string>(TypeList<char, double, int, char>());
	std::cout << c << std::endl;
}
