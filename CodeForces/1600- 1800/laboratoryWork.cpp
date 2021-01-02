#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, x[100007], a[100007], occ[3];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ll maxn = LLONG_MIN, minn = LLONG_MAX;
    for(ll i = 0; i < n; ++i) {
        cin >> x[i];
        maxn = max(maxn, x[i]);
        minn = min(minn, x[i]);
    }

    if(maxn == minn || maxn - minn == 1) {
        cout << n << '\n';
        for(ll i = 0; i < n; ++i) cout << x[i] << ' ';
        cout << '\n';
        return 0;
    }

    for(ll i = 0; i < n; ++i) {
        a[i] = x[i] - minn;
        occ[a[i]]++;
    }

    if(occ[1] + abs(occ[0] - occ[2]) < occ[0] + occ[2] + occ[1]%2) {
        ll res = occ[1] + abs(occ[0] - occ[2]);
        cout << res << '\n';
        ll left = min(occ[0], occ[2]);
        for(ll i = 0; i < n; ++i) {
            if(a[i] == 0 && left) {
                a[i] = 1;
                x[i] = minn + 1;
                left--;
            }
        }

        left = min(occ[0], occ[2]);
        for(ll i = 0; i < n; ++i) {
            if(a[i] == 2 && left) {
                a[i] = 1;
                x[i] = minn + 1;
                left--;
            }
        }

        for(ll i = 0; i < n; ++i) cout << x[i] << ' ';
    } else {
        ll res = occ[0] + occ[2] + occ[1]%2;
        cout << res << '\n';
        ll left = occ[1]/2;
        for(ll i = 0; i < n; ++i) {
            if(a[i] == 1 && left) {
                a[i] = 0;
                x[i] = minn;
                left--;
            }
        }

        left = occ[1]/2;
        for(ll i = 0; i < n; ++i) {
            if(a[i] == 1 && left) {
                a[i] = 2;
                x[i] = minn + 2;
                left--;
            }
        }

        for(ll i = 0; i < n; ++i) cout << x[i] << ' ';
    }

    return 0;
}