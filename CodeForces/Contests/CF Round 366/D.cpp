#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define benq queue
#define pbenq priority_queue
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
#define m0(x) memset(x, 0, sizeof(x))
#define m1(x) memset(x, 1, sizeof(x))
#define mn1(x) memset(x, -1, sizeof(x))
#define minf(x) memset(x, 0x3f, sizeof(x))
#define flout cout << fixed << setprecision(12)
ll n, s, e, x[5007], a[5007], b[5007], c[5007], d[5007], dp[5007][2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s >> e;
    for(ll i = 1; i <= n; ++i) cin >> x[i];
    for(ll i = 1; i <= n; ++i) cin >> a[i];
    for(ll i = 1; i <= n; ++i) cin >> b[i];
    for(ll i = 1; i <= n; ++i) cin >> c[i];
    for(ll i = 1; i <= n; ++i) cin >> d[i];

    pbenq<pair<ll, pair<ll, bool>>> ben;
    minf(dp);
    //cout << dp[0][0] << '\n';
    dp[s][1] = 0;
    ben.push({0, {s, 1}});

    while(!ben.empty()) {
        pair<ll, pair<ll, bool>> p = ben.top();
        ben.pop();
        ll dist = -p.first, x = p.second.first, siz = p.second.second;
        cout << dist << '\n';
        if(dp[x][siz] < dist) continue;

        for(ll i = 1; i <= n; ++i) {
            if(i == x) continue;
            ll adj = abs(i - x) + (i < x ? c[x] + b[i] : d[x] + a[i]);
            //cout << adj << '\n';

            if(dp[x][siz] + adj < dp[x][(i > x)]) {
                cout << x << ' ' << (i > x) << '\n';
                dp[x][(i > x)] = dp[x][siz] + adj;
                ben.push({-dp[x][(i > x)], {x, (i > x)}});
            }
        }
    }

    cout << dp[e][0] << ' ' << dp[e][1] << '\n';
    cout << min(dp[e][0], dp[e][1]) << '\n';
    return 0;
}