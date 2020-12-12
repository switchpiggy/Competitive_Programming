#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll p[100007], n, m;
vector<ll> v[100007];

ll get(ll x) {
    return p[x];
}

void uni(ll a, ll b) {
    ll x = a, y = b;
    if(p[x] == p[y]) return;
    if((ll)v[p[x]].size() > (ll)v[p[y]].size()) swap(x, y);
    ll cur = p[x];
    for(ll i = 0; i < (ll)v[cur].size(); ++i) {
        v[p[y]].push_back(v[cur][i]);
        p[v[cur][i]] = p[y]; 
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 1; i <= n; ++i) {
        p[i] = i;
        v[i].push_back(i);
    }

    for(ll i = 0; i < m; ++i) {
        string s;
        ll a, b;
        cin >> s >> a >> b;
        if(s == "get") cout << (get(a) == get(b) ? "YES\n" : "NO\n");
        else uni(a, b);
    }

    //for(ll i = 1; i <= n; ++i) cout << p[i] << ' ';

    return 0;
}