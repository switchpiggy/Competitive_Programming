#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, c[100007], sz[100007];
vector<ll> adj[100007];
bool v[100007];
ll a, b;

ll sz_dfs(ll x) {
    ll cur = 1;
    v[x] = 1;
    for(ll i : adj[x]) {
        if(!v[i]) cur += sz_dfs(i);
    }

    return cur;
}

bool dfs(ll x, ll col) {
    v[x] = 1;
    if(col == 1) a++;
    else b++;
    c[x] = col;

    for(ll i : adj[x]) {
        //if(v[i]) continue;
        if(c[i] == c[x]) return 0;
        if(v[i]) continue;
        if(!dfs(i, 3 - col)) return 0;
    }

    return 1;
}

int main() {
    cin >> n >> m;
    for(ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if(!m) {
        cout << 3 << ' ' << (n * (n - 1) * (n - 2))/6 << '\n';
        return 0;
    }

    bool ok = 0;
    for(ll i = 1; i <= n; ++i) {
        if(!v[i]) {
            if(sz_dfs(i) > 2) {
                ok = 1;
                break;
            } 


        }
    }

    if(!ok) {
        cout << 2 << ' ' << m * (n - 2) << '\n';
        return 0;
    }

    memset(v, 0, sizeof(v));
    ll ans = 0;
    for(ll i = 1; i <= n; ++i) {
        if(v[i]) continue;
        a = b = 0;
        if(!dfs(i, 1)) {
            cout << 0 << ' ' << 1 << '\n';
            return 0;
        }

        ans += (a * (a - 1))/2 + (b * (b - 1))/2;
    }

    cout << 1 << ' ' << ans << '\n';
    return 0;
}