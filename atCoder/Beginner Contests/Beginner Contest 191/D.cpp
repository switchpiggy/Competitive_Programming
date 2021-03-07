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
ld x, y, r;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> x >> y >> r;
    ll a = llround(x * 10000), b = llround(y * 10000), n = llround(r * 10000);

    ll lx = b - 1, rx = b + 1, mins = a - n;
    while(lx%10000) lx--;
    while(rx%10000) rx++;
    while(mins%10000) mins++;

    ll ans = 0;
    for(ll i = mins; i <= a + n; i += 10000) {
        ll cur = (i - a) * (i - a);
        while(rx >= b && cur + (rx - b) * (rx - b) > n * n) rx -= 10000;
        while(rx <= b || cur + (rx - b) * (rx - b) <=  n * n) rx += 10000;

        while(lx <= b && cur + (lx - b) * (lx - b) > n * n) lx += 10000;
        while(lx >= b || cur + (lx - b) * (lx - b) <= n * n) lx -= 10000; 

        ll add = (rx - lx)/10000 - 1;
        if(add > 0) ans += add;
    }

    if(!ans) exit(-1);
    cout << ans << '\n';
    return 0;
}