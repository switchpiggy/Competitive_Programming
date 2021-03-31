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
ll n, k, a[100007], pc[100007], cost[100007];
pbenq<pair<ll, ll>> ben;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(ll i = 0; i < n; ++i) cin >> a[i], ben.push({a[i] * a[i] - (a[i]/2) * (a[i]/2) - ((a[i] + 1)/2) * ((a[i] + 1)/2), i}), pc[i] = 1, cost[i] = a[i] * a[i];
    
    ll cur = n;
    while(cur < k) {
        auto t = ben.top();
        ben.pop();
        ll i = t.second, nc = 0;
        pc[i]++;
        cur++;
        cost[i] -= t.first;

        ben.push({cost[i] - ((a[i]/(pc[i] + 1)) * (a[i]/(pc[i] + 1)) * (pc[i] + 1 - (a[i]%(pc[i] + 1))) + (a[i]/(pc[i] + 1) + 1) * (a[i]/(pc[i] + 1) + 1) * (a[i]%(pc[i] + 1))), i});
    }

    ll ans = 0;
    for(ll i = 0; i < n; ++i) ans += cost[i];

    cout << ans << '\n';
    return 0;
}