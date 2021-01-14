#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define benqueue queue
#define pbenqueue priority_queue
ll t, n, m, pref[200007][2];
string s;

struct segTreeMax {
    vector<ll> v;
    ll size;
    void init(ll x) {
        v.clear();
        size = 1;
        while(size <= x) size *= 2;
        v.assign(size * 2, LLONG_MIN);
    }

    void set(ll val, ll pos, ll x, ll lx, ll rx) {
        if(rx - lx == 1) {
            v[x] = val;
            return;
        }

        if(pos >= (lx + rx)/2) set(val, pos, 2 * x + 2, (lx + rx)/2, rx);
        else set(val, pos, 2 * x + 1, lx, (lx + rx)/2);

        v[x] = max(v[2 * x + 1], v[2 * x + 2]);
    }

    void set(ll val, ll pos) {
        set(val, pos, 0, 0, size);
    }

    ll get_max(ll l, ll r, ll x, ll lx, ll rx) {
        if(l <= lx && rx <= r) return v[x];
        if(lx >= r || rx <= l) return LLONG_MIN;
        return max(get_max(l, r, 2 * x + 1, lx, (lx + rx)/2), get_max(l, r, 2 * x + 2, (lx + rx)/2, rx));
    }

    ll get_max(ll l, ll r) {
        //if(l > n) return 0;
        return get_max(l, r, 0, 0, size);
    }
};

struct segTreeMin {
    vector<ll> v;
    ll size;
    void init(ll x) {
        v.clear();
        size = 1;
        while(size <= x) size *= 2;
        v.assign(size * 2, LLONG_MAX);
    }

    void set(ll val, ll pos, ll x, ll lx, ll rx) {
        if(rx - lx == 1) {
            v[x] = val;
            return;
        }

        if(pos >= (lx + rx)/2) set(val, pos, 2 * x + 2, (lx + rx)/2, rx);
        else set(val, pos, 2 * x + 1, lx, (lx + rx)/2);

        v[x] = min(v[2 * x + 1], v[2 * x + 2]);
    }

    void set(ll val, ll pos) {
        set(val, pos, 0, 0, size);
    }

    ll get_min(ll l, ll r, ll x, ll lx, ll rx) {
        if(l <= lx && rx <= r) return v[x];
        if(lx >= r || rx <= l) return LLONG_MAX;
        return min(get_min(l, r, 2 * x + 1, lx, (lx + rx)/2), get_min(l, r, 2 * x + 2, (lx + rx)/2, rx));
    }

    ll get_min(ll l, ll r) {
        //if(l > n) return 0;
        return get_min(l, r, 0, 0, size);
    }
};

segTreeMax stmax;
segTreeMin stmin;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> m >> s;
        stmax.init(n + 1);
        stmin.init(n + 1);
        for(ll i = 1; i <= n; ++i) {
            pref[i][0] = pref[i][1] = 0;
        }

        for(ll i = 1; i <= n; ++i) {
            if(s[i - 1] == '-') pref[i][0]++;
            else pref[i][1]++;
        }

        for(ll i = 1; i <= n; ++i) {
            pref[i][1] += pref[i - 1][1];
            pref[i][0] += pref[i - 1][0];
        }

        ll cur = 0;
        stmax.set(0, 0);
        stmin.set(0, 0);
        for(ll i = 1; i <= n; ++i) {
            if(s[i - 1] == '-') cur--;
            else cur++;
            stmax.set(cur, i);
            stmin.set(cur, i);
        }

        //stmax.set(cur, n + 1);
        //stmin.set(cur, n + 1);

        while(m--) {
            ll l, r;
            cin >> l >> r;
            ll net = (pref[r][1] - pref[l - 1][1]) - (pref[r][0] - pref[l - 1][0]);
            ll curMax = max(stmax.get_max(0, l), (r == n ? 0 : stmax.get_max(r + 1, n + 1) - net)), curMin = min(stmin.get_min(0, l), (r == n ? 0 : stmin.get_min(r + 1, n + 1) - net));
            cout << curMax - curMin + 1 << '\n';
        }
    }

    return 0;
}