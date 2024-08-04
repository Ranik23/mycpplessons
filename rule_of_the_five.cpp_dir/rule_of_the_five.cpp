#include <string>
#include <utility>



template<typename T>
class Auto {

	private:

		std::string name_;

	public:

		Auto(const std::string name) {
			name_ = name;
		}

		Auto(const Auto<T>& other) : name_(other.name_) {}
			

		Auto(Auto<T>&& other) : name_(std::move(other.name_)) {}
	

		Auto<T>& operator=(const Auto<T>& other) {
			if (this != &other) {
				name_ = other.name_;
			}

			return *this;
		}

		Auto<T>& operator=(Auto<T>&& other) {
			if (this != &other) {
				name_ = std::move(other.name_);
			}

			return *this;
		}
};


template<typename T>
class Bmw: public Auto<T> {
	private:
		
		int price;

	public:

		Bmw(const std::string name_, int price_) : Auto<T>(name_) {
			price = price_; 
		}

};




int main() {

	Bmw<int> c("X5", 1000);

	auto e = c;

}
