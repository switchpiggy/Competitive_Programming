#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll p[300007], minn[300007], maxn[300007], sz[300007], n, m;

ll get(ll x) {
    return p[x] = (p[x] == x ? x : get(p[x]));
}

void uni(ll x, ll y) {
    x = get(x);
    y = get(y);
    if(x == y) return;
    if(sz[x] <= sz[y]) {
        p[x] = y;
        sz[y] += sz[x];
        maxn[y] = max(maxn[y], maxn[x]);
        minn[y] = min(minn[y], minn[x]);
    } else {
        p[y] = x;
        sz[x] += sz[y];
        maxn[x] = max(maxn[y], maxn[x]);
        minn[x] = min(minn[x], minn[y]);
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 1; i <= n; ++i) {
        sz[i] = 1;
        maxn[i] = minn[i] = i;
        p[i] = i;
    }

    for(ll i = 0; i < m; ++i) {
        string s;
        ll a, b;
        cin >> s;
        if(s == "get") {
            cin >> a;
            ll cur = get(a);
            cout << minn[cur] << ' ' << maxn[cur] << ' ' << sz[cur] << '\n';
        } else {
            cin >> a >> b;
            uni(a, b);
        }
    }
}