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
ll n, a, b, ans, dp[200007][2];
vector<ll> adj[200007];

void dfs(ll x, ll p = -1) {
    if(sz(adj[x]) == 1 && p != -1) return;

    ll mins = INF;
    for(ll i : adj[x]) {
        if(p == i) continue;
        dfs(i, x);
        dp[x][0] += max(dp[i][0], dp[i][1]);
        mins = min(mins, dp[i][1] - dp[i][0]);
    }

    dp[x][1] = dp[x][0] + 1;
    if(mins > 0) dp[x][1] -= mins;   
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);

    cout << max(dp[1][1], dp[1][0]) << '\n';
    return 0;
}