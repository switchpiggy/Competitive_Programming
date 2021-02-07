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
ll n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    if((n * (n + 1))%4) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    if(n%2) {
        cout << n/2 << '\n';
        cout << n << ' ';
        n--;
        ll i;
        for(i = 1; i <= n/4; ++i) cout << i << ' ' << n - i + 1 << ' ';
        cout << '\n';
        cout << n/2 + 1 << '\n';
        for(; i <= n/2; ++i) cout << i << ' ' << n - i + 1 << ' ';
        cout << '\n';
    } else {
        cout << n/2 << '\n';
        ll i;
        for(i = 1; i <= n/4; ++i) cout << i << ' ' << n - i + 1 << ' ';
        cout << '\n';
        cout << n/2 << '\n';
        for(; i <= n/2; ++i) cout << i << ' ' << n - i + 1 << ' ';
        cout << '\n';
    }
}