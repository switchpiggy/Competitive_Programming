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

struct node {
    ll seg, pref, suff, sum;
};
 
struct segTree {
    ll size;
    vector<node> v;
 
    void init(ll x) {
        ll cur = 1;
        while(cur <= x) cur *= 2;
        size = cur;
        v.assign(2 * size, {0, 0, 0, 0});
    }
 
    void set(ll i, ll x, ll val, ll lx, ll rx) {
        if(rx - lx == 1) {
            v[x].sum = val;
            v[x].seg = max(0ll, val);
            v[x].suff = max(0ll, val);
            v[x].pref = max(0ll, val);
            return;
        }
 
        if(i < (rx + lx)/2) set(i, 2 * x + 1, val, lx, (lx + rx)/2);
        else set(i, 2 * x + 2, val, (lx + rx)/2, rx);
 
        v[x].sum = v[2 * x + 2].sum + v[2 * x + 1].sum;
        v[x].seg = max(v[2 * x + 1].seg, max(v[2 * x + 2].seg, v[2 * x + 1].suff + v[2 * x + 2].pref));
        v[x].suff = max(v[2 * x + 2].sum + v[2 * x + 1].suff, v[2 * x + 2].suff);
        v[x].pref = max(v[2 * x + 1].sum + v[2 * x + 2].pref, v[2 * x + 1].pref);
 
        return;        
    }
 
    void set(ll x, ll val) {
        set(x, 0, val, 0, size);
    }
 
    ll maxSegment() {
        return v[0].seg;
    }
};
 
ll n, m, a, l, r;
segTree st;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n >> m;
    st.init(n);
    for(ll i = 0; i < n; ++i) {
        cin >> a;
        st.set(i, a);
    }
 
    // cout << st.maxSegment() << '\n';
    for(ll i = 0; i < m; ++i) { 
        cin >> l >> r;
        st.set(l - 1, r);
        cout << st.maxSegment() << '\n';
    }
 
    return 0;   
}