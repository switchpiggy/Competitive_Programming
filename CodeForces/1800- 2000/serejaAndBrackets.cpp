#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, l, r;
string s;

struct node {
    ll a, b, c;
};

struct segTree {
    ll size;
    vector<node> v;
    
    void init(ll x) {
        size = 1;
        while(size <= x) size *= 2;
        v.assign(size * 2, {0, 0, 0});
    }

    node merge(node x, node y) {
        ll mins = min(x.b, y.c);
        return {x.a + y.a + mins, x.b + y.b - mins, x.c + y.c - mins};
    }

    void set(ll i, char c, ll x, ll lx, ll rx) {
        if(rx - lx == 1) {
            if(c == '(') {
                v[x].b = 1;
            } else v[x].c = 1;
            return;
        }

        if(i < (lx + rx)/2) set(i, c, 2 * x + 1, lx, (lx + rx)/2);
        else set(i, c, 2 * x + 2, (lx + rx)/2, rx);

        v[x] = merge(v[2 * x + 1], v[2 * x + 2]);
    }

    void set(ll i, char c) {
        set(i, c, 0, 0, size);
    }

    node get(ll l, ll r, ll x, ll lx, ll rx) {
        if(rx <= l || r <= lx) return {0, 0, 0};
        if(l <= lx && rx <= r) return v[x];
        return merge(get(l, r, 2 * x + 1, lx, (lx + rx)/2), get(l, r, 2 * x + 2, (lx + rx)/2, rx));
    }

    node get(ll l, ll r) {
        return get(l, r, 0, 0, size);
    }
};

segTree st;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s >> m;
    st.init((ll)s.length());
    for(ll i = 0; i < (ll)s.length(); ++i) st.set(i, s[i]);
    while(m--) {
        cin >> l >> r;
        l--;
        r--;
        cout << st.get(l, r + 1).a * 2 << '\n';
    }

    return 0;
}