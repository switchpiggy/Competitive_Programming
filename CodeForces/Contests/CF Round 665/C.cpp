#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, a[100007], b[100007], c[100007];

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        ll mins = INT_MAX;

        for(ll i = 0; i < n; ++i) {
            cin >> a[i];
            mins= min(mins, a[i]);
        }        

        ll k = 0;
        bool ok = 0;
        for(ll i = 0; i < n; ++i) {
            if(a[i]%mins == 0) {
                b[k] = a[i];
                c[k] = i;
                k++;
            }
        }

        sort(b, b + k);

        for(ll i = 0; i < k; ++i) {
            a[c[i]] = b[i];
        }

        for(ll i = 0; i < n - 1; ++i) {
            if(a[i] > a[i + 1]) {
                ok = 1;
                break;
            }
        }

        if(!ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}