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
#define INF 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793238
#define MOD 1000000007 
#define flout cout << fixed << setprecision(12)
ll n, a[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    ll ans = 0;
    for(ll i = 0; i <= 30; ++i) {
        ll cur = 0;
        for(ll j = 0; j < n; ++j) {
            cur += (a[j] > i ? -INF : a[j]);
            if(cur < 0) cur = 0;
            ans = max(ans, cur - i);
        }
    }
    
    cout << ans << '\n';
    return 0;
}