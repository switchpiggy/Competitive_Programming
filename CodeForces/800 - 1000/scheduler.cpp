#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll n, m, k, t;
vector<ll> servers;

int main() {

    scanf("%lld", &t);
    for(ll count = 1; count <= t; ++count) {
    	servers.clear();
        scanf("%lld %lld %lld", &n, &k, &m);
        ll c = ceil(m/k);
        for(int i = 0; i < n; ++i) {
            ll p, s;
            scanf("%lld %lld", &p, &s);
            servers.push_back(p + (c * s));
        }
        sort(servers.begin(), servers.end());
        ll res = 0;
        ll minR = INT_MAX;
        for(ll i = 0; i < k; ++i) {
            res = max(res, servers[i]);
            minR = min(minR, servers[i]);
        }
        printf("Case #%lld: %lld\n", count, res);
    }

}