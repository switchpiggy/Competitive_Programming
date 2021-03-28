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
ll n, q, t[200007], x, k, lift[200007][30];

ll nxt(ll x, ll k) {
    ll res = x;
    for(ll i = 29; i >= 0; --i) {
        if((1 << i) <= k) {
            res = lift[res][i];
            k -= (1 << i);
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(ll i = 1; i <= n; ++i) cin >> t[i], lift[i][0] = t[i];

    for(ll i = 1; i < 30; ++i) {
        for(ll j = 1; j <= n; ++j) lift[j][i] = lift[lift[j][i - 1]][i - 1];
    }

    while(q--) {
        cin >> x >> k;
        cout << nxt(x, k) << '\n';
    }

    return 0;
}