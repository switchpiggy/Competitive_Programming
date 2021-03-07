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
ll n, a[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    vector<ll> v;
    for(ll i = 0; i < n; ++i) if(i%2 == 0) v.push_back(a[i]);
    for(ll i = 0; i < n; ++i) if(i%2 == 1) v.push_back(a[i]);
    for(ll i = 0; i < n; ++i) v.push_back(v[i]);

    // for(ll i : v) cout << i << ' ';

    ll ans = 0;
    for(ll i = 0; i < (n + 1)/2; ++i) ans += v[i];

    ll cur = ans;
    for(ll i = 1; i + (n + 1)/2 - 1 < sz(v); ++i) {
        cur -= v[i - 1];
        cur += v[i + (n + 1)/2 - 1];
        ans = max(ans, cur);
    }

    cout << ans << '\n';
    return 0;
}