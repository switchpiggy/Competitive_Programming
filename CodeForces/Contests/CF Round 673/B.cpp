#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, a[100007], k, ans[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        memset(ans, 0, sizeof(ans));
        cin >> n >> k;
        for(ll i = 0; i < n; ++i) cin >> a[i];

        vector<ll> v;

        for(ll i = 0; i < n; ++i) {
            if(a[i] < k/2) ans[i] = 1;
            if(a[i] > k/2) ans[i] = 2;
            if(a[i] == k/2) {
                if(k%2 == 0) v.push_back(i);
                else ans[i] = 1;
            }
        }

        ll cur = 1;
        for(ll i = 0; i < (ll)v.size(); ++i) {
            ans[v[i]] = cur;
            cur = 3 - cur;
        }

        for(ll i = 0; i < n; ++i) cout << ans[i] - 1 << ' ';
        cout << '\n';
    }

    return 0;
}