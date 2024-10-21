#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> indices;
unordered_map<string, int> results;

int main() {
	int n; cin >> n;
	string guess_word; cin >> guess_word;
	for (int i=0; i<guess_word.size(); i++) {
		indices[guess_word.at(i)] = i;
	}
	results["*****"]++;
	for (int i=1; i<n; i++) {
		string curr_guess; cin >> curr_guess;
		string result;
		for(int j=0; j<curr_guess.size(); j++) {
			char curr_letter = curr_guess.at(j);
			if (indices.find(curr_letter) == indices.end()) {
				result += "X";
			} else if (indices[curr_letter] != j) {
				result += "!";
			} else {
				result += "*";
			}
		}
		results[result]++;
	}
	int n_guesses; cin >> n_guesses;
	for(int i=0; i<n_guesses; i++) {
		string guess; cin >> guess;
		cout << results[guess] << "\n";
	}
	return 0;
}
