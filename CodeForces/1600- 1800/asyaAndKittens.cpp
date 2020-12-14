#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, x, y, p[150007], r[150007];
vector<ll> v[150007];

ll get(ll x) { return p[x] = (p[x] == x ? x : get(p[x]));}

void uni(ll x, ll y) {
    x = get(x);
    y = get(y);
    if(r[x] == r[y]) r[x]++;
    if(r[x] > r[y]) swap(x, y);

    p[x] = y;
    for(ll i = 0; i < (ll)v[x].size(); ++i) {
        v[y].push_back(v[x][i]);
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    iota(p + 1, p + n + 1, 1);
    for(ll i = 1; i <= n; ++i) v[i].push_back(i);

    for(ll i = 0; i < n - 1; ++i) {
        ll a, b;
        cin >> a >> b;
        uni(a, b);
    }

    for(ll i = 0; i < n; ++i) cout << v[get(1)][i] << ' ';
    return 0;
}