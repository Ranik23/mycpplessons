#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> g, g_t;

int n, m;

vector<int> order;

vector<bool> used, used2;

void dfs(int v) {
	
	used[v] = false;

	for (auto c: g[v]) {
		if (used[c]) dfs(c);
	}

	order.push_back(v);
}


void dfs2(int v, vector<int>& ans) {

	used2[v] = false;

	for (auto c: g_t[v]) {
		if (used2[c]) dfs2(c, ans);
	}

	ans.push_back(v);
}


int main() {

	std::cin >> n >> m;

	g.resize(n); g_t.resize(n); used.resize(n, true);

	used2.resize(n, true);

	for (int i = 0; i < m; ++i) {

		int a, b;

		std::cin >> a;
		std::cin >> b;

		g[a].push_back(b);

		g_t[b].push_back(a);
	}

	dfs(0);

	std::reverse(order.begin(), order.end());
		
	
	//std::cout << "Order : ";
	//for (auto a: order) std::cout << a << " ";
	//std::cout << std::endl;

	int i = 0;
	
	vector<vector<int>> b;

	while (i < n) {

		if (used2[order[i]]) {

			vector<int> ans = {};

			dfs2(order[i], ans);

			b.push_back(ans);
		}

		i += 1;
	}


	int j = 0;
	for (auto c: b) {
		std::cout << j << "-th KCC" << std::endl;
		for (auto el: c) {
			std::cout << el << " ";
		}
		std::cout << std::endl;
		j += 1;
	}
}
