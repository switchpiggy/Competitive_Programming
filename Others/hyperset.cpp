
#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 1501;
string S[maxn];
set <string> T;
 
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> S[i];
		T.insert(S[i]);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			string s = "";
			for (int l = 0; l < k; l++) {
				if (S[i][l] == S[j][l])
					s += S[i][l];
				else if (S[i][l] != 'S' && S[j][l] != 'S')
					s += 'S';
				else if (S[i][l] != 'E' && S[j][l] != 'E')
					s += 'E';
				else
					s += 'T';
			}
			if (T.find(s) != T.end())
				ans++;
		}
	}
	cout << ans / 3;
}