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
ll n, m, p[300007], cnt[300007];
vector<ll> adj[300007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 1; i <= n; ++i) cin >> p[i];

    for(ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        adj[b].push_back(a);
    }

    ll ans = 0;
    for(ll i : adj[p[n]]) {
        cnt[i]++;
    }
    
    for(ll i = n - 1; i >= 1; --i) {
        if(cnt[p[i]] == n - i - ans) {
            ans++;
            continue;
        }

        for(ll j : adj[p[i]]) {
            cnt[j]++;
        }
    }

    cout << ans << '\n';
    return 0;
}