#include <iostream>
#include <functional>
#include <utility>




std::pair<int, int> solution(const std::vector<int>& v, int n) {


	int l = 0, r = 0;
	
	int maximal = 1;
	
	std::pair<int, int> answer = std::pair<int, int>(l, l);

	while (r < n) {

		if (v[r + 1] >= v[r]) {
			r += 1;
		}else {
			
			maximal = std::max(maximal, r - l + 1);
			if (maximal == r - l + 1) answer = std::pair<int, int>(l, r);

			r += 1;
			l = r;
		}
	}

	maximal = std::max(maximal, r - l + 1);
	if (maximal == r - l + 1) answer = std::pair<int, int>(l, r);

	return answer;

}









int main() {

	std::vector<int>().construct();
}
