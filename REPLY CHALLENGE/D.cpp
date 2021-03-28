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

void fileIO() {
    freopen("ttt.txt", "w", stdout);
    freopen("in.txt", "r", stdin);
}

ll n, k, a[100007], cur, pos[100007], gr[100007], ans[100007];
bool v[100007];
vector<vector<ll>> g;

void dfs(ll x) {
    v[x] = 1;
    pos[x] = sz(g[cur]);
    gr[x] = cur;
    g[cur].push_back(x);

    if(!v[a[x]]) {
        dfs(a[x]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fileIO();
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cur = 0;
        m0(v);
        m0(pos);
        m0(gr);
        g.clear();
        // cout << "Case #" << tc << ":" << " ";
        cin >> n >> k;
        for(ll i = 0; i < n; ++i) {
            cin >> a[i];
        }

        for(ll i = 0; i < n; ++i) {
            if(!v[i]) {
                g.push_back(vector<ll>());
                dfs(i);
                cur++;
            }
        }
        
        cout << "Case #" << tc << ":" << " ";
        for(ll i = 0; i < n; ++i) ans[g[gr[i]][(pos[i] + k)%(sz(g[gr[i]]))]] = i;
        for(ll i = 0; i < n; ++i) cout << ans[i] << ' ';
        cout << '\n';
    }

    return 0;
}