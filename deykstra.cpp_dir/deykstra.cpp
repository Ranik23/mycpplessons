#include <iostream>
#include <vector>
#include <queue>


template<typename T>
struct deykstra {
	public:

		deykstra(const std::vector<T> &data) {	
			graph = data;
			count = data.size();
		}

		void action() {
		
			vector<int> dist(count, INT_MAX);
			std::queue<int> q;
			
			q.push(0);


			while (!q.empty()) {
				

			}
		}


	private:
		
		std::vector<T> graph;
		int count;
		



};







int main() {

	
	deykstra<int> variable(std::vector<int>());

	return 0;


}
