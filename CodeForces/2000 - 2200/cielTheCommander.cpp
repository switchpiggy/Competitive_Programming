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
#define MAXN 100007
ll par[MAXN], sz[MAXN], n, a, b;
char ans[MAXN];
bool v[MAXN];
vector<ll> adj[MAXN];

void sz_init(ll x, ll p = -1) {
    if(v[x]) {
        sz[x] = 0;
        return;
    }

    sz[x] = 1;
    for(ll i : adj[x]) {
        if(i == p) continue;
        sz_init(i, x);
        sz[x] += sz[i];
    }

    return;
}

ll find_centroid(ll x, ll p, ll tot) {
    for(ll i : adj[x]) {
        if(i != p && !v[i] && sz[i] > tot/2) {
            return find_centroid(i, x, tot);
        }
    }

    return x;
}

void cd_init(ll x, ll p, char cur) {
    sz_init(x);
    
    ll cent = find_centroid(x, -1, sz[x]);
    v[cent] = 1;
    par[cent] = p;
    ans[cent] = cur;

    for(ll i : adj[cent]) {
        if(!v[i]) {
            cd_init(i, cent, cur + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cd_init(1, -1, 'A');

    for(ll i = 1; i <= n; ++i) cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}