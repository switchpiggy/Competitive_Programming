#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, a[1007][1007], r[1007], c[1007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= m; ++j) {
            cin >> a[i][j];
            r[i] += a[i][j];
            c[j] += a[i][j];
        }
    }

    ll rows = LLONG_MAX, cols = LLONG_MAX, curR = -1, curC = -1;
    for(ll i = 1; i <= n + 1; ++i) {
        ll cur = 4 * (i - 1), res = 0;
        for(ll j = 1; j <= n; ++j) {
            res += abs(cur - (4 * j - 2)) * abs(cur - (4 * j - 2)) * r[j];
        }

        if(res < rows) {
            rows = res;
            curR = i - 1;
        }
    }

    for(ll i = 1; i <= m + 1; ++i) {
        ll cur = 4 * (i - 1), res = 0;
        for(ll j = 1; j <= m; ++j) {
            res += abs(cur - (4 * j - 2)) * abs(cur - (4 * j - 2)) * c[j];
        }

        if(res < cols) {
            cols = res;
            curC = i - 1;
        }
    }

    cout << rows + cols << '\n' << curR << ' ' << curC << '\n';
    return 0;
}