#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
vector<ll> v;
ll n, t[10][10], k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(ll i = 2; i <= n; ++i) {
        v.push_back(i);
    }

    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= n; ++j) cin >> t[i][j];
    }
    ll ans = 0;
    do {
        ll res = t[1][v[0]] + t[v.back()][1];
        for(ll i = 1; i < (ll)v.size(); ++i) res += t[v[i - 1]][v[i]];

        if(res == k) ans++;
    } while(next_permutation(v.begin(), v.end()));

    cout << ans << '\n';
    return 0;
}