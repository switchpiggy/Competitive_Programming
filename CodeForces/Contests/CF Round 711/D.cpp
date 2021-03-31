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
ll n, m, t, x, y;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    vector<ll> ans(m + 1, INF);
    vector<bool> vis(m + 1, 0);
    vis[0] = 1;
    ans[0] = 0;

    for(ll i = 0; i < n; ++i) {
        cin >> t >> x >> y;

        auto nvis = vis;

        auto op = [&] (ll &cur) {
            if(t == 1) cur = (100000 * cur + x + 100000 - 1)/100000;
            else cur = (cur * x + 100000 - 1)/100000;
        };

        for(ll j = 0; j <= m; ++j) {
            if(!vis[j]) continue;
            ll cur = j;

            for(ll k = 0; k < y; ++k) {
                op(cur);
                if(cur > m || vis[cur]) break;
                ans[cur] = i + 1;
                nvis[cur] = 1;
            }
        }

        vis = nvis;
    }

    for(ll i = 1; i <= m; ++i) cout << (ans[i] == INF ? -1 : ans[i]) << ' ';
    cout << '\n';
    return 0;
}
