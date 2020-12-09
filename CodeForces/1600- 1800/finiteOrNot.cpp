#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
//hopefully getting a CP girlfriend soon
ll n, p, q, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;   
    while(n--) {
        cin >> p >> q >> b;
        q /= __gcd(p, q);
        b = __gcd(q, b);
        while(b != 1) {
            while(q%b == 0) q /= b;
            b = __gcd(q, b);
        }

        if(q == 1) cout << "Finite\n";
        else cout << "Infinite\n";
    }

    return 0;
}