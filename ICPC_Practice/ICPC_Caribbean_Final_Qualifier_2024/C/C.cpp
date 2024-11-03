// Problem: https://matcomgrader.com/problem/9770/connecting-modules/

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int out = 0;
	int modules; cin >> modules;
	vector<vector<int>> adj_modules(modules+1);
	bool streaming_modules[modules+1];
	std::fill(streaming_modules, streaming_modules + modules + 1, false);

	for (int i=0; i<modules; i++) {
		int streaming; cin >> streaming;
		streaming_modules[i+1] = streaming;
		int connected_modules; cin >> connected_modules;
		for (int j=0; j<connected_modules; j++) {
			int connected_to; cin >> connected_to;
			adj_modules[i+1].push_back(connected_to);
		}
	}
	for (int i=0; i<modules; i++) {
		if (streaming_modules[i+1]) {
			bool visited[modules+1];
			std::fill(visited, visited + modules + 1, false);
			stack<int> dfs;
			dfs.push(i+1);
			while(!dfs.empty()) {
				bool can_break = false;
				int top = dfs.top(); dfs.pop();
				for (int connected_modules: adj_modules[top]) {
					if (visited[connected_modules] == false) {
						if (streaming_modules[connected_modules] == true) {
							out+=1;
							can_break = true;
							break;
						}
						dfs.push(connected_modules);
					}
				}
				if (top != i+1)
					visited[top] = true;
				if (can_break)
					break;
			}		
		}
	}
	cout << out;
	return 0;
}

