#include <vector>
#include <deque>



template<typename Container, typename Index>
auto authAndAccess(Container& c, Index i) -> decltype(c[i]) {
    return c[i];
}



decltype(auto) f1() {

  int x = 0;


  return x; // просто возвращает по значению 
}


decltype(auto) f2() {
    
    int x = 0;


    return (x); // вернет по ссылку, то есть int& и будет висячая ссылка
}


std::vector<int> arr = {1, 2, 3, 3};

auto getElement(int index = 0) { // auto убирает любую ссылочность
    return arr[index];
}








int main() {
    

    getElement() = 10;
}
