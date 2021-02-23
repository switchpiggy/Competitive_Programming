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
ll n, m, t, cnt, dp[1007][1007], x, y, p, dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1}, c[1007][1007], sz[1000007];
vector<string> v;
bool vis[1007][1007];

bool ok(ll x, ll y) {
    return (x < n && x >= 0 && y < m && y >= 0 && !vis[x][y]);
}

void dfs(ll x, ll y) {
    c[x][y] = cnt;
    sz[cnt]++;
    vis[x][y] = 1;

    for(ll i = 0; i < 4; ++i) {
        ll nx = x + dx[i], ny = y + dy[i];
        if(ok(nx, ny) && v[nx][ny] == v[x][y]) dfs(nx, ny);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> n >> m >> t;
    for(ll i = 0; i < n; ++i) {
        string s;
        cin >> s;
        v.push_back(s);
    }

    bool a = 0;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) {
            if(!vis[i][j]) {
                ++cnt;
                dfs(i, j);
                if(sz[cnt] > 1) a = 1;
            }
        }
    }

    m0(vis);
    benq<pair<ll, ll>> ben;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) {
            if(sz[c[i][j]] > 1) {
                dp[i][j] = 0;
                ben.push({i, j});
            }
        }
    }

    while(!ben.empty()) {
        pair<ll, ll> p = ben.front();
        ben.pop();

        for(ll i = 0; i < 4; ++i) {
            ll nx = p.first + dx[i], ny = p.second + dy[i];
            if(ok(nx, ny) && dp[nx][ny] == -1) {
                dp[nx][ny] = dp[p.first][p.second] + 1;
                ben.push({nx, ny});
            }
        }
    }

    /*for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) cout << dp[i][j] << ' ';
        cout << '\n';
    }*/

    while(t--) {
        cin >> x >> y >> p;
        x--;
        y--;
        if(!a) cout << v[x][y] << '\n';
        else cout << ((v[x][y] - '0') + max(0ll, p - dp[x][y]))%2 << '\n';
    }

    return 0;
}