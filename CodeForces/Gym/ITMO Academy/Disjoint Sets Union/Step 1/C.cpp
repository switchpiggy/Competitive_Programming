#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, p[200007], sub[200007], r[200007], res[200007];

ll get(ll x) {
    if(x == p[x]) return x;
    return get(p[x]);
}

void uni(ll x, ll y) {
    x = get(x);
    y = get(y);
    if(x == y) return;
    if(r[x] == r[y]) r[x]++;
    if(r[x] > r[y]) swap(x, y);
    p[x] = y;
    sub[x] = res[y];
}

ll sum(ll x) {
    if(x == p[x]) return res[x];
    return res[x] - sub[x] + sum(p[x]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for(ll i = 1; i <= n; ++i) {
        p[i] = i;
    }

    while(m--) {
        string s;
        cin >> s;
        if(s == "add") {
            ll a, b;
            cin >> a >> b;
            res[get(a)] += b;
        } else if(s == "join") {
            ll a, b;
            cin >> a >> b;
            uni(a, b);
        } else {
            ll a;
            cin >> a;
            cout << sum(a) << '\n';
        }
    }

    return 0;
}