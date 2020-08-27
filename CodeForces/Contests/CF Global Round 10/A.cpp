#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, a[200007];

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        for(ll i = 0; i < n; ++i) cin >> a[i];
        sort(a, a + n);
        if(a[0] == a[n - 1]) cout << n << endl;
        else cout << '1' << endl;
    }

    return 0;
}