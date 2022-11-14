#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

void solve() {
	int n, m, totWeight = 0, nEx;
	cin >> n >> m;
	nEx = m - 2 * n;

	map<int, int> mix, mxw;
	pair<int, int>* wx = new pair<int, int>[m];

	for (int i = 0; i < m; i++) {
		int x, w;
		cin >> x >> w;
		mix.insert(pair<int, int>(i + 1, x));
		mxw.insert(pair<int, int>(x, w));
		wx[i].first = w;
		wx[i].second = x;
	}

	sort(wx, wx + m, greater<int>());

	delete[] wx;
}

int main() {
	int t;
	cin >> t;

	for (;t--;) {
		solve();
	}
}