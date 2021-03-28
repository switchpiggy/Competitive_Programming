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
#define mn(x) memset(x, -1, sizeof(x))
#define inf(x) memset(x, 0x3f, sizeof(x))
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define PI 3.14159265358979323846264338
#define flout cout << fixed << setprecision(12)
ll n, m, dist[1007][1007], dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};
pair<ll, ll> pre[1007][1007];
ll t[1007][1007];
char g[1007][1007], dc[4] = {'R', 'L', 'U', 'D'}, cpre[1007][1007];
bool vis[1007][1007];
benq<pair<ll, ll>> ben;

bool ok(ll x, ll y) {
    if(x < 0 || x >= n || y < 0 || y >= m || g[x][y] == '#' || vis[x][y]) return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    inf(dist);
    mn(t);
    ll a, b;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) {
            cin >> g[i][j];
            if(g[i][j] == 'M') ben.push({i, j}), dist[i][j] = 0;
            if((!i || i == n - 1 || j == m - 1 || !j) && g[i][j] == '.') {
                g[i][j] = '*';
            }

            if(g[i][j] == 'A') {
                a = i, b = j;
            }
        }
    }

    if(!a || !b || a == n - 1 || b == m - 1) {
        cout << "YES\n0\n";
        return 0;
    }
    
    while(!ben.empty()) {
        pair<ll, ll> f = ben.front();
        ben.pop();

        for(ll i = 0; i < 4; ++i) {
            if(!ok(f.first + dx[i], f.second + dy[i]) || dist[f.first + dx[i]][f.second + dy[i]] != INF) continue;
           dist[f.first + dx[i]][f.second + dy[i]] = dist[f.first][f.second] + 1;
           ben.push({f.first + dx[i], f.second + dy[i]});
        } 
    }

    ben.push({a, b});
    t[a][b] = 0;
    vis[a][b] = 1;
    while(!ben.empty()) {
        pair<ll, ll> f = ben.front();
        ben.pop();
        if(g[f.first][f.second] == '*') {
            cout << "YES\n";
            string s;
            ll x = f.first, y = f.second;
            while(x != a || y != b) {
                s += cpre[x][y];
                pair<ll, ll> nxt = pre[x][y];
                x = nxt.first;
                y = nxt.second;
            }

            reverse(all(s));
            cout << sz(s) << '\n' << s << '\n';
            return 0;
        }

        for(ll i = 0; i < 4; ++i) {
            if(!ok(f.first + dx[i], f.second + dy[i])) continue;
            t[f.first + dx[i]][f.second + dy[i]] = t[f.first][f.second] + 1;
            vis[f.first + dx[i]][f.second + dy[i]] = 1;
            if(t[f.first + dx[i]][f.second + dy[i]] >= dist[f.first + dx[i]][f.second + dy[i]]) continue;
            cpre[f.first + dx[i]][f.second + dy[i]] = dc[i];
            pre[f.first + dx[i]][f.second + dy[i]] = f;
            // vis[f.first + dx[i]][f.second + dy[i]] = 1;
            ben.push({f.first + dx[i], f.second + dy[i]});
        }
    }

    cout << "NO\n";
    return 0;
}