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
ll a, b, c, d, n, px[100007], py[100007];
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> c >> d >> n >> s;
    ll nx = 0, ny = 0;
    for(ll i = 0; i < n; ++i) {
        if(s[i] == 'U') ny++;
        else if(s[i] == 'D') ny--;
        else if(s[i] == 'L') nx--;
        else nx++;

        px[i + 1] = nx, py[i + 1] = ny;
    }

    ll l = 1, r = 1e18, ans = LLONG_MAX;
    while(l < r) {
        ll mid = (l + r)/2, cx = a + px[mid%n] + px[n] * (mid/n), cy = b + py[mid%n] + py[n] * (mid/n);
        if(abs(cx - c) + abs(cy - d) <= mid) {
            ans = mid;
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    if(ans == LLONG_MAX) ans = -1;
    cout << ans << '\n';
    return 0;
}