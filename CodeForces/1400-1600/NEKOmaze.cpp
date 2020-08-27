#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int n, q;
vector<vector<int>> lava;

void Input() {
	cin >> n >> q;
	lava.resize(2, vector<int>(n, 0));
}

void Solve() {
	int blockedPair = 0;
	while (q--) {
		int x, y; cin >> x >> y; x--; y--;
		int delta = (lava[x][y] == 0) ? +1 : -1;

		lava[x][y] = 1 - lava[x][y];
		for (int dy=-1; dy<=1; dy++) {
			if (y+dy < 0 || y+dy >= n) continue;

			if (lava[1-x][y+dy] == 1) blockedPair += delta;
		}

		cout << ((blockedPair == 0) ? "Yes\n" : "No\n");
	}
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}