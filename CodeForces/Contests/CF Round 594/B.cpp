#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[100007];

int main() {
    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);

    ll h = 0, l = 0;
    for(ll i = 0; i < n/2; ++i) h += a[i];
    for(ll i = n/2; i < n; ++i) l+= a[i];

    cout << h * h + l * l << endl;
    return 0;
}