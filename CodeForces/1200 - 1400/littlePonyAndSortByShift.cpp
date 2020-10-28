#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    ll res = -1;
    for(ll i = 0; i < n - 1; ++i) {
        if(a[i] > a[i + 1]) {
            res = i;
        }
    }

    if(res == -1) {
        cout << 0 << '\n';
        return 0;
    }

    vector<ll> v;
    for(ll i = res + 1; i < n; ++i) v.push_back(a[i]);
    for(ll i = 0; i <= res; ++i) v.push_back(a[i]);

    for(ll i = 0; i < (ll)v.size() - 1; ++i) {
        if(v[i] > v[i + 1]) {
            cout << "-1\n";
            return 0;
        }
    }

    cout << n - 1 - res << '\n';
    return 0;
}