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
ll n, m, a, b, dp[100007];
vector<ll> adj[100007];

void dfs(ll x) {
    if(dp[x] != -1) return;
    dp[x] = 0;
    for(ll i : adj[x]) {
        dfs(i);
        (dp[x] += dp[i]) %= MOD;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
    }

    memset(dp, -1, sizeof(dp));
    dp[n] = 1;
    dfs(1);

    cout << dp[1] << '\n';
}