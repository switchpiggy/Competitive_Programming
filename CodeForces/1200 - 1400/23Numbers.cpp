#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll l, r;
vector<ll> twos;
vector<ll> threes;
set<ll> products;

int main() {
    scanf("%lld %lld", &l, &r);
    ll cur = 1;
    for(ll i = 0; i <= 30; ++i) {
        twos.push_back(cur);
        cur *= 2;
    }

    ll curr = 1;
    for(ll i = 0; i <= 19; ++i) {
        threes.push_back(curr);
        curr *= 3;
    }

    for(ll i = 0; i <= 30; ++i) {
        for(ll j = 0; j <= 19; ++j) products.insert(twos[i] * threes[j]);
    }

    ll res = 0;
    for(auto itr = products.begin(); itr != products.end(); ++itr) {
        if(*itr >= l && *itr <= r) res++;
    }

    printf("%lld\n", res);

    return 0;
}