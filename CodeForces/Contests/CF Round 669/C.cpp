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
ll n, a[10007], b[10007], res[10007];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    auto ask = [](ll x, ll y) {
        cout << "? " << x << ' ' << y << '\n';
        cout.flush();
        ll cur;
        cin >> cur;
        return cur;
    };

    ll m = 1;
    for(ll i = 2; i <= n; ++i) {
        ll x = ask(i, m);
        ll y = ask(m, i);

        if(y > x) {
            res[m] = y;
            m = i;
        } else {
            res[i] = x;
        }
    }

    res[m] = n;
    cout << "! ";
    for(ll i = 1; i <= n; ++i) cout << res[i] << ' ';
    cout << '\n';
    return 0;
}