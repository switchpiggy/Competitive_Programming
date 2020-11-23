#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m;
struct segtree {
    ll size;
    vector<ll> v;

    void init(ll x) {
        ll cur = 1;
        while(cur < x) cur *= 2;
        size = cur;
        v.assign(size * 2, 0ll);
    }

    void set(ll i, ll val, ll x, ll lx, ll rx) {
        if(rx - lx == 1) {
            v[x] = val;
            return;
        }

        if(i < (lx + rx)/2) set(i, val, 2 * x + 1, lx, (lx + rx)/2);
        else set(i, val, 2 * x + 2, (lx + rx)/2, rx);

        v[x] = v[2 * x + 1] + v[2 * x + 2];
    }

    void set(ll i, ll v) {
        set(i, v, 0, 0, size);
    }

    ll sum(ll x, ll lx, ll rx, ll l, ll r) {
        if(l >= rx || r <= lx) return 0;
        if(l <= lx && rx <= r) return v[x];

        return sum(2 * x + 1, lx, (lx + rx)/2, l, r) + sum(2 * x + 2, (lx + rx)/2, rx, l, r);
    }

    ll sum(ll l, ll r) {
        return sum(0, 0, size, l, r);
    }
};

segtree st;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   cin >> n >> m; 
   st.init(n);
   for(ll i = 0; i < n; ++i) {
       ll t;
       cin >> t;
       st.set(i, t);
   }

   for(ll i = 0; i < m; ++i) {
       ll type;
       cin >> type;
       if(type == 1) {
           ll s, c;
           cin >> s >> c;
           st.set(s, c);
       } else {
           ll l, r;
           cin >> l >> r;
           cout << st.sum(l, r) << '\n';
       }
   }

   return 0;
}