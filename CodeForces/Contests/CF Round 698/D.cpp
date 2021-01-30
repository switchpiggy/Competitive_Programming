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
ll t, n, k,  x[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> k;
        for(ll i = 0; i < n; ++i) cin >> x[i];

        k -= x[0];
        for(ll i = 1; i < n; ++i) x[i] -= x[0];
        x[0] = 0;

        ll g = abs(x[1]);
        for(ll i = 2; i < n; ++i) g = __gcd(g, abs(x[i]));

        if(abs(k)%abs(g) == 0) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}