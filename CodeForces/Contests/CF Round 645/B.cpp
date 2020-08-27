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

        ll res = 1, cur = n;
        for(ll i = n - 1; i >= 0; --i) {
            if(a[i] > cur) cur--;
            else res++; 
        }

        cout << res << endl;
    }

    return 0;
}