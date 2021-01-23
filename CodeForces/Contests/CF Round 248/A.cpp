#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define benq queue
#define pbenq priority_queue
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
#define m0(x) memset(x, 0, sizeof(x))
#define m1(x) memset(x, 1, sizeof(x))
#define mn1(x) memset(x, -1, sizeof(x))
#define flout cout << fixed << setprecision(12)
ll n, w[107];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ll a = 0, b = 0;
    for(ll i = 1; i <= n; ++i) {
        cin >> w[i];
        if(w[i] == 100) a++;
        else b++;
    }

    if(a%2 == 0 && b%2 == 0) cout << "YES\n";
    else if(b%2 == 1 && a >= 2 && a%2 == 0) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}