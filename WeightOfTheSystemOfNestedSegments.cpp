#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

void solve() {
	int n, m, totWeight = 0;
	cin >> n >> m;

	map<int, int> mx;
	map<int, int> mw;
	map<int, int> mxw;
	map<int, int> mxi;

	for (int i = 0; i < m; i++) {
		int x, w;
		cin >> x >> w;
		mx.insert(pair<int, int>(i + 1, x));
		mw.insert(pair<int, int>(i + 1, w));
		mxw.insert(pair<int, int>(x, w));
		mxi.insert(pair<int, int>(x, i + 1));
		totWeight += w;
	}

	int nEx = m - 2 * n;

	map<int, int>::iterator itx;
	map<int, int>::iterator itw;
	map<int, int>::iterator itxw;
	map<int, int>::iterator itxi;

	for (int i = 0; i < nEx; i++) {
		itw = max_element(mw.begin(), mw.end(), [](const auto& x, const auto& y) {return x.second < y.second;});
		int maxWeightIndex = itw->first;
		int maxWeightX = mx[maxWeightIndex];
		totWeight -= itw->second;
		mx.erase(maxWeightIndex);
		mw.erase(maxWeightIndex);
		mxw.erase(maxWeightX);
		mxi.erase(maxWeightX);
	}

	cout << totWeight << endl;

	itxw = mxw.begin();
	map<int, int>::reverse_iterator ritxw = mxw.rbegin();

	for (int i = 0; i < n; i++) {
		int xFirst, xLast;
		xFirst = itxw->first;
		xLast = ritxw->first;
		cout << mxi[xFirst] << " " << mxi[xLast] << endl;
		xFirst = itxw++->first;
		xLast = ritxw++->first;
	}
}

int main() {
	int t;
	cin >> t;

	for (;t--;) {
		solve();
	}
}