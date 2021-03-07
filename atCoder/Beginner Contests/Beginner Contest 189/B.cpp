#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define benq queue
#define pbenq priority_queue
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
#define flout cout << fixed << setprecision(12)
ll n, x, v[1007], p[1007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    for(ll i = 1; i <= n; ++i) {
        cin >> v[i] >> p[i];
        v[i] *= 100;
    }

    x *= 100;
    ll tot = 0;
    for(ll i = 1; i <= n; ++i) {
        tot += (v[i]/100 * p[i]);
        if(tot > x) {
            cout << i << '\n';
            return 0;
        }
    }

    cout << "-1\n";
    return 0;
}