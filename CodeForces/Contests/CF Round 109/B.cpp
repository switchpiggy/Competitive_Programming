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
#define flout cout << fixed << setprecision(12)
ll n;
vector<ll> z, pos;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ll sum = 0;
    for(ll i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        if(b == 0) z.push_back(a);
        else {
            pos.push_back(a);
            sum += b;
        }
    }

    sort(all(z), greater<ll>());
    ll ans = accumulate(all(pos), 0);

    for(ll i = 0; i < sum - sz(pos) + 1 && i < sz(z); ++i) ans += z[i];

    cout << ans << '\n';
    return 0;
}