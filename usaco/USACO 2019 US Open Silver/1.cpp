#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[100007], b[100007];
map<ll, ll> occ;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b, b + n);
    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        ll k = lower_bound(b, b + n, a[i]) - b;
        if(i <= k + occ[a[i]]) continue;
        ans = max(ans, i - (k + occ[a[i]]));
        occ[a[i]]++;
    }

    cout << ans + 1 << '\n';
    return 0;
}