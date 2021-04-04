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
ll n, a[5007];

ll solve(ll x, ll y) {
    if(x > y) return 0;
    if(x == y) return (a[x] > 0);

    ll mins = INF, ind = x;
    for(ll i = x; i <= y; ++i) {
        if(a[i] < mins) {
            mins = a[i];
            ind = i;
        }
    }

    for(ll i = x; i <= y; ++i) a[i] -= mins;

    return min(y - x + 1, solve(x, ind - 1) + solve(ind + 1, y) + mins);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    cout << solve(0, n - 1) << '\n';

    return 0;
}