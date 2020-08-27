#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        ll ans = 0;
        for(ll i = 2; i <= sqrt(n); ++i) {
            if(n%i == 0) ans = max(ans, i);
            while(n%i == 0) n /= i;
        }

        cout << max(ans, n) << endl;
    }

    return 0;
}