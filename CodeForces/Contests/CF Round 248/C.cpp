#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define benq queue
#define pbenq priority_queue
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
#define m0(x) memset(x, 0, sizeof(x))
#define m1(x) memset(x, 1, sizeof(x))
#define mn1(x) memset(x, -1, sizeof(x))
#define flout cout << fixed << setprecision(12)
ll n, m, a[100007], sum[100007];
vector<ll> adj[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 1; i <= m; ++i) cin >> a[i];
    for(ll i = 1; i <= m; ++i) {
        if(i > 1 && a[i] != a[i - 1]) adj[a[i]].push_back(a[i - 1]), sum[a[i]] += a[i - 1];
        if(i < m && a[i] != a[i + 1]) adj[a[i]].push_back(a[i + 1]), sum[a[i]] += a[i + 1];
    }

    ll ans = 0;
    for(ll i = 1; i <= n; ++i) {
        if(!sz(adj[i])) continue;
        sort(all(adj[i]));
        //cout << sum[i] << ' ';
        //ll avg = (ll)round((ld)sum[i]/(ld)sz(adj[i])), res = 0;
        ll avg = adj[i][sz(adj[i])/2], res = 0;
        avg = min(avg, n);
        avg = max(avg, 1ll);
        //cout << avg << ' ';
        for(ll j : adj[i]) {
            res += abs(j - avg) - abs(i - j);
        }

        ans = min(ans, res);
    }

    ll cur = 0;
    for(ll i = 2; i <= m; ++i) {
        cur += abs(a[i] - a[i - 1]);
    }

    cout << cur + ans << '\n';
    return 0;
}