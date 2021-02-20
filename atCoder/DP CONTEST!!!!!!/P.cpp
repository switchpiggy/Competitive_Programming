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
ll n, dp[100007][2];
vector<ll> adj[100007];

void dfs(ll x, ll p) {
    dp[x][0] = dp[x][1] = 1;
    for(ll i : adj[x]) {
        if(i == p) continue;
        dfs(i, x);
        (dp[x][1] *= dp[i][0]) %= MOD;
        (dp[x][0] *= (dp[i][1] + dp[i][0])%MOD) %= MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n - 1; ++i) {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, -1);
    cout << (dp[1][0] + dp[1][1])%MOD << '\n';
    return 0;
}
