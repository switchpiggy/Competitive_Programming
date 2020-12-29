#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, q, x[200007], u, k, a, b, block[2007];

void init() {
    ll sz = (ll)ceil(sqrt(n));
    for(ll i = 0; i < n; ++i) {
        block[i/sz] += x[i];
    }
}

void update(ll i, ll val) {
    ll cur = x[i], sz = (ll)ceil(sqrt(n));
    x[i] = val;
    block[i/sz] += val - cur;
}

ll query(ll l, ll r) {
    ll sz = (ll)ceil(sqrt(n)), lb = l/sz, rb = r/sz;

    if(lb == rb) {
        ll res = 0;
        for(ll i = l; i <= r; ++i) res += x[i];
        return res;
    }

    ll res = 0;
    for(ll i = rb * sz; i <= r; ++i) res += x[i];
    for(ll i = l; i < (lb + 1) * sz; ++i) res += x[i];
    for(ll i = lb + 1; i < rb; ++i) res += block[i];

    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(ll i = 0; i < n; ++i) cin >> x[i];
    init();

    for(ll i = 0; i < q; ++i) {
        ll t;
        cin >> t;
        if(t == 1) {
            cin >> k >> u;
            k--;
            update(k, u);
        } else {
            cin >> a >> b;
            cout << query(a - 1, b - 1) << '\n';
        }
    }

    return 0;
}