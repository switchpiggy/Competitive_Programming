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
ll gcd(ll a, ll b){ return b == 0 ? a : gcd(b,a%b); }
void fileIO() {
    freopen("test.txt", "w", stdout);
    freopen("input-kits-0ad2.txt", "r", stdin);
}
set<ll> factor(ll n) {
    set<ll> ret;
    for (ll i = 1; i * i <= n; i++) {
        if (n%i == 0) {
            ret.insert(i);
            ret.insert(n/i);
        }
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fileIO();
    ll t;
    cin >> t;
    for (ll l = 1; l <= t; l ++) {
        cout << "Case #" << l << ":" << " ";
        ll n;
        cin >> n;
        ll g[n];
        for (ll i = 0; i < n; i ++) {
            cin >> g[i];
        }
        ll fac = g[0];
        for (int i = 1; i < n; i ++) {
            fac = gcd(fac, g[i]);
        }
        // cout << fac << endl << endl;
        set<ll> x = factor(fac);
        cout << x.size() << endl;
        // for (auto i: x) {
        //     cout << i << endl;
        // }
    }
}