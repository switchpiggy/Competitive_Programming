#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a, b;

int main() {
    cin >> a >> b;
    ll gcf = __gcd(a, b);

    ll ans = 0;
    ll aa = a/gcf, bb = b/gcf;
    //cout << aa << ' ' << bb << endl;
    while(aa%2 == 0) {
        ans++;
        aa /= 2;
    }
    while(aa%3 == 0) {
        ans++;
        aa /= 3;
    }
    while(aa%5 == 0) {
        ans++;
        aa /= 5;
    }

    while(bb%2 == 0) {
        ans++;
        bb /= 2;
    }

    while(bb%3 == 0) {
        ans++;
        bb /= 3;
    }

    while(bb%5 == 0) {
        ans++;
        bb /= 5;
    }

    if(aa == 1 && bb == 1) {
        cout << ans << endl;
        return 0;
    }

    cout << "-1" << endl;
    return 0;
}