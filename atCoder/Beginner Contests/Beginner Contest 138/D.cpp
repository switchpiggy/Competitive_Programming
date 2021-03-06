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
ll n, q, a, b, cnt[200007];
vector<ll> adj[200007];

void dfs(ll x, ll p) {
    for(ll i : adj[x]) {
        if(i == p) continue;
        cnt[i] += cnt[x];
        dfs(i, x);
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(ll i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    while(q--) {
        cin >> a >> b;
        cnt[a] += b;
    }

    dfs(1, -1);

    for(ll i = 1; i <= n; ++i) cout << cnt[i] << ' ';
    cout << '\n';
    return 0;
}