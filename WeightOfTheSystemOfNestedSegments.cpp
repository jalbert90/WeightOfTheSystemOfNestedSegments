#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

void solve() {
	int n, m, totalWeight = 0, nEx;
	cin >> n >> m;
	nEx = m - 2 * n;

	map<int, int> mix, mxi;
	vector<pair<int, int>> wx;

	for (int i = 0; i < m; i++) {
		int x, w;
		cin >> x >> w;
		mix.insert(pair<int, int>(i + 1, x));
		mxi.insert(pair<int, int>(x, i + 1));
		wx.push_back(make_pair(w, x));
		totalWeight += w;
	}

	sort(wx.rbegin(), wx.rend());

	for (int i = 0; i < nEx; i++) {
		int maxWeightX = wx[i].second;
		int maxWeightIndex = mxi[maxWeightX];
		mxi.erase(maxWeightX);
		totalWeight -= wx[i].first;
	}

	cout << totalWeight << endl;

	map<int, int>::iterator mxiItr = mxi.begin();
	map<int, int>::reverse_iterator mxiRItr = mxi.rbegin();

	for (int i = 0; i < n; i++) {
		cout << mxiItr++->second << " " << mxiRItr++->second << endl;
	}
}

int main() {
	int t;
	cin >> t;

	for (;t--;) {
		solve();
	}
}