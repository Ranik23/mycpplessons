#include <boost/type_index.hpp>
#include <vector>
#include <iostream>


template<typename T>
void f(const T& param) {

    std::cout << "T - " << boost::type_index::type_id_with_cvr<T>().pretty_name() << std::endl;
    
    std::cout << "param - " << boost::type_index::type_id_with_cvr<decltype(param)>().pretty_name() << std::endl;

  
}



class Widget;



int main() {

  std::vector<Widget> createVec();

  const auto vw = createVec();


  if (!vw.empty()) {
      f(&vw[0]);
  }
    
  return 0;
}


