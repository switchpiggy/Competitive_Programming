#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m;

struct node {
    ll m, c;
};

struct segtree {
    ll size;
    vector<node> v;

    node merge(node a, node b) {
        if(a.m < b.m) return a;
        if(a.m > b.m) return b;
        return {a.m, a.c + b.c};
    }

    void init(ll x) {
        ll cur = 1;
        while(cur < x) cur *= 2;
        size = cur;
        v.assign(size * 2, {INT_MAX, 0});
    }

    void set(ll i, ll val, ll x, ll lx, ll rx) {
        if(rx - lx == 1) {
            v[x] = {val, 1};
            return;
        }

        if(i < (lx + rx)/2) set(i, val, 2 * x + 1, lx, (lx + rx)/2);
        else set(i, val, 2 * x + 2, (lx + rx)/2, rx);

        v[x] = merge(v[2 * x + 1], v[2 * x + 2]);
    }

    void set(ll i, ll v) {
        set(i, v, 0, 0, size);
    }

    ll min(ll x, ll lx, ll rx, ll l, ll r) {
        if(rx <= l || lx >= r) return INT_MAX;
        if(l <= lx && rx <= r) return v[x].m;

        return min(min(2 * x + 1, lx, (lx + rx)/2, l, r), min(2 * x + 2, (lx + rx)/2, rx, l, r));
    }

    ll min(ll l, ll r) {
        return min(0, 0, size, l, r);
    }

    node countMin(ll x, ll lx, ll rx, ll l, ll r) {
        if(lx >= r || rx <= l) return {INT_MAX, 0};
        if(lx >= l && rx <= r) return v[x];

        return merge(countMin(2 * x + 1, lx, (lx + rx)/2, l, r), countMin(2 * x + 2, (lx + rx)/2, rx, l, r));
    }

    node countMin(ll l, ll r) {
        return countMin(0, 0, size, l, r);
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
           node cc = st.countMin(l, r);
           cout << cc.m << ' ' << cc.c << '\n';
       }
   }

   return 0;
}