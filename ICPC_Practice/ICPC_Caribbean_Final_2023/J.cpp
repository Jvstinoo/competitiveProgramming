#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj_list;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    int n_cities; cin >> n_cities;
    adj_list.resize(n_cities+1);
    for(int i=0; i<n_cities; i++) {
        int node, node_to; cin >> node >> node_to;
        adj_list[node].push_back(node_to);
        adj_list[node_to].push_back(node);
    }

    

    return 0;
}