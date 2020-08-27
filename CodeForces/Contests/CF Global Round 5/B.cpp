#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[100007], c[100007], b[100007];

int main() {
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        //cout << a[i] << ' ';
    }

    for(ll i = 0; i < n; ++i) {
        ll temp;
        cin >> temp;
        b[temp] = i;
    }

    for(ll i = 0; i < n; ++i) {
        c[i] = b[a[i]];
        //cout << c[i] << ' ';
    }

    ll maxn = 0, ans = 0;
    for(ll i = 0; i < n; ++i) {
        if(c[i] < maxn) ans++;
        maxn = max(c[i], maxn);
    } 

    cout << ans << endl;
    return 0;
}