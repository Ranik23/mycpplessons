#include <iostream>
#include <type_traits>



class Widget {

  public:

      Widget(int i, double b) {
        std::cout << "Default constructor 1" << std::endl;
      }

      Widget(int i, bool b) {
        std::cout << "Default constructor 2" << std::endl;
      }

      Widget(std::initializer_list<long double> il) {
        std::cout << "initializer_list constructor" << std::endl;
      }
};



class Widget2 {

  public:
      
    Widget2() {
      std::cout << "Empty constructor" << std::endl;
    }

    Widget2(std::initializer_list<int> il) {
      std::cout << "initializer_list constructor" << std::endl;
    }      
};


int main() {
  
    double x = 5.0, y = 4.0, z = 10.0;

    int sum{x + y + z}; // не позволяет сделать неявное преобразование типов
    
    int sum2(x + y + z);
    
    auto test{1 + 2 + 3 + 4};

    std::cout << std::is_same_v<decltype(test), int> << std::endl;

    std::cout << sum << std::endl;



    Widget w1{10, "adfwef"}; // когда есть конструктор с initializer_list, лучше не использовать фигурные скобки в создании объектов этого типа


    Widget2 w2{}; // когда есть пустой конструктор без аргументов и конструктор с initializer_list, то в данном случае будет вызываться первое

    return 0;
}
