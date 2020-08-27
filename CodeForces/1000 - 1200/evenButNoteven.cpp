#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        int odd = 0;
        for (char c : s) if ((c - '0') & 1) odd++;
        if (odd <= 1) { cout << "-1\n"; continue; }
        int cnt = 0;
        for (char c : s) {
            if ((c - '0') & 1) { cout << c; cnt++; }
            if (cnt == 2) break;
        }
        cout << '\n';
    }
    return 0;
}