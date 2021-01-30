#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define benq queue
#define pbenq priority_queue
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
#define flout cout << fixed << setprecision(12)
ll t, n, l, r;
vector<pair<ll, ll>> v;
vector<ll> a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        a.clear();
        b.clear();
        v.clear();
        cin >> n;
        for(ll i = 0; i < n; ++i) {
            cin >> l >> r;
            a.push_back(l);
            b.push_back(r);
            v.push_back({l, r});
        }

        sort(all(a));
        sort(all(b));

        ll ans = LLONG_MAX;
        for(ll i = 0; i < n; ++i) {
            ll bef = lower_bound(all(b), v[i].first) - b.begin();
            ll aft = upper_bound(all(a), v[i].second) - a.begin();
            ans = min(ans, bef + (sz(v) - aft));
        }

        cout << ans << '\n';
    }

    return 0;
}