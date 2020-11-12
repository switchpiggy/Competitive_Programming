#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, r, b, k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> r >> b >> k;
        ll g = __gcd(r, b);
        r /= g, b /= g;
        if(r > b) swap(r, b);
        if((k - 1) * r + 1 >= b) cout << "OBEY\n";
        else cout << "REBEL\n"; 
    }

    return 0;
}