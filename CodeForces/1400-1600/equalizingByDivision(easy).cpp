#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, a[57];
map<ll, ll> occ;

int main() {
    cin >> n >> k;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    for(ll i = 0; i < n; ++i) {
        occ[a[i]]++;
        ll cur = a[i];
        while(cur) {
            cur /= 2;
            occ[cur]++;
        }
        occ[0]++;
    }

    sort(a, a + n);

    ll minn = *min_element(a, a + n);
    ll ans = INT_MAX;
    for(auto i = occ.begin(); i != occ.end(); ++i) {
        if(i->second >= k) {
            //cout << i->first << endl;
            ll res = 0, cur = 0;
            vector<ll> v(a, a + n);
            for(ll j = 0; j < v.size(); ++j) {
                ll cnt = 0;
                while(v[j] != i->first && v[j]) {
                    v[j] /= 2;
                    cnt++;
                }
                if(v[j] == i->first) {
                    res += cnt;
                    cur++;
                }
                if(cur == k) break;
            }

            ans = min(ans, res);
        }
    }

    cout << ans << endl;
    return 0;
}