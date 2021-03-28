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
ll n, m, dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
char g[1007][1007];
bool vis[1007][1007];

bool c(ll x, ll y) {
    if(x < 0 || x >= n || y < 0 || y >= m || vis[x][y] || g[x][y] == '#') return 0;
    return 1;
}

void dfs(ll x, ll y) {
    vis[x][y] = 1;
    for(ll i = 0; i < 4; ++i) {
        if(!c(x + dx[i], y + dy[i])) continue;
        dfs(x + dx[i], y + dy[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) cin >> g[i][j];
    }

    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) {
            if(!vis[i][j] && g[i][j] == '.') {
                dfs(i, j);
                ans++;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}