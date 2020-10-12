#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, r, s[1007], b[1007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> r;
    for(ll i = 0; i < n; ++i) cin >> s[i];
    for(ll i = 0; i < m; ++i) cin >> b[i];

    ll minn = INT_MAX, maxn = INT_MIN;
    for(ll i = 0; i < n; ++i) minn = min(minn, s[i]);
    for(ll i = 0; i < m; ++i) maxn = max(maxn, b[i]);

    if(maxn <= minn) {
        cout << r << '\n';
        return 0;
    }

    cout << (r/minn) * maxn + r%minn << '\n';
    return 0;
}