#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define benqueue queue
#define pbenqueue priority_queue
ll n, a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> a >> b;
    if(a * b >= 6 * n) {
        cout << a * b << '\n' << a << ' ' << b << '\n';
        return 0;
    }

    bool ok = 0;
    if(a > b) {
        swap(a, b);
        ok = 1;
    }

    ll x = INT_MAX, y = INT_MAX;
    for(ll i = a; i * i <= 6 * n; ++i) {
        ll cur = i * ((6 * n + i - 1)/i);
        if(((6 * n + i - 1)/i) >= b && x * y - 6 * n > cur - 6 * n) {
            x = i;
            y = ((6 * n + i - 1)/i);
        }
    }

    if(ok) swap(x, y);

    cout << x * y << '\n' << x << ' ' << y << '\n';
    return 0;
}