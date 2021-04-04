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
ll t, n, r[200007], c[200007];
vector<pair<ll, ll>> v;

ll dist(ll x, ll y, ll x2, ll y2) {
    if(x - y == x2 - y2) {
        if((x + y)%2) return 0;
        return x2 - x;
    }

    x2 = x2 - x + 1;
    y2 = y2 - y + 1;

    if((x + y)%2) return (x2 - y2 + 1)/2;
    return (x2 - y2)/2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        v.clear();
        cin >> n;
        for(ll i = 0; i < n; ++i) cin >> r[i];
        for(ll i = 0; i < n; ++i) cin >> c[i];
        for(ll i = 0; i < n; ++i) v.push_back({r[i], c[i]});

        sort(all(v));

        ll ans = 0;
        ans += dist(1, 1, v[0].first, v[0].second);
        for(ll i = 0; i < n - 1; ++i) {
            ans += dist(v[i].first, v[i].second, v[i + 1].first, v[i + 1].second);
        }

        cout << ans << '\n';
    }
    
    return 0;
}