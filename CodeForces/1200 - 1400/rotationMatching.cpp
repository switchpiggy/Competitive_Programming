#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, temp;
map<ll, ll> pos;
map<ll, ll> shifts;

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) {
        scanf("%lld", &temp);
        pos[temp] = i;
    }

    for(ll i = 0; i < n; ++i) {
        scanf("%lld", &temp);
        ll diff = i - pos[temp];
        shifts[diff]++;
        shifts[-1 * (n - diff)]++;
    }

    ll maxn = 0;
    for(auto itr = shifts.begin(); itr != shifts.end(); ++itr) {
        maxn = max(maxn, itr->second);
    }

    printf("%lld\n", maxn);
}