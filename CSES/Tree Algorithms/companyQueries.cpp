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
#define MAXN 200007
ll lift[MAXN][30], d[MAXN], a, b, n, q;
vector<ll> adj[MAXN];

void lca_init(ll x, ll p = 0) {
    lift[x][0] = p;
    for(ll i = 1; i < 20; ++i) {
        lift[x][i] = lift[lift[x][i - 1]][i - 1];
    }

    for(ll i : adj[x]) {
        if(i == p) continue;
        d[i] = d[x] + 1;
        lca_init(i, x);
    }
}

ll par(ll x, ll k) {
    ll ans = x;
    for(ll i = 19; i >= 0; --i) {
        if(k >= (1 << i)) {
            k -= (1 << i);
            ans = lift[ans][i];
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(ll i = 2; i <= n; ++i) {
        cin >> a;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }

    lca_init(1);

    while(q--) {
        cin >> a >> b;
        if(!par(a, b)) cout << "-1\n";
        else cout << par(a, b) << '\n';
    }

    return 0;
}