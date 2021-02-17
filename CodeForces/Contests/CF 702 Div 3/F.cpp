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
ll t, n, a[200007];
vector<pair<ll, ll>> v;
map<ll, ll> occ;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        occ.clear();
        v.clear();
        cin >> n;

        for(ll i = 0; i < n; ++i) cin >> a[i], occ[a[i]]++;
        for(auto i = occ.begin(); i != occ.end(); ++i) {
            v.push_back({i->second, 0ll});
        }

        sort(all(v));
        v[0].second = v[0].first;
        for(ll i = 1; i < sz(v); ++i) v[i].second = v[i - 1].second + v[i].first;
        //for(pair<ll, ll> i : v) cout << i.first << ' ' << i.second << '\n';

        ll ans = LLONG_MAX;
        for(ll i = 1; i <= n; ++i) {
            ll k = lower_bound(all(v), make_pair(i, -1ll)) - v.begin();
            k--;
            ll res = 0;
            if(k >= 0) res += v[k].second;
            res += v[sz(v) - 1].second - (k >= 0 ? v[k].second : 0) - (sz(v) - k - 1) * i;
            //cout << v[sz(v) - 1].second - (k >= 0 ? v[k].second : 0) - (sz(v) - k - 1) * i << '\n';
            ans = min(ans, res);
            //cout << i << ' ' << res << '\n';
        }

        cout << ans << '\n';
    }

    return 0;
}