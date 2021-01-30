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
ll n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    if(n%2 == 1) {
        cout << "1 ";
        for(ll i = 2; i <= n; i += 2) cout << i + 1 << ' ' << i << ' ';
    } else {
        for(ll i = 1; i <= n; i += 2) cout << i + 1 << ' ' << i << ' ';
    }

    cout << '\n';
    return 0;
}