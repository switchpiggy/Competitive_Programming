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
#define flout cout << fixed << setprecision(12)
ll n, a[1007][1007], in[1007][1007], v[1007][1007];
vector<pair<ll, ll>> adj[1007][1007];

void dfs(ll x, ll y) {
    v[x][y] = 1;
    for(pair<ll, ll> i : adj[x][y]) {
        if(v[i.first][i.second] == 1) {
            cout << "-1\n";
            exit(0);
        }

        if(!v[i.first][i.second]) dfs(i.first, i.second);
    }

    v[x][y] = 2;
    return;
    }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 1; i <= n; ++i) {
        for(ll j = 0; j < n - 1; ++j) {
            cin >> a[i][j];
            if(j) {
                ll x = min(i, a[i][j]), y = i + a[i][j] - x;
                adj[min(i, a[i][j - 1])][max(i, a[i][j - 1])].push_back({x, y});
                in[x][y]++;
            }
        }
    }

    for(ll i = 1; i <= n; ++i) {
        for(ll j = i + 1; j <= n; ++j) {
            if(!v[i][j]) dfs(i, j);
        }
    }

    m0(v);
    ll ans = 0;
    benq<pair<ll, ll>> ben;

    for(ll i = 1; i <= n; ++i) {
        for(ll j = i + 1; j <= n; ++j) {
            if(!in[i][j]) {
                //cout << i << ' ' << j << '\n';
                v[i][j] = 1;
                ben.push({i, j});
            }
        }
    }

    //ll ans = 0;
    while(!ben.empty()) {
        pair<ll, ll> f = ben.front();
        ben.pop();

        for(pair<ll, ll> i : adj[f.first][f.second]) {
            in[i.first][i.second]--;
            if(!in[i.first][i.second]) ben.push({i.first, i.second});
            v[i.first][i.second] = v[f.first][f.second] + 1;
            
            ans = max(ans, v[i.first][i.second]);
        }
    }

    //cout << v[2][3] << '\n';

    cout << ans << '\n';
    return 0;
}