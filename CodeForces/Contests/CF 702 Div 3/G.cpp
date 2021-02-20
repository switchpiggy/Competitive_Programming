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
ll t, n, m, a[200007], x, pref[200007];

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

        v[x] = max(v[2 * x + 1], v[2 * x + 2]);
    }

    void set(ll p, ll val) {
        set(p, val, 0, 0, size);
    }

    ll find_first(ll val, ll x, ll lx, ll rx) {
        if(rx - lx == 1) return lx;
        if(v[2 * x + 1] >= val) return find_first(val, 2 * x + 1, lx, (lx + rx)/2);

        return find_first(val, 2 * x + 2, (lx + rx)/2, rx);
    }

    ll find_first(ll val) {
        return find_first(val, 0, 0, size);
    }
};

segTree st;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> m;
        st.init(n + 1);
        ll maxn = 0;
        for(ll i = 0; i < n; ++i) cin >> a[i], pref[i] = a[i] + (i ? pref[i - 1] : 0), st.set(i + 1, pref[i]);
        for(ll i = 0; i < n; ++i) {
            if(pref[i] > pref[maxn]) maxn = i;
        }

        while(m--) {
            cin >> x;
            if(pref[0] >= x) {
                cout << "0\n";
                continue;
            }
            
            if(pref[n - 1] <= 0) {
                if(pref[maxn] < x) {
                    cout << "-1 ";
                } else cout << st.find_first(x) - 1 << ' ';
            } else {
                ll l = 0, r = 1e9, ans = 0;
                while(l < r) {
                    ll mid = (l + r)/2;
                    if(mid * pref[n - 1] + pref[maxn] >= x) {
                        ans = mid;
                        r = mid;
                    } else l = mid + 1;
                }

                ll res = st.find_first(x - ans * pref[n - 1]) + ans * n;
                cout << res - 1 << ' ';
            }
        }

        cout << '\n';
    }

    return 0;
}