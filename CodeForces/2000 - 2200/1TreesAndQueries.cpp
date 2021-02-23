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
ll n, u, v, q, x, y, a, b, k, p[100007][22], d[100007];
vector<ll> adj[100007];

void dfs(ll x, ll par) {
    d[x] = d[par] + 1;
    p[x][0] = par;

    for(ll i = 1; i <= 20; ++i) {
        p[x][i] = p[p[x][i - 1]][i - 1];
    }

    for(ll i : adj[x]) {
        if(i != par) dfs(i, x);
    }
}

ll dist(ll a, ll b) {
    if(d[a] > d[b]) swap(a, b);
    ll res = 0;
    for(ll i = 20; i >= 0; --i) {
        if(d[p[b][i]] >= d[a]) {
            b = p[b][i];
            res += (1 << i);
        }
    }

    if(a == b) return res;

    for(ll i = 20; i >= 0; --i) {
        if(p[b][i] != p[a][i]) {
            b = p[b][i];
            a = p[a][i];
            res += (1 << (i + 1));
        }
    }

    return res + 2;
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

    dfs(1, 0);

    cin >> q;
    while(q--) {
        cin >> x >> y >> a >> b >> k;
        ll ans = dist(a, b), ans2 = (dist(a, x) + dist(y, b)) + 1, ans3 = (dist(a, y) + dist(x, b)) + 1;
        //cout << ans << ' ' << ans2 << ' ' << ans3 << '\n';
        ll f = INF;
        if(ans%2 == k%2) f = min(f, ans);
        if(ans2%2 == k%2) f = min(f, ans2);
        if(ans3%2 == k%2) f = min(f, ans3);

        if(f <= k) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}