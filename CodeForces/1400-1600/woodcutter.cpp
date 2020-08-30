#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, x[100007], h[100007]; 

int main() {
    cin >> n;
    ll ans = 1;

    for(ll i = 0; i < n; ++i) {
        cin >> x[i] >> h[i];
    }

    for(ll i = 1; i < n; ++i) {
        if(x[i] - h[i] > x[i - 1]) ans++;
        else {
            if(i == n - 1 || x[i] + h[i] < x[i + 1]) {
                ans++;
                x[i] += h[i];
            }
        }
    }

    cout << ans << endl;
    return 0;
}