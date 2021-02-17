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
#define mins(x) memset(x, -0x3f, sizeof(x));
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define PI 3.14159265358979323846264338
#define flout cout << fixed << setprecision(12)
ll n, m, dp[100007], in[100007];
vector<ll> adj[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    mins(dp);
    cin >> n >> m;
    for(ll i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        in[y]++;
    }

    benq<ll> ben;
    for(ll i = 1; i <= n; ++i) {
        if(!in[i]) ben.push(i), dp[i] = 0;
    }

    while(!ben.empty()) {
        ll f = ben.front();
        ben.pop();

        for(ll i : adj[f]) {
            dp[i] = max(dp[i], dp[f] + 1);
            in[i]--;
            if(!in[i]) ben.push(i);
        }        
    }

    ll ans = 0;
    for(ll i = 1; i <= n; ++i) ans = max(ans, dp[i]);

    cout << ans << '\n';
    return 0;
}