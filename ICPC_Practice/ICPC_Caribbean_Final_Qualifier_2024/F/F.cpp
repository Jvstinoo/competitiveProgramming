//https://matcomgrader.com/problem/9773/family-spy/

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int points, translations; cin >> points >> translations;
	int64_t point_sum[2] = {0,0};
	for (int i=0; i<points; i++) {
		int64_t x,y; cin >> x >> y;
		point_sum[0] += x;
		point_sum[1] += y;
	}
	for (int i=0; i<translations; i++) {
		int64_t trans_x, trans_y; cin >> trans_x >> trans_y;
		point_sum[0] += (points * trans_x);
		point_sum[1] += (points * trans_y);
		cout << point_sum[0] << " " << point_sum[1] << "\n";
	}
	return 0;
}

