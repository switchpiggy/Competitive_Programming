#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a, b, nxt[1000007], occ[1000007];
vector<ll> u;
vector<ll> v;

bool visited[1000007], is[1000007];

void dfs(ll x) {
    visited[x] = 1;
    u.push_back(x);

    if(nxt[x] > 0) dfs(nxt[x]);

    return;
}

void dfs2(ll x) {
    v.push_back(x);

    if(nxt[x] > 0) dfs2(nxt[x]);

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    ll start = 0;
    for(ll i = 0; i < n; ++i) {
        cin >> a >> b;

        if(a == 0) start = b;
        if(b != 0) nxt[a] = b;

        is[a] = is[b] = 1;
    }

    //cout << start << '\n';

    dfs(start);

    for(ll i = 1; i <= 1000000; ++i) occ[nxt[i]]++;

    for(ll i = 1; i <= 1000000; ++i) {
        if(!visited[i] && !occ[i] && is[i]) {
            dfs2(i);
            break;
        }
    }

    for(ll i = 0; i < (ll)v.size() && i < (ll)u.size(); ++i) {
        cout << v[i] << ' ' << u[i] << ' ';
    }

    if((ll)v.size() > (ll)u.size()) cout << v.back() << '\n';

    return 0;
}