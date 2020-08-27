#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, k, d[107], res[107];
vector<ll> ans;

int main() {
    scanf("%lld %lld %lld", &n, &m, &k);
    for(ll i = 1; i <= m; ++i) scanf("%lld", &d[i]);
    for(ll i = 0; i < k; ++i) {
        ll temp;
        scanf("%lld", &temp);

        for(ll i = 1; i <= m; ++i) {
            if(temp%d[i] == 0) res[i]++;
        }
    }

    ll mins = INT_MAX;
    for(ll i = 1; i <= m; ++i) mins = min(mins, res[i]);

    for(ll i = 1; i <= m; ++i) {
        if(res[i] == mins) ans.push_back(i);
    }

    printf("%lld\n", (ll)ans.size());
    for(ll i = 0; i < ans.size(); ++i) printf("%lld ", ans[i]);

    return 0;
}