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
ll n, cnt[2000007], p[2000007], x;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> x;
        cnt[x] = x;
    }

    for(ll i = 1; i <= 2000000; ++i) {
        p[i] = max(cnt[i], p[i - 1]);
    }

    ll ans = 0;
    for(ll i = 1; i <= 1000000; ++i) {
        if(!cnt[i]) continue;
        for(ll j = 2 * i; j <= 2000000; j += i) ans = max(ans, p[j - 1]%i);
    }

    cout << ans << '\n';
    return 0;
}