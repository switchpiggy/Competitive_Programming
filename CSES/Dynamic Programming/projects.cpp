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
ll n, nxt[200007], dp[200007];
vector<pair<pair<ll ,ll>, ll>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) {
        ll a, b, p;
        cin >> a >> b >> p;
        v.push_back({{a, b}, p});
    }

    sort(all(v));

    //nxt[0] = 1;
    for(ll i = 0; i < n; ++i) {
        ll k = lower_bound(all(v), make_pair(make_pair(v[i].first.second + 1ll, -1ll), -1ll)) - v.begin();
        nxt[i] = k;
    }

    for(ll i = 0; i < n; ++i) {
        dp[i + 1] = max(dp[i + 1], dp[i]);
        dp[nxt[i]] = max(dp[nxt[i]], dp[i] + v[i].second);
    }

    cout << dp[n] << '\n';
    return 0;
}