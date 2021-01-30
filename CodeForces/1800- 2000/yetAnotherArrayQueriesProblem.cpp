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
ll n, q, m, a[200007], t, l, r;
vector<pair<ll, pair<ll, ll>>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q >> m;
    for(ll i = 1; i <= n; ++i) cin >> a[i];
    for(ll i = 0; i < q; ++i) {
        cin >> t >> l >> r;
        v.push_back({t, {l, r}});
    }

    reverse(all(v));

    for(ll i = 0; i < m; ++i) {
        ll b;
        cin >> b;
        for(pair<ll, pair<ll, ll>> p : v) {
            if(b < p.second.first || b > p.second.second) continue;
            if(p.first == 2) {
                b = p.second.first + (p.second.second - b);
            } else {
                b--;
                if(b < p.second.first) b = p.second.second;
            }
        }

        cout << a[b] << ' ';
    }

    return 0;
}