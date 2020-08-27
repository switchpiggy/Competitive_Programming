#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

const ll mxn = 57;
ll n, m, row[mxn], col[mxn], a, b, c, ans;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n >> m;
    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= m; ++j) {
            ll temp;
            cin >> temp;
            row[i] += temp;
            col[j] += temp;
        }
    }

    cin >> a >> b >> c;

    for(ll i = 1; i <= n; ++i) row[i] += row[i - 1];
    for(ll i = 1; i <= m; ++i) col[i] += col[i - 1];

    vector<ll> v({a, b, c});
    sort(v.begin(), v.end());

    for(ll i = 1; i <= n - 1; ++i) {
        for(ll j = i + 1; j <= n - 1; ++j) {
            ll aa = row[i], bb = row[j] - row[i], cc = row[n] - row[j];
            vector<ll> u({aa, bb, cc});
            sort(u.begin(), u.end());

            if(v == u) ans++;
        }
    }

    for(ll i = 1; i <= m - 1; ++i) {
        for(ll j = i + 1; j <= m - 1; ++j) {
            ll aa = col[i], bb = col[j] - col[i], cc = col[m] - col[j];
            vector<ll> u({aa, bb, cc});
            sort(u.begin(), u.end());

            if(v == u) ans++;
        }
    }

    cout << ans << endl;
    return 0;
}