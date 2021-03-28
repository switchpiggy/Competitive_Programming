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
ll t, r, c, g[307][307], dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
map<ll, vector<pair<ll, ll>>> occ;

bool ok(ll x, ll y) {
    if(x < 0 || x >= r || y < 0 || y >= c) return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    // benq<pair<ll, ll>> ben;
    for(ll tc = 1; tc <= t; ++tc) {
        cin >> r >> c;
        occ.clear();
        for(ll i = 0; i < r; ++i) {
            for(ll j = 0; j < c; ++j) cin >> g[i][j], occ[g[i][j]].push_back({i, j});
        }
        
        ll ans = 0;
        for(auto itr = occ.rbegin(); itr != occ.rend(); ++itr) {
            auto it = *itr;
            ll i = it.first;
            // cout << i << ' ';
                for(pair<ll, ll> rc : it.second) {
                    ll j = rc.first, k = rc.second;
                    if(g[j][k] != i) continue;
                        for(ll l = 0; l < 4; ++l) {
                            if(!ok(j + dx[l], k + dy[l])) continue;
                            if(g[j + dx[l]][k + dy[l]] < i - 1) {
                                ans += i - 1 - g[j + dx[l]][k + dy[l]];
                                g[j + dx[l]][k + dy[l]] = i - 1;
                                occ[i - 1].push_back({j + dx[l], k + dy[l]});
                            }
                        }
                }
        }

        cout << "Case #" << tc << ": ";
        cout << ans << '\n';
    }

    return 0;
}