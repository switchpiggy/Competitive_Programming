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
#define MOD 998244353
#define INF 0x3f3f3f3f3f3f3f3f
#define PI 3.14159265358979323846264338
#define flout cout << fixed << setprecision(12)
ll n, f[200007], vis[200007], cnt;

ll dfs(ll x) {
    if(vis[x] == cnt) return 1;
    else if(vis[x] && vis[x] < cnt) return 0;
    vis[x] = cnt;
    return dfs(f[x]);
}

ll fastpow(ll x, ll y) {
    if(!y) return 1;
    ll rec = fastpow(x, y/2);
    if(y%2) return ((rec * rec)%MOD * x)%MOD;
    return (rec * rec)%MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> f[i], f[i]--;

    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        if(!vis[i]) {
            // cout << i << ' ';
            ++cnt;
            ans += dfs(i);
        }
    }

    // cout << ans << '\n' << vis[0] << '\n';
    cout << (fastpow(2, ans) - 1 + MOD)%MOD << '\n';
    return 0;
}