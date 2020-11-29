#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, r, c, t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
    cin >> n >> m >> r >> c;
    cout << max(abs(n - r), abs(r - 1)) + max(abs(m - c), abs(c - 1)) << '\n';
    }
    return 0;
}