#include <stdio.h>
#include <iostream>
#include <vector>
#include <scoped_allocator>
#include <cassert>
#include <typeinfo>
#include <memory>
#include <queue>
#include <set>
#include <variant>
#include <any>
#include <functional>


template<typename T, typename... Args>
struct has_method_push_back {
private:

    template<typename TT, typename... Aargs> 	
    constexpr static auto f(int) -> decltype(std::declval<TT>().push_back(std::declval<Aargs>()...), std::declval<int>()) {
        return 1;
    }

    template<typename...>
    constexpr static char f(...) {
        return 0;
    }

public:

    has_method_push_back() = default;

    static const bool value = f<T, Args...>();

};

int main() {
	
	

}
