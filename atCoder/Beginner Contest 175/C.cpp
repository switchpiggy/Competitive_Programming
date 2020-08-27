#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll x, k, d;

int main() {
    cin >> x >> k >> d;
    if(abs(x) >= k * d) {
        cout << abs(abs(x) - (k * d)) << endl;
        return 0;
    }

    ll res = (k - (abs(x)/d));
    if(res%2 == 0) cout << abs(x)%d << endl;
    else cout << min(abs(abs(x)%d + d), abs(abs(x)%d - d)) << endl;

    return 0; 
}