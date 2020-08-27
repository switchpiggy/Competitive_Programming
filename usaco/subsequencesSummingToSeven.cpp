#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, pref[50007], a, ans = INT_MIN;
set<ll> pos[7];

int main() {
    scanf("%lld", &n);
    pref[0] = 0;
    for(ll i = 1; i <= n; ++i) scanf("%lld", &pref[i]);

    for(ll i = 1; i <= n; ++i) {
        pref[i] += pref[i - 1];
        pref[i] %= 7;
    }

    for(ll i = 1; i <= n; ++i) pos[pref[i]].insert(i);

    for(ll i = 0; i < 7; ++i) {
        if(pos[i].empty()) continue;
        ans = max(ans, *(pos[i].rbegin()) - *(pos[i].begin()));
    }

    printf("%lld\n", ans);

    return 0;
}