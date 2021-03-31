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
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define PI 3.14159265358979323846264338
#define flout cout << fixed << setprecision(12)
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
            v[x] += val;
            return;
        }

        if(p < (lx + rx)/2) set(p, val, 2 * x + 1, lx, (lx + rx)/2);
        else set(p, val, 2 * x + 2, (lx + rx)/2, rx);

        v[x] = max(v[2 * x + 1], v[2 * x + 2]);
    }

    void set(ll p, ll val) {
        set(p, val, 0, 0, size);
    }

    ll first_larger(ll q, ll x, ll lx, ll rx) {
        if(rx - lx == 1) return lx;
        if(v[2 * x + 1] >= q) return first_larger(q, 2 * x + 1, lx, (lx + rx)/2);
        return first_larger(q, 2 * x + 2, (lx + rx)/2, rx);
    }

    ll first_larger(ll q) {
        return first_larger(q, 0, 0, size);
    }
};

ll n, m, h[200007], r;
segTree st;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    st.init(n + 1);
    for(ll i = 0; i < n; ++i) cin >> h[i], st.set(i, h[i]);
    st.set(n, INF);

    while(m--) {
        cin >> r;
        ll cur = st.first_larger(r);

        if(cur == n) cout << "0 ";
        else {
            cout << cur + 1 << ' ';
            st.set(cur, -r);
        }
    }

    return 0;
}