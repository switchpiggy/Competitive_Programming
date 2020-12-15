#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[307], t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(ll i = 0; i < n; ++i) cin >> a[i];
        for(ll i = 0; i < n/2; ++i) {
            cout << a[i] << ' ' << a[n - i - 1] << ' ';
        }

        if(n%2 == 1) cout << a[n/2];

        cout << '\n';
    }

    return 0;
}