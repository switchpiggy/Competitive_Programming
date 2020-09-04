#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, x, y;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> x >> y;
        if(n == 2) {
            cout << x << ' ' << y << endl;
            continue;
        }

        ll diff = y - x;
        for(ll i = y - x; i >= 2; --i) {
            if((y - x)%i == 0 && i < n) {
                diff = i;
                break;
            }
        }

        ll cur = 0;
        for(ll i = x; i <= y && cur < n; i += (y - x)/diff) {
            cout << i << ' ';
            cur++;
        }

        ll num = x - (y - x)/diff;
        while(cur < n && num > 0) {
            cur++;
            cout << num << ' ';
            num -= (y - x)/diff;
        }

        if(cur < n) {
            num = y + (y - x)/diff;
            while(cur < n) {
                cout << num << ' ';
                num += (y - x)/diff;
                cur++;
            }
        }

        cout << endl;
    }

    return 0;
}