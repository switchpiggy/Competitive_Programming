#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	vector<int> le, ri;
	int l = 0, r = s.size() - 1;
	while(l < r) {
		while(l < s.size() && s[l] == ')')
			l++;
		while(r >= 0 && s[r] == '(')
			r--;
		if(l < s.size() && r >= 0 && l < r) {
			le.push_back(l + 1);
			ri.push_back(r + 1);
			l++;
			r--;
		}
	}
	if(le.empty()) {
		cout << "0\n";
		return 0;
	}
	cout << "1\n";
	cout << 2 * le.size() << '\n';
	for(auto x : le)
		cout << x << " ";
	reverse(ri.begin(), ri.end());
	for(auto x : ri)
		cout << x << " ";
	cout << '\n';
}