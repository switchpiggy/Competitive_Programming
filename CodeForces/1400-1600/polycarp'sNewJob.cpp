#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, x, y;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    ll a = 0, b = 0;
    for(ll i = 0; i < n; ++i) {
        char c;
        cin >> c;

        if(c == '?') {
            cin >> x >> y;
            if((x >= a && y >= b) || (x >= b && y >= a)) {
                cout << "YES\n";
            } else cout << "NO\n";
        } else {
            cin >> x >> y;
            a = max(a, min(x, y));
            b = max(b, max(x, y)); 
        }
    }

    return 0;
}