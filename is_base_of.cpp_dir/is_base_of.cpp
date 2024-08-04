#include <iostream>
#include <vector>
#include <type_traits>


class B {};

class A : public B {};

template<typename A, typename B>
auto is_base_of_helper(A*) -> std::true_type;

template<typename A, typename B>
auto is_base_of_helper(...) -> std::false_type;

template<typename A, typename B>
struct is_base_of : std::conjunction<
                       std::is_class<A>,
                       std::is_class<B>,
                       decltype(is_base_of_helper<A, B>(static_cast<B*>(nullptr)))>
{};

int main() {

    std::cout << is_base_of<B, A>::value << std::endl;
    return 0;
}



