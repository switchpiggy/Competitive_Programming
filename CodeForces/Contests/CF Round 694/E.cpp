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
ll t, n, m, c[300007];
vector<ll> adj[300007];

void dfs(ll x) {
    if(c[x] == 1) {
        for(ll i : adj[x]) {
            if(!c[i]) dfs(i);
        }
    } else {
        vector<ll> v;
        c[x] = 2;
        for(ll i : adj[x]) {
            if(!c[i]) {
                c[i] = 1;
                v.push_back(i);
            }
        }

        for(ll i : v) {
            dfs(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(ll i = 1; i <= n; ++i) adj[i].clear(), c[i] = 0;
        for(ll i = 1; i <= m; ++i) {
            ll x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        dfs(1);
        bool ok = 1;
        vector<ll> ans;
        for(ll i = 1; i <= n; ++i) {
            if(!c[i]) {
                ok = 0;
                break;
            } else if(c[i] == 2) ans.push_back(i);
        }

        if(!ok) cout << "NO\n";
        else {
            cout << "YES\n" << sz(ans) << '\n';
            for(ll i : ans) cout << i << ' ';
            cout << '\n';
        }
    }

    return 0;
}