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
ll n, m, dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, -1, 1};
ll pre[1007][1007][2];
bool vis[1007][1007];
char g[1007][1007], cp[1007][1007], dc[4] = {'D', 'U', 'L', 'R'};
// benq<pair<ll, ll>> ben;

bool c(ll x, ll y) {
    if(x < 0 || x >= n || y < 0 || y >= m || vis[x][y] || g[x][y] == '#') return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    ll a, b, x, y;
    benq<pair<ll, ll>> ben;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) {
            cin >> g[i][j];
            if(g[i][j] == 'A') {
                ben.push({i, j});
                a = i, b = j;
            }

            if(g[i][j] == 'B') {
                x = i, y = j;
            }
        }
    }

    // benq<pair<ll, ll>> ben;
    while(!ben.empty()) {
        pair<ll, ll> t = ben.front();
        ben.pop();

       for(ll i = 0; i < 4; ++i) {
           if(!c(t.first + dx[i], t.second + dy[i])) continue;
           pre[t.first + dx[i]][t.second + dy[i]][0] = t.first, pre[t.first + dx[i]][t.second + dy[i]][1] = t.second;
           cp[t.first + dx[i]][t.second + dy[i]] = dc[i];
           vis[t.first + dx[i]][t.second + dy[i]] = 1;
           ben.push({t.first + dx[i], t.second + dy[i]});
       }
    }

    if(!vis[x][y]) cout << "NO\n";
    else {
        cout << "YES\n";
        string res;
        while(x != a || y != b) {
            res += cp[x][y];
            pair<ll, ll> nxt = {pre[x][y][0], pre[x][y][1]};
            x = nxt.first;
            y = nxt.second;
        }

        reverse(all(res));
        cout << sz(res) << '\n' << res << '\n';
    }

    return 0;
}