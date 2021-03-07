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
ll n, fib[40], sz[200007];
set<ll> adj[200007];
bool f[200007];

void precalc(ll x, ll p) {
    sz[x] = 1;
    for(ll i : adj[x]) {
        if(i == p) continue;
        precalc(i, x);
        sz[x] += sz[i];
    }
}

pair<ll, ll> dfs(ll x, ll p, ll s) {
    if(sz[x] == s) return {x, p};

    for(ll i : adj[x]) {
        if(i == p) continue;
        pair<ll, ll> cur = dfs(i, x, s);
        if(cur.first != -1) return cur;
    }

    return {-1, -1};
}

void cut(ll x, ll y) {
    // cout << x << ' ' << y << '\n';
    adj[x].erase(y);
    adj[y].erase(x);

    return;
}

bool solve(ll x) {
    //cout << "Current recursion: " << x << ' ' << sz[x] << '\n';
    precalc(x, 0);
    if(!f[sz[x]]) return 0;
    if(sz[x] == 1 || sz[x] == 2) return 1;

    ll cur;
    for(ll i = 1; i <= 32; ++i) if(fib[i] <= 200000 && fib[i] == sz[x]) {
        cur = fib[i - 1];
        break;
    }

    pair<ll, ll> res = dfs(x, 0, cur), res1 = dfs(x, 0, sz[x] - cur);
    if(res.first == -1 && res1.first == -1) return 0;
    if(res.first != -1) {
        cut(res.first, res.second);
        return solve(x) & solve(res.first);
    } else {
        cut(res1.first, res1.second);
        return solve(x) & solve(res1.first);
    }
    
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    fib[0] = fib[1] = 1;
    f[1] = 1;
    for(ll i = 2; i <= 32; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
        if(fib[i] <= 200000) f[fib[i]] = 1;
    }

    for(ll i = 0; i < n - 1; ++i) {
        ll x, y;
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
    }

    precalc(1, 0);

    if(!f[n]) {
        cout << "No\n";
        return 0;
    }

    cout << (solve(1) ? "Yes\n" : "No\n");
    return 0;
}