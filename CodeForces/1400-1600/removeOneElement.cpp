#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[200007], l[200007], r[200007];

int main() {
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        l[i] = r[i] = 1;
    }

    ll cnt = 1;
    for(ll i = 1; i < n; ++i) {
        r[i - 1] = cnt;
        if(a[i] <= a[i - 1]) {
            cnt = 1;
        } else cnt++;
    }

    r[n - 1] = cnt;

    cnt = 1;
    for(ll i = n - 2; i >= 0; --i) {
        l[i + 1] = cnt;
        if(a[i] >= a[i + 1]) {
            cnt = 1;
        } else cnt++;
    }

    l[0] = cnt;

    //for(ll i = 0; i < n; ++i) cout << l[i] << ' ' << r[i] << endl;

    ll maxn = 0;
    for(ll i = 0; i < n; ++i) maxn = max(maxn, l[i]);

    for(ll i = 1; i < n - 1; ++i) {
        if(a[i - 1] < a[i + 1]) maxn = max(maxn, r[i - 1] + l[i + 1]);
    }

    cout << maxn << endl;
    return 0;
}