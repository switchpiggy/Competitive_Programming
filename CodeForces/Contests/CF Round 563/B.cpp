#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    bool even = 0, odd = 0;
    for(ll i = 0; i < n; ++i) {
        if(a[i]%2 == 0) even = 1;
        else odd = 1;
    }

    if(!odd || !even) {
        for(ll i = 0; i < n; ++i) cout << a[i] << ' ';
        return 0;
    }

    sort(a, a + n);
    for(ll i = 0; i < n; ++i) cout << a[i] << ' ';
    return 0;
}