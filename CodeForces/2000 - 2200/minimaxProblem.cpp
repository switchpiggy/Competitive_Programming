#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define benqueue queue
#define pbenqueue priority_queue
ll n, m, a[300007][9], x, y;

bool check(ll q) {
    vector<ll> v((1 << m), -1);
    for(ll i = 0; i < n; ++i) {
        ll cur = 0;
        for(ll j = 0; j < m; ++j) {
            if(a[i][j] >= q) cur += (1 << j);
        }

        v[cur] = i;
    }

    if(v[(1 << m) - 1] != -1) {
        x = y = v[(1 << m) - 1];
        return 1;
    }

    for(ll i = 0; i < (1 << m); ++i) {
        for(ll j = 0; j < (1 << m); ++j) {
            if(v[i] != -1 && v[j] != -1 && (i | j) == (1 << m) - 1) {
                x = v[i], y = v[j];
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) cin >> a[i][j];
    }

    ll l = 0, r = 1e9 + 7;
    while(l < r) {
        ll mid = (l + r)/2;
        if(check(mid)) {
            l = mid + 1;
        } else r = mid;
    }

    cout << x + 1 << ' ' << y + 1 << '\n';
    return 0;
}