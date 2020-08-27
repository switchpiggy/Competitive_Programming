#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, a[200007];

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        for(ll i = 0; i < n; ++i) cin >> a[i];
        
        ll cur = 0, ans = 1;
        for(ll i = 0; i < n; ++i) {
            if(a[i] == i + 1) {
                if(cur == 1) {
                    cur = 2;
                }
            } else {
                if(!cur) {
                    cur = 1;
                } else if(cur == 2) {
                    ans = 2;
                    break;
                }
            }
        }

        if(!cur) ans = 0;
        cout << ans << endl;
    }

    return 0;
}