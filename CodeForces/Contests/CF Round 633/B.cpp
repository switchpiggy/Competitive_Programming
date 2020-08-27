#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, a[100007];

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        for(ll i = 0; i < n; ++i) cin >> a[i];

        sort(a, a + n);

        if(n%2 == 1) cout << a[n/2] << ' ';
        for(ll i = n/2 - 1; i >= 0; --i) {
            cout << a[i] << ' ' << a[n - i - 1] <<  ' ';
        }
        cout << endl;
    }

    return 0;
}