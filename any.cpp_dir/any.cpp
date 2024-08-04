#include <iostream>
#include <vector>
#include <cmath>
#include <typeinfo>
#include <type_traits>


class any {

	public:

		template<typename T>
			any(const T& value) {
				ptr = new holder<T>(value);
		}


		const std::type_info& get_type() const {
			return ptr->get_info();
		}
		
		template<typename U>
			U get_data() {

    			if constexpr (std::is_same_v<U, decltype(dynamic_cast<holder<U>*>(ptr->get())->data)>) {
        			return dynamic_cast<holder<U>*>(ptr->get())->data;
				} else {
					
					throw std::out_of_range("error");
				}
		}

	private:
		
		struct base_holder {
			
			virtual const std::type_info& get_info() const = 0;

			virtual base_holder* get() = 0;
		};


		template<typename T>
			struct holder : base_holder {

				explicit holder(const T& value) : data(value) {}
				
				const std::type_info& get_info() const override {
					return typeid(data);
				}

				holder* get() override {
					return this;
				}

				T data;

			}; 
		
		base_holder* ptr;

};


int main() {

	any aa(10);

	std::cout << aa.get_data<int>() << std::endl;

}



