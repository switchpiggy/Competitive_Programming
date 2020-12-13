#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, a[200007], occ[200007];

bool check(ll x) {
    ll cnt = 0;
    for(ll i = 1; i <= 200000; ++i) {
        cnt += occ[i]/x;
    }

    return cnt >= k;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        occ[a[i]]++;
    }

    //sort(occ + 1, occ + 200001, greater<ll>());

    ll l = 0, r = n + 1, ans = -1;
    while(l < r) {
        ll mid = (l + r)/2;
        if(check(mid)) {
            ans = mid;
            l = mid + 1;
        } else r = mid;
    }

    //cout << ans << '\n';
    for(ll i = 1; i <= 200000; ++i) {
        if(!k) return 0;
        ll cnt = min(k, occ[i]/ans);
        k -= cnt;
        while(cnt--) cout << i << ' ';
    }
}