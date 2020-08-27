#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, a, ans = 0;
map<ll, vector<ll>> occ;

int main() {
    scanf("%lld %lld", &n, &k);
    for(ll i = 0; i < n; ++i) {
        scanf("%lld", &a);
        occ[a].push_back(i);
    }

    for(auto itr = occ.begin(); itr != occ.end(); ++itr) {
        if(itr->second.empty()) continue;
        for(ll i = 1; i < itr->second.size(); ++i) {
            if(itr->second[i] - itr->second[i - 1] <= k) ans = max(ans, itr->first);
        }
    }

    printf("%lld\n", ans);

    return 0;
}