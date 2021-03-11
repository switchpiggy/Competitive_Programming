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
ll n, m, a[200007], b[200007], mins[200007];

bool check(ll x, ll q) {
    ll res = 0, cur = q;
    multiset<ll> s;

    for(ll i = 0; i < n; ++i) {
        cur += a[i];
        s.insert(a[i]);
        while(cur < 0) {
            cur -= *s.begin();
            s.erase(s.begin());
            res++;
        }
    }

    return res <= x;
}

vector<ll> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    for(ll i = 0; i < m; ++i) cin >> b[i], v.push_back(b[i]);

    sort(all(v));
    v.push_back(INF);

    for(ll i = 0; i <= n; ++i) {
        ll l = 0, r = m, ans = m;
        while(l < r) {
            ll mid = (l + r)/2;
            if(check(i, v[mid])) {
                ans = mid;
                r = mid;
            } else l = mid + 1;
        }

        mins[i] = ans;
    }

    // for(ll i = 0; i <= n; ++i) cout << mins[i] << ' ';
    // cout << '\n';

    for(ll i = 0; i < m; ++i) {
        ll res = 0;
        ll l = 0, r = n + 1;
        while(l < r) {
            ll mid = (l + r)/2;
            if(v[mins[mid]] <= b[i]) {
                res = mid;
                r = mid;
            } else l = mid + 1;
        }

        cout << res << '\n';
    }

    return 0;
}