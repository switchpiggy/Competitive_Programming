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
ll n, m, k;
vector<pair<ll, ll>> v, c;
bool used[107];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        c.push_back({x, y});
    }

    cin >> k;
    for(ll i = 0; i < k; ++i) {
        ll x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    ll ans = 0;
    for(ll i = 0; i < (1ll << k); ++i) {
        m0(used);
        for(ll j = 0; j < k; ++j) {
            if(i & (1ll << j)) {
                used[v[j].first] = 1;
            } else used[v[j].second] = 1;
        }

        ll res = 0;
        for(ll j = 0; j < m; ++j) {
            if(used[c[j].first] && used[c[j].second]) {
                res++;
            }
        }

        ans = max(ans, res);
    }

    cout << ans << '\n';
    return 0;
}