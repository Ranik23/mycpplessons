#include <utility>
#include <memory>



std::weak_ptr<int> foo() {

      int a = 10;

      return a;
}




int main() {

    
    auto c = foo();


    return 0;

}
