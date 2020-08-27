#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int n, a[2007];

int main() {
    cin >> n;
    bool ok = 0;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        if(i > 0 && a[i] <= a[i - 1]) {
            ok = 1;
        }
    }

    if(!ok) {
        cout << 0 << endl;
        return 0;
    }

    cout << n + 1 << endl;

    ll cnt = 0, sum = 0;
    for(ll i = n - 1; i >= 0; --i) {
        ll cur = (i - (a[i] + sum)%n + n)%n;
        cout << 1 << ' ' << i + 1 << ' ' << cur << endl;
        sum += cur;
    }

    cout << 2 << ' ' << n << ' ' << n << endl;
    return 0;
}