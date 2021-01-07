#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[300007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ll w = 0, b = 0, sum = 0;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        if(i%2 == 0) {
            w += (a[i] + 1)/2;
            b += a[i]/2;
        } else {
            b += (a[i] + 1)/2;
            w += a[i]/2;
        }
    }

    cout << (sum - abs(b - w))/2 << '\n';
    return 0;
}