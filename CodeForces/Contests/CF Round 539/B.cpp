#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[50007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    ll sum = 0;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    sort(a, a + n);
    ll mins = a[0], res = sum;

    for(ll i = 1; i < n; ++i) {
        for(ll j = 2; j * j <= a[i]; ++j) {
            if(a[i]%j == 0) {
                res = min(res, sum - a[i] + a[i]/j - mins + mins * j);
            }

            if(a[i]%(a[i]/j) == 0) {
                res = min(res, sum - a[i] + a[i]/j - mins + mins * j);
            }
        }        
    }

    cout << res << '\n';
    return 0;
}