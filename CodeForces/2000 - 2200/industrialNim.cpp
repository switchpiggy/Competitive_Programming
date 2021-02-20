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
ll n, x, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    ll ans = 0;

    auto f = [](ll x) {
        if(x%4 == 0) return x;
        else if(x%4 == 1) return 1ll;
        else if(x%4 == 2) return x + 1ll;
        return 0ll;
    };

    while(n--) {
        cin >> x >> m;
        ans ^= f(x + m - 1) ^ f(x - 1);
    }

    cout << (ans == 0 ? "bolik\n" : "tolik\n");
    return 0;
}