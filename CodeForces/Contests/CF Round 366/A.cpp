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

void solve(ll x, bool c) {
    if(x == 1) {
        if(c) cout << "I love it\n";
        else cout << "I hate it\n";
        return;
    }

    if(c) cout << "I love that ";
    else cout << "I hate that ";
    solve(x - 1, 1 - c);
}

ll n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    solve(n, 0);
    return 0;
}