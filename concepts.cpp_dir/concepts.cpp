#include <iostream>
#include <type_traits>


namespace detail {

	template<bool B>
		using bool_constant = std::integral_constant<bool, B>;

	template<typename T, typename U>
		struct is_same : std::false_type {};


	template<typename T>
		struct is_same<T, T> : std::true_type {};

	template<typename T>
		struct is_intergal : std::integral_constant<bool,
							 requires (T t, T* p, void(*f)(T)) {
								 p + t;
								 f(0);
								 reinterpret_cast<T>(t);
							 }> {};


	template<typename T>
		struct is_string : std::is_same<T, std::string> {};



	template<typename T>
		struct is_object : std::integral_constant<bool,
								std::is_scalar<T>::value || 
								std::is_array<T>::value ||
								std::is_union<T>::value ||
								std::is_class<T>::value> {};


	template<class Derived, class Base>
		concept derived_from = std::is_base_of_v<Base, Derived> && std::is_convertible_v<const volatile Derived*, const volatile Base*>;

}

struct A {};

struct B : A {};

struct CC {};

template<detail::derived_from<A> T>
	class C {

		public:
			C() {};

};


int main() {
	
	
	C<B> a;

	C<CC> b;



}
