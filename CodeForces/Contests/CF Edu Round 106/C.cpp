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
ll t, n, c[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(ll i = 1; i <= n; ++i) cin >> c[i];

        ll odd = c[1], even = c[2], ans = n * c[1] + n * c[2], odds = c[1], evens = c[2];
        for(ll i = 3; i <= n; ++i) {
            if(i%2 == 0) even = min(even, c[i]), evens += c[i];
            else odd = min(odd, c[i]), odds += c[i];
            ans = min(ans, evens + (n - i/2) * even + odds + (n - (i + 1)/2) * odd);
        }

        cout << ans << '\n';
    }

    return 0;
}