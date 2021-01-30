#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define benq queue
#define pbenq priority_queue
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
#define flout cout << fixed << setprecision(12)
ll n, k, a[100007], p[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    for(ll i = 0; i < 256; ++i) p[i] = -1;

    for(ll i = 0; i < n; ++i) {
        if(p[a[i]] != -1) continue;
        for(ll j = max(0ll, a[i] - k + 1); j <= a[i]; ++j) {
            if(p[j] == -1 || a[i] - p[j] < k) {
                for(ll l = j; l <= a[i]; ++l) p[l] = j;
                break;
            }
        }
    }

    for(ll i = 0; i < n; ++i) cout << p[a[i]] << ' ';

    return 0;
}