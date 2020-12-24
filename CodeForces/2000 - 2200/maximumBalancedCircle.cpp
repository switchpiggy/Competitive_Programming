#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<ll> a(n), occ(200001);
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        occ[a[i]]++;
    }

    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());

    ll ans = occ[a[0]], l = 0, r = 0;
    for(ll i = 0; i < (ll)a.size(); ++i) {
        ll j = i + 1, cur = occ[a[i]];
        while(a[j] - a[j - 1] == 1 && occ[a[j]] > 1) {
            cur += occ[a[j]];
            j++;
        }

        ll rr = j - 1;
        if(j < n && a[j] - a[j - 1] == 1) {
            rr = j;
            cur += occ[a[j]];
        }

        if(ans < cur) {
            ans = cur;
            l = i;
            r = rr;
        }

        i = j - 1;
    }    

    cout << ans << '\n';
    for(ll i = 0; i < occ[a[l]]; ++i) cout << a[l] << ' ';
    for(ll j = l + 1; j < r; ++j) {
        for(ll i = 0; i < occ[a[j]] - 1; ++i) cout << a[j] << ' ';
    }

    if(l != r) for(ll i = 0; i < occ[a[r]]; ++i) cout << a[r] << ' ';
    for(ll i = r - 1; i > l; --i) cout << a[i] << ' ';

    return 0;
}