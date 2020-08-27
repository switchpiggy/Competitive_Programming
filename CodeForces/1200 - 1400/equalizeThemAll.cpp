#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[200007];
map<ll, ll> occ;
queue<ll> pos;
vector<pair<ll, pair<ll, ll>>> res;

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
        occ[a[i]]++;
    }
    pair<ll, ll> maxn;
    for(auto i = occ.begin(); i != occ.end(); ++i) {
        if(i->second > maxn.second) {
            maxn.second = i->second;
            maxn.first = i->first;
        }
    }

    for(ll i = 0; i < n; ++i) {
        if(a[i] == maxn.first) pos.push(i);
    }

    while(!pos.empty()) {
        ll f = pos.front();
        pos.pop();

        if(f < n - 1 && a[f + 1] != maxn.first) {
            if(a[f + 1] > maxn.first) res.push_back(make_pair(2, make_pair(f + 1, f)));
            else res.push_back(make_pair(1, make_pair(f + 1, f)));

            a[f + 1] = maxn.first;
            pos.push(f + 1);
        }

        if(f > 0 && a[f - 1] != maxn.first) {
            if(a[f - 1] > maxn.first) res.push_back(make_pair(2, make_pair(f - 1, f)));
            else res.push_back(make_pair(1, make_pair(f - 1, f)));

            a[f - 1] = maxn.first;
            pos.push(f - 1);
        }
    }

    printf("%lld\n", (ll)res.size());
    for(ll i = 0; i < res.size(); ++i) {
        printf("%lld %lld %lld", res[i].first, res[i].second.first + 1, res[i].second.second + 1);
        printf("\n");
    }

    return 0;
}