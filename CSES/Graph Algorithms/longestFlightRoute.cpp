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
ll n, m, a, b, dp[100007], nxt[100007];
vector<ll> adj[100007];

void dfs(ll x) {
    if(x == n) {
        dp[x] = 0;
        return;
    } else dp[x] = -INF;

    for(ll i : adj[x]) {
        if(dp[i] == -1) dfs(i);
        if(dp[i] == -INF) continue;
        if(dp[i] + 1 > dp[x]) {
            nxt[x] = i;
            dp[x] = dp[i] + 1;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    for(ll i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
    }

    dfs(1);

    if(dp[1] == -INF) cout << "IMPOSSIBLE\n";
    else {
        cout << dp[1] + 1 << '\n';
        ll x = 1;
        cout << "1 ";
        while(x != n) {
            x = nxt[x];
            cout << x << ' ';
        }

        cout << '\n';
    }

    return 0;
}