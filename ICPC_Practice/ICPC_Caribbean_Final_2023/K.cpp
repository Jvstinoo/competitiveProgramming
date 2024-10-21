#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

vector<vector<int>> adj_list;
vector<vector<int>> permutations;

bool inPerm(vector<int> &nums, int start_at) {
    for (vector<int> perm: permutations) {
        bool inIt = true;
        if (perm.size() > nums.size()) {
            inIt = false;
	    break;
	}
        for (int i=0, j=start_at; j<nums.size(); j++) {
            if (perm[i] != nums[j])
                inIt = false;
	    	break;
        }
        if (!inIt) {
            for (int j: perm) {
                cout << j << " ";
            }
            return false;
        }
    }
    return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, n_permutations; cin >> n >> n_permutations;
	vector<int> perms;

	for(int i=1;i<n_permutations+1;i++) {
		perms.push_back(i);
	}
	do {
		permutations.push_back(perms);
	} while (next_permutation(perms.begin(), perms.end()));

	vector<int> nums;
	int start_at = 0;
	for (int i=0; i<n; i++) {
		int k; cin >>k;
		nums.push_back(k);
		if (nums.size() >= n_permutations) {
		    if (!inPerm(nums,start_at)) {
			return 0;
		    }
		    start_at ++;
		}
	}
	cout << "*";
	return 0;
	}
