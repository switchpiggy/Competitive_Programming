#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, p[100007], sz[100007], cnt, maxn;

ll get(ll x) {return p[x] = (p[x] == x ? x : get(p[x]));}

void uni(ll x, ll y) {
    x = get(x);
    y = get(y);
    if(sz[x] > sz[y]) swap(x, y);

    p[x] = y;
    cnt--;
    sz[y] += sz[x];
    maxn = max(maxn, sz[y]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    iota(p + 1, p + n + 1, 1);
    for(ll i = 1; i <= n; ++i) sz[i] = 1;
    cnt = n, maxn = 1;

    for(ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        if(get(a) != get(b)) uni(a, b);

        cout << cnt << ' ' << maxn << '\n';
    }

    return 0;
}