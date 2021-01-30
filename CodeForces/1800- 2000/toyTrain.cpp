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
ll n, m, minDist[5007], cnt[5007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    inf(minDist);
    for(ll i = 1; i <= m; ++i) {
        ll a, b;
        cin >> a >> b;
        cnt[a]++;
        if(b < a) minDist[a] = min(minDist[a], (b + n) - a);
        else minDist[a] = min(minDist[a], b - a);
    }

    for(ll i = 1; i <= n; ++i) {
        ll ans = 0;
        for(ll j = 1; j <= n; ++j) {
            //if(i == j) continue;
            ll d = (j < i ? (j + n) - i : j - i);
            if(minDist[j] > n) {
                //ans = max(ans, d);
                continue;
            }
            //ll d = (j < i ? (j + n) - i : j - i);
            ans = max(ans, d + n * (cnt[j] - 1) + minDist[j]);
        }

        cout << ans << ' ';
    }

    return 0;
}