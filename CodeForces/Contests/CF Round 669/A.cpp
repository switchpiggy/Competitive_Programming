#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, a[1007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(ll i = 0; i < n; ++i) cin >> a[i];

        ll zero = 0, one = 0;
        for(ll i = 0; i < n; ++i) {
            if(a[i] == 0) zero++;
            else one++;
        }

        if(one <= n/2) {
            cout << n - one << '\n';
            for(ll i = 0; i < one; ++i) cout << 1 << ' ';
            if(one) cout << '\n';
        } else {
            if(one%2 == 1) {
                cout << n - (zero + 1) << '\n';
                cout << 1 << ' ';
                for(ll i = 0; i < zero; ++i) cout << 0 << ' ';
                cout << '\n';
            } else {
                cout << n - zero << '\n';
                for(ll i = 0; i < zero; ++i) cout << 0 << ' ';
                if(zero) cout << '\n';
            }   
        }
    }

    return 0;
}