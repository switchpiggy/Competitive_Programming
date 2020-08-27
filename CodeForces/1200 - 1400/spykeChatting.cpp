#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, k, res[20007], num[11];
vector<ll> v[11];

int main() {
    scanf("%lld %lld %lld", &n, &m, &k);
    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= m; ++j) {
            ll temp;
            scanf("%lld", &temp);
            if(temp) v[j].push_back(i);
        }
    }

    for(ll i = 0; i < k; ++i) {
        ll x, y;
        scanf("%lld %lld", &x, &y);
        res[x]--;
        num[y]++;
    }

    for(ll i = 1; i <= m; ++i) {
        for(ll j = 0; j < v[i].size(); ++j) {
            res[v[i][j]] += num[i];
        }
    }

    for(ll i = 1; i <= n; ++i) printf("%lld ", res[i]);
    return 0;
}