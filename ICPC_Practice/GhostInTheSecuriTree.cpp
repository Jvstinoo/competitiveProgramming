#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

vector<vector<int>> adjacency;

bool dfsRec(int curr_node, int target, vector<int> &path, unordered_set<int> &visited) {
    path.push_back(curr_node);
    visited.insert(curr_node);

    if(curr_node == target)
        return true;

    for (int i: adjacency[curr_node]) {
        if (visited.find(i) == visited.end()) {
            if (dfsRec(i, target, path, visited))
                return true;
        }
    }
    path.pop_back();
    return false;
}

std::vector<int> findPath(int root, int target) {
    std::vector<int> path = {};
    unordered_set<int> visited = {};
    if (dfsRec(root, target, path, visited)) {
        return path;
    }
    return {};
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int nodes, queries, root;
	cin >> nodes >> queries >> root ;
	adjacency.resize(nodes+1);
	for(int i=0; i<nodes-1; i++) {
		int u, v;
		cin >> u >> v;
		// cout << "u == " << u << "v == " << v;
		adjacency[u].push_back(v);
		adjacency[v].push_back(u);
    	}
    	for (int i=0; i<queries; i++) {
		int find, k;
		cin >> find >> k;
		std::vector<int> path = findPath(root, find);
		sort(path.begin(), path.end());
		cout << path[k-1] << "\n";
	}

	return 0;

}
