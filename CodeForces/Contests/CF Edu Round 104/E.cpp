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
ll n1, n2, n3, n4;
pair<ll, ll> a[200007], b[200007], c[200007], d[200007];
set<ll> x[200007], y[200007], z[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n1 >> n2 >> n3 >> n4;
    for(ll i = 1; i <= n1; ++i) cin >> a[i].first, a[i].second = i;
    for(ll i = 1; i <= n2; ++i) cin >> b[i].first, b[i].second = i;
    for(ll i = 1; i <= n3; ++i) cin >> c[i].first, c[i].second = i;
    for(ll i = 1; i <= n4; ++i) cin >> d[i].first, d[i].second = i;

    sort(a + 1, a + n1 + 1);
    sort(b + 1, b + n2 + 1);
    sort(c + 1, c + n3 + 1);
    sort(d + 1, d + n4 + 1);

    auto no = []() {
        cout << "-1\n";
        exit(0);
    };

    ll m;
    cin >> m;
    for(ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        x[v].insert(u);
    }

    cin >> m;
    for(ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        y[u].insert(v);
    }

    cin >> m;
    for(ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        z[u].insert(v);
    }

    for(ll i = 1; i <= n2; ++i) {
        ll res = -1;
        for(ll j = 1; j <= n1; ++j) {
            if(x[b[i].second].find(a[j].second) == x[b[i].second].end()) {
                res = j;
                break;
            }
        }

        if(res == -1) {
            b[i].first = -1;
            continue;
        }

        b[i].first += a[res].first;
    }

    for(ll i = 1; i <= n3; ++i) {
        ll res = -1;
        for(ll j = 1; j <= n4; ++j) {
            if(z[c[i].second].find(d[j].second) == z[c[i].second].end()) {
                res = j;
                break;
            }
        }

        if(res == -1) {
            c[i].first = -1;
            continue;
        }

        c[i].first += d[res].first;
    }

    vector<pair<ll, ll>> cc;
    for(ll i = 1; i <= n3; ++i) if(c[i].first != -1) cc.push_back(c[i]);
    sort(all(cc));

    ll ans = LLONG_MAX;
    for(ll i = 1; i <= n2; ++i) {
        if(b[i].first == -1) continue;
        for(ll j = 0; j < sz(cc); ++j) {
            if(y[b[i].second].find(cc[j].second) == y[b[i].second].end()) {
                ans = min(ans, cc[j].first + b[i].first);
                break;
            }
        }
    }

    if(ans == LLONG_MAX) ans = -1;
    cout << ans << '\n';
    return 0;
}