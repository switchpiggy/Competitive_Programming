#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll y, x, a, b, c;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> x >> y;
    a = y, b = y, c = y;

    ll cnt = 0;
    while(!(a == b && b == c && c == x)) {
        ll d = min(a, min(b, c));
        if(a == d) {
            a = min(x, b + c - 1);
        } else if(b == d) {
            b = min(x, a + c - 1);
        } else {
            c = min(x, b + a - 1);
        }

        //cout << a << ' ' << b << ' ' << c << '\n';
        cnt++;
    }

    cout << cnt << '\n';
    return 0;
}