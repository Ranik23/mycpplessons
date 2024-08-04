#include <iostream>

template<typename T>
void a(T&& p) {
  std::cout << "Right" << std::endl;
}

template<typename T>
void a(T& p) {
  std::cout << "Left" << std::endl;
}

template<typename T>
void f(T&& param) {
    a(std::forward<T>(param));
}

int main() {

    f(20);
}
