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
ll n, a[100007];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    ll cur = 0, ans = 0;
    for(ll i = 0; i < n; ++i) {
        if(i && a[i] <= a[i - 1]) cur++, ans = max(ans, cur);
        else {
            cur = 0;
        }
    }

    cout << ans << '\n';
    return 0;
}