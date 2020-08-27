#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, t, k;
vector<ll> v[200007];

int main() {
    scanf("%lld", &t);

    while(t--) {
        scanf("%lld %lld", &n, &k);
        ll a[n], w[k];
        for(ll i = 0; i < n; ++i) scanf("%lld", &a[i]);
        for(ll i = 0; i < k; ++i) scanf("%lld", &w[i]);
        for(ll i = 0; i <= n; ++i) v[i].clear();

        sort(a, a + n);
        sort(w, w + k, greater<ll>());

        ll p = 0;

        for(ll i = 0; i < n - k; ++i) {
            while(w[p] == v[p].size() + 1) p++;
            v[p].push_back(a[i]);
        }

        ll ans = 0, qf = 1;

        for(ll i = 0; i < k; ++i) {
            ans += a[n - 1 - i];
            if(v[i].size()) ans += v[i][0];
            else {
                ans += a[n - qf];
                qf++;
            } 
        }

        printf("%lld\n", ans);
    }

    return 0;
}