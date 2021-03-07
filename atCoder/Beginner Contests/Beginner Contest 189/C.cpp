#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define benq queue
#define pbenq priority_queue
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
#define flout cout << fixed << setprecision(12)
ll n, a[10007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        ll mins = a[i];
        for(ll j = i; j < n; ++j) {
            mins = min(mins, a[j]);
            ans = max(ans, (j - i + 1) * mins);
        }
    }

    cout << ans << '\n';
    return 0;
}