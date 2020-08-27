#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, k;

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> k;
        if(n%2 == k%2 && n >= 2 + k) cout << '0' << endl;
        else if(n == k) cout << '0' << endl;
        else if(n >= 2 + k) cout << '1' << endl;
        else {
            ll cur = abs((2 + k) - n);
            if(n%2 != k%2) cur++;

            cout << min(cur, abs(n - k)) << endl;
        }
    }

    return 0;
}