#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, p[200007], a[200007], b[200007], m, temp;
set<ll> shirts[3];

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) scanf("%lld", &p[i]);
    for(ll i = 0; i < n; ++i) scanf("%lld", &a[i]);
    for(ll i = 0; i < n; ++i) scanf("%lld", &b[i]);

    for(ll i = 0; i < n; ++i) {
        shirts[a[i] - 1].insert(p[i]);
        shirts[b[i] - 1].insert(p[i]);
    }

    scanf("%lld", &m);
    for(ll i = 0; i < m; ++i) {
        scanf("%lld", &temp);
        ll cur = *(shirts[temp - 1].begin());
        if(shirts[temp - 1].empty()) cur = -1;
        cout << cur << ' ';
        shirts[0].erase(cur);
        shirts[1].erase(cur);
        shirts[2].erase(cur);
    }

    return 0;
}