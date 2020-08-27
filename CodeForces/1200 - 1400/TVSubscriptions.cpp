#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, d, t, a[200007];

int main() {
    scanf("%lld", &t);

    while(t--) {
        scanf("%lld %lld %lld", &n, &k, &d);
        for(ll i = 0; i < n; ++i) scanf("%lld", &a[i]);

        map<ll, ll> occ;
        ll distinct = 0;

        ll ans;

        for(ll i = 0; i < d; ++i) {
            occ[a[i]]++;
        }

        distinct = occ.size();
        ans = distinct;

        for(ll i = d; i < n; ++i) {
            occ[a[i - d]]--;
            if(occ[a[i - d]] == 0) distinct--;

            occ[a[i]]++;
            if(occ[a[i]] == 1) distinct++;

            ans = min(ans, distinct);
        }

        
        printf("%lld\n", ans);
    }
}