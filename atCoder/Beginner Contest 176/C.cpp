#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[200007];

int main() {
    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    ll sum = 0;
    for(ll i = 1; i < n; ++i) {
        if(a[i] < a[i - 1]) {
            sum += a[i - 1] - a[i];
            a[i] = a[i - 1];
        }
    }

    cout << sum << endl;
    return 0;
}