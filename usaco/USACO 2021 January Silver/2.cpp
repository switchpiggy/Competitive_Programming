#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define benq queue
#define pbenq priority_queue
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
#define m1(x) memset(x, 1, sizeof(x))
#define m0(x) memset(x, 0, sizeof(x))
#define inf(x) memset(x, 0x3f, sizeof(x))
#define flout cout << fixed << setprecision(12)
ll n, q, x, y, cum[100007], suf[100007], last[100007];
string s;

struct segTree {
    ll size;
    vector<ll> v;

    void init(ll x) {
        size = 1;
        while(size <= x) size *= 2;
        v.assign(size * 2, 0);
    }

    void set(ll p, ll val, ll x, ll lx, ll rx) {
        if(rx - lx == 1) {
            v[x] = val;
            return;
        }

        if(p < (lx + rx)/2) set(p, val, 2 * x + 1, lx, (lx + rx)/2);
        else set(p, val, 2 * x + 2, (lx + rx)/2, rx);

        v[x] = min(v[2 * x + 1], v[2 * x + 2]);
    }

    void set(ll p, ll val) {
        set(p, val, 0, 0, size);
    }

    ll range_min(ll l, ll r, ll x, ll lx, ll rx) {
        if(l <= lx && rx <= r) return v[x];
        if(r <= lx || rx <= l) return 27;
        return min(range_min(l, r, 2 * x + 1, lx, (lx + rx)/2), range_min(l, r, 2 * x + 2, (lx + rx)/2, rx));
    }

    ll range_min(ll l, ll r) {
        return range_min(l, r, 0, 0, size);
    }
};

segTree st;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(last, -1, sizeof(last));
    cin >> n >> q >> s;
    st.init(n + 1);

    //cum[0] = 1;
    for(ll i = 0; i < n; ++i) {
        st.set(i, s[i] - 'A');
        if(last[s[i] - 'A'] == -1) {
            last[s[i] - 'A'] = i;
            cum[i]++;
            if(i) cum[i] += cum[i - 1];
            continue;
        }
        //last[s[i]] = i;
        ll mins = st.range_min(last[s[i] - 'A'], i + 1);
        if(char(mins + 'A') < s[i]) cum[i]++;
        if(i) cum[i] += cum[i - 1];
        last[s[i] - 'A'] = i;
    }

    memset(last, -1, sizeof(last));
    st.init(n + 1);
    //suf[n - 1] = 1;
    for(ll i = n - 1; i >= 0; --i) {
        st.set(i, s[i] - 'A');
        if(last[s[i] - 'A'] == -1) {
            last[s[i] - 'A'] = i;
            suf[i]++;
            if(i < n - 1) suf[i] += suf[i + 1];
            continue;
        }

        ll mins = st.range_min(i, last[s[i] - 'A'] + 1);
        if(char(mins + 'A') < s[i]) suf[i]++;
        if(i < n - 1) suf[i] += suf[i + 1];
        last[s[i] - 'A'] = i;
    }

    while(q--) {
        cin >> x >> y;
        x--;
        y--;
        cout << suf[y + 1] + (x ? cum[x - 1] : 0) << '\n';
    }

    //cout << suf[4] << '\n';
    return 0;
}