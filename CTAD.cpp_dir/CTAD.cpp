#include <utility>



namespace detail {


	template<typename T1, typename T2>
		std::pair<T1, T2> make_pair(T1 x, T2 y) {
			return std::pair<T1, T2>(std::forward(x), std::forward(y));
		}
}


int main() {



	auto pair = detail::make_pair(4, 5);


}
