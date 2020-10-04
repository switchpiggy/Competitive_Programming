#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, p, k, x, a[400007], n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> x >> p >> k;
        p--;
        k--;
        for(ll i = 0; i < n; ++i) cin >> a[i];

        ll less = 0;
        for(ll i = 0; i < n; ++i) if(a[i] <= x) less++;

        sort(a, a + n);

        //less--;

        //if k < p and less < p + 1 -> ans = no
        //if less > p + 1 and k > p -> ans = no;

        if((k < p && less < p + 1) || (less > p + 1 && k > p) || (less == p + 1 && k != p)) {
            cout << "-1\n";
            continue;
        } 
    }

    return 0;
}