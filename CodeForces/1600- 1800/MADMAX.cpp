#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define benq queue
#define pbenq priority_queue
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()

ll n, m;
vector<pair<ll, char>> adj[107];
ll dp[107][107][27];

void dfs(ll x, ll y, ll c) {
    if(dp[x][y][c] != -1) return;
    for(pair<ll, char> i : adj[x]) {
        if(i.second - 'a' >= c) {
            dfs(y, i.first, i.second - 'a');
            if(dp[y][i.first][i.second - 'a'] == 0) dp[x][y][c] = 1;
        }
    }

    /*for(pair<ll, char> i : adj[y]) {
        if(i.second - 'a' >= c) {
            dfs(x, i.first, i.second - 'a');
            if(dp[x][i.first][i.second] == 0) dp[x][y][c] = 0;
        }
    }*/

    if(dp[x][y][c] == -1) dp[x][y][c] = 0;
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    for(ll i = 0; i < m; ++i) {
        ll a, b;
        char c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    for(ll i = 1; i <= n; ++i, cout << '\n') {
        for(ll j = 1; j <= n; ++j) {
            if(dp[i][j][0] == -1) dfs(i, j, 0);
            cout << (dp[i][j][0] == 1 ? 'A' : 'B');
        }
    }

    return 0;
}